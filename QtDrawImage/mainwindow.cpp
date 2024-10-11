#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    connect(ui->btnPicture, &QPushButton::clicked, this, &MainWindow::DrawPicture);
    connect(ui->btnTest, &QPushButton::clicked, this, &MainWindow::DrawText);
    connect(ui->btnRound, &QPushButton::clicked, this, &MainWindow::DrawRound);
    connect(ui->btnEllipse, &QPushButton::clicked, this, &MainWindow::DrawEllipse);
    connect(ui->btnRect, &QPushButton::clicked, this, &MainWindow::DrawRect);
    connect(ui->btnLine, &QPushButton::clicked, this, &MainWindow::DrawLine);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        startPoint = event->pos();
        isDrawing = true;
        pix.fill(Qt::transparent);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
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

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    update();
    int x = startPoint.x();
    int y = startPoint.y();
    int width = endPoint.x() - x;
    int height = endPoint.y() - y;
    QPainter painter;
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
    painter.end();
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    if (!isDrawing){
        pix = tempPix;
    }
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
