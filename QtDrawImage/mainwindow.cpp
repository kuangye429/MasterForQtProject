#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pix = QPixmap(800,600);
    pix.fill(Qt::transparent);
    tempPix = pix;
    isDrawing = false;
    drawType = DrawType::NULLDRAW;
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
    // 设置画笔颜色、宽度
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
        painter.setBrush(Qt::blue);
        painter.drawEllipse(QPoint(startPoint.x(), startPoint.y()),
                            (endPoint.x() - startPoint.x()), (endPoint.y() - startPoint.y()));
    }
    painter.end();
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    if (!isDrawing){
        pix = tempPix;
    }
}

void MainWindow::DrawEllipse()
{
    drawType = DrawType::ELLIPSE;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}

void MainWindow::DrawRect()
{
    drawType = DrawType::RECT;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}

void MainWindow::DrawLine()
{
    drawType = DrawType::LINE;
    pix.fill(Qt::transparent);
    tempPix.fill(Qt::transparent);
}
