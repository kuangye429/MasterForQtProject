#ifndef IMAGETEST_H
#define IMAGETEST_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>
// 调用摄像头
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>

namespace Ui {
class ImageTest;
}

class ImageTest : public QWidget
{
    Q_OBJECT

public:
    explicit ImageTest(QWidget *parent = nullptr);
    ~ImageTest();

private:
    void InitUi();
private slots:
    void OnPushButton();
    void OnPushButton1();
    void showCamera(int id, const QImage& preview);
    void tokenReply(QNetworkReply *reply);
private:
    Ui::ImageTest *ui;
    QCamera *m_camera;  // 摄像头
    QCameraViewfinder *m_finder;  // 摄像头取景器
    QCameraImageCapture *m_capture; // 摄像头捕获器

    QVBoxLayout *vbox1;
    QLabel *pictureLabel;
    QPushButton *button;
    QPushButton *button1;
    QTextBrowser *textB;
    QVBoxLayout *vbox2;
    QHBoxLayout *hbox;

    QTimer *timer;
    QNetworkAccessManager  *tokenManager;
};

#endif // IMAGETEST_H
