#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QStyleOption>
#include <QBuffer>
#include <QMessageBox>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("签名DEMO");
    ui->btn_Confirm->setStyleSheet("QPushButton{background-color:white}");
    ui->btn_Clear->setStyleSheet("QPushButton{background-color:white}");
    ui->widget->setStyleSheet("QWidget{border: 2px solid black; background-color: white}");
    ui->widget->installEventFilter(this);
    connect(ui->btn_Clear, SIGNAL(clicked()), this, SLOT(BtnClearSlot()));
    connect(ui->btn_Confirm, SIGNAL(clicked()), this, SLOT(BtnConfirmSlot()));
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject * obj, QEvent * event)
{
    if(obj == ui->widget){
        if(event->type() == QEvent::MouseButtonPress){
            vecPoint.push_back(QVector<QPoint>());
            vecPoint[vecPoint.size() - 1].push_back(((QMouseEvent *)event)->pos());
            ui->widget->update();
        }else if(event->type() == QEvent::MouseMove){
            vecPoint[vecPoint.size() - 1].push_back(((QMouseEvent *)event)->pos());
            ui->widget->update();
        }else if(event->type() == QEvent::Paint){
            Paint(ui->widget);
        }
    }
    return QWidget::eventFilter(obj,event);
}

void Widget::Paint(QPaintDevice * device)
{
    QPainter painter(device);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(Qt::black,7,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    for(int i = 0;i < vecPoint.size();++i){
        for(int j = 0;j < vecPoint[i].size() - 1;++j){
            painter.drawLine(vecPoint[i][j],vecPoint[i][j + 1]);
        }
    }
}

void Widget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Widget::BtnClearSlot()
{
    vecPoint = QVector<QVector<QPoint> >();
    ui->widget->update();
}

void Widget::BtnConfirmSlot()
{
    if(vecPoint.size() <= 0){
        return;
    }
    QImage img(ui->widget->size(),QImage::Format_ARGB32);
    img.fill(Qt::white);
    Paint(&img);
    QString imgPath = "sign.png";
    bool ret = img.save(imgPath);
    if (ret) {
        QMessageBox::information(nullptr, "保存成功", "文件成功保存。");
    } else {
        QMessageBox::information(nullptr, "保存失败", "文件保存失败");
    }
    saveBase64ImageToFile("sign.png", "baseText.txt");

}

bool Widget::saveBase64ImageToFile(const QString &imagePath, const QString &txtFilePath)
{
    QImage image(imagePath);
    if (image.isNull()) {
        qDebug() << "图片加载失败";
        return false;
    }

    // 将图片转换为Base64编码
    QByteArray imageData;
    QBuffer buffer(&imageData);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG"); // 可以改为其他格式，如"JPG"
    QByteArray base64Image = imageData.toBase64();

    // 保存Base64编码到文本文件
    QFile txtFile(txtFilePath);
    if (!txtFile.open(QIODevice::WriteOnly)) {
        qDebug() << "文本文件打开失败";
        return false;
    }
    txtFile.write(base64Image);
    txtFile.close();

    return true;
}
