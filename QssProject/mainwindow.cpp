#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(SetQss()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetQss()   //设置样式
{
    // 创建文件
    QFile file(":/QSS/myqss.qss");
    // 只读方式打开文件
    file.open(QFile::ReadOnly);
    // 将文件中字符存入字符串
    QString styleSheet = tr(file.readAll());
    // 设置窗口的QSS
    this->setStyleSheet(styleSheet);
    file.close();
}
