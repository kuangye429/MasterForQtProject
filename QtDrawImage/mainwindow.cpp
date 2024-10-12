#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 用于在显示器上显示图片
    pix = QPixmap(800,600);
    pix.fill(Qt::transparent);
    tempPix = pix;
    isDrawing = false;
    drawType = DrawType::NULLDRAW;
    m_pTimer = new QTimer(this);
    m_nClickCnt = 0;
    m_bLongPress = false;
    connect(m_pTimer, &QTimer::timeout, [=]{
        m_nClickCnt = 0;
        m_pTimer->stop();
        qDebug() << "键盘单击";
    });
    // 给lineedit安装事件过滤器
    // ui->lineEdit->installEventFilter(this);
    connect(ui->btnPicture, &QPushButton::clicked, this, &MainWindow::DrawPicture);
    connect(ui->btnTest, &QPushButton::clicked, this, &MainWindow::DrawText);
    connect(ui->btnRound, &QPushButton::clicked, this, &MainWindow::DrawRound);
    connect(ui->btnEllipse, &QPushButton::clicked, this, &MainWindow::DrawEllipse);
    connect(ui->btnRect, &QPushButton::clicked, this, &MainWindow::DrawRect);
    connect(ui->btnLine, &QPushButton::clicked, this, &MainWindow::DrawLine);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::DrawText);

    // 初始化菜单
    popMenu = new QMenu(this);
    popMenu->setStyleSheet(QStringLiteral("background-color: rgb(99, 99, 99);"));
    action1 = new QAction(this);
    action1->setText(("最小化"));
    action2 = new QAction(this);
    action2->setText(("最大化"));
    action3 = new QAction(this);
    action3->setText(("退出"));
    connect(action1, &QAction::triggered, this, &MainWindow::showMinimized);
    connect(action2, &QAction::triggered, this, &MainWindow::showMaximized);
    connect(action3, SIGNAL(triggered(bool)),this, SLOT(close()));//关联退出的Action
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // button()返回鼠标按下的按键是那个
    if (event->button() == Qt::LeftButton){
        // 相对于窗口的坐标
        startPoint = event->pos();
        qDebug()<<QString("相对于屏幕的坐标:")<<event->globalPos();
        isDrawing = true;
        pix.fill(Qt::transparent);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // event->buttons()返回按键状态
    if (event->buttons() & Qt::LeftButton)
    {
        endPoint = event->pos();
        tempPix = pix;
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();
        isDrawing = false;
        update();
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        qDebug() << "右键双击";
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    update();
    int x = startPoint.x();
    int y = startPoint.y();
    int width = endPoint.x() - x;
    int height = endPoint.y() - y;
    QPainter painter;
    // 开始往Pixmap绘图设备上绘图
    painter.begin(&tempPix);
    // 设置画笔颜色、宽度，风格
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter.setRenderHint(QPainter::Antialiasing);  // 抗锯齿
    if (drawType == DrawType::RECT) {
        // 填充颜色
        painter.setBrush(Qt::blue);
        painter.drawRect(x,y,width,height);
    } else if (drawType == DrawType::LINE) {
        painter.drawLine(startPoint, endPoint);
    } else if (drawType == DrawType::ELLIPSE) {
        // 填充颜色
        painter.setBrush(Qt::red);
        painter.drawEllipse(QPoint(startPoint.x(), startPoint.y()),
                            (endPoint.x() - startPoint.x()), (endPoint.y() - startPoint.y()));
    } else if (drawType == DrawType::ROUND) {
        // 填充颜色,设置画刷
        painter.setBrush(Qt::yellow);
        painter.drawEllipse(QPoint(startPoint.x(), startPoint.y()), width, width);
    } else if (drawType == DrawType::TEXT) {
        if (!ui->lineEdit->text().isEmpty())
        {
            QFont font("华文行楷",12);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(QRect(100, 200, 600, 150), ui->lineEdit->text());
        }
    } else if (drawType == DrawType::PICTURE) {
        // 以（100，100）画图，图片尺寸变为：100*120
        painter.drawPixmap(100, 100, 100, 120, QPixmap("C:/Users/Administrator/Desktop/1.jpg"));

    }
    // 结束绘图
    painter.end();
    // 在当前mainwindow中绘图
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    if (!isDrawing){
        pix = tempPix;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // 通过event->key()函数获取单个按键
    switch(event->key())
    {
    case Qt::Key_Escape:
        qDebug() << "ESC";
        break;
    default:
        break;
    }
    // 两键组合
    if (event->modifiers() == Qt::ControlModifier)
    {
        if (event->key() == Qt::Key_M){
            qDebug() << "CTRL + M";
        }
    }

    // 三键组合Shift + Ctrl + A的实现
    if (event->modifiers() == (Qt::ShiftModifier | Qt::ControlModifier) && event->key() == Qt::Key_A) {
        qDebug() << "CTRL + Shift + A";
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A) { // Qt::Key_Control经实测，长按永远不会使isAutoRepeat()为true
        // 是否是长按可以从release中直接判断
        if (!event->isAutoRepeat()) {
            // LongPress_初始值为false，如果非长按执行单击或双击动作判断
            // 如果长按会在长按里将其置true，在最后的Relese(非长按)里就不会执行单击、双击判断的动作
            if (!m_bLongPress) {
                if (!m_pTimer->isActive()) {
                    m_pTimer->start(500);
                }
                m_nClickCnt++;
                if (m_nClickCnt == 2){
                    m_nClickCnt = 0; // 计数清零
                    m_pTimer->stop(); // 停止计时
                    qDebug() << "键盘双击";
                }
            }
            m_bLongPress = false; // 置false
        }
        else{
            if (!m_bLongPress) {
                qDebug() << "键盘长按";
                // 限定长按只执行一次,最后会在Relese(非长按)里将LongPress_重新置false
                m_bLongPress = true;
            }
        }
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // 判断控件
    // if (obj = ui->lineEdit) {
    //     if (event->type() == QEvent::KeyPress) {
    //         QKeyEvent* event1 = static_cast<QKeyEvent*>(event);
    //         if (event1->key() == Qt::Key_I) {
    //             QString str = QString("事件过滤器中键盘按下为:%1").arg(event1->key());
    //             qDebug() << str;
    //         }
    //         return true;
    //     }
    // }
    // return QMainWindow::eventFilter(obj, event);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    popMenu->clear();
    popMenu->addAction(action1);
    popMenu->addAction(action2);

    // 添加线
    popMenu->addSeparator();

    popMenu->addAction(action3);
    popMenu->exec(QCursor::pos());
}

// 绘制椭圆
void MainWindow::DrawEllipse()
{
    drawType = DrawType::ELLIPSE;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}

// 绘制矩形
void MainWindow::DrawRect()
{
    drawType = DrawType::RECT;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}

// 绘制线段
void MainWindow::DrawLine()
{
    drawType = DrawType::LINE;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}

// 绘制圆
void MainWindow::DrawRound()
{
    drawType = DrawType::ROUND;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}

// 绘制文本
void MainWindow::DrawText()
{
    drawType = DrawType::TEXT;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}

// 绘制图片
void MainWindow::DrawPicture()
{
    drawType = DrawType::PICTURE;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}
