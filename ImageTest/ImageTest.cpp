#include "ImageTest.h"
#include "ui_imagetest.h"
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>
#include <QSslConfiguration>



ImageTest::ImageTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageTest)
{
    ui->setupUi(this);
    // 设置摄像头功能
    m_camera = new QCamera();
    m_finder = new QCameraViewfinder();
    m_capture = new QCameraImageCapture(m_camera);  // 捕捉器构造Capture需要指明摄像头
    m_camera->setViewfinder(m_finder); // 设置摄像头的取景器
    m_camera->setCaptureMode(QCamera::CaptureStillImage);
    connect(m_capture, &QCameraImageCapture::imageCaptured, this, &ImageTest::showCamera);
    // 设置捕获的图片保存为一个文件
    m_capture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    m_camera->start(); // 启动摄像头

    InitUi();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ImageTest::OnPushButton);
    timer->start(20);

    tokenManager = new QNetworkAccessManager(this);
    // 判断所支持的协议
    qDebug() << tokenManager->supportedSchemes();

    // 拼接url及参数
    QUrl url("https://aip.baidubce.com/oauth/2.0/token");
    QUrlQuery query;
    query.addQueryItem("grant_type", "client_credentials");
    query.addQueryItem("client_id", "oQXBRlaW4BrlvqrvMpCAkyCd");
    query.addQueryItem("client_secret", "BxjQcEpqikDuUR19e1vv3F4CTBQgPpj");


    url.setQuery(query);
    qDebug()<<url;

    QSslSocket *ssl = new QSslSocket(this);
    if (ssl->supportsSsl()) {
        qDebug()<<"支持ssl";
    }
    // ssl配置
    QSslConfiguration config = ssl->sslConfiguration();
    config.setProtocol(QSsl::SslV2);
    config.setPeerVerifyMode(QSslSocket::QueryPeer);

    // 组装请求
    QNetworkRequest req;
    req.setUrl(url);
    req.setSslConfiguration(config);

    // 发送请求
    tokenManager->get(req);
    connect(tokenManager, &QNetworkAccessManager::finished, this, &ImageTest::tokenReply);
}

ImageTest::~ImageTest()
{
    delete ui;
    if (m_camera != nullptr) {
        delete m_camera;
        m_camera = nullptr;
    }
    if (m_capture != nullptr) {
        delete  m_capture;
        m_capture = nullptr;
    }
    if (m_finder != nullptr) {
        delete  m_finder;
        m_finder = nullptr;
    }
}

void ImageTest::InitUi()
{
    this->setFixedSize(800,600);
    vbox1 = new QVBoxLayout();
    QHBoxLayout *hboxButton = new QHBoxLayout();
    pictureLabel = new QLabel(this);
    button = new QPushButton(this);
    button1 = new QPushButton(this);
    textB = new QTextBrowser(this);
    button->setText("拍照");
    button1->setText("清空");
    pictureLabel->setFixedSize(400, 300);
    pictureLabel->setScaledContents(true);
    vbox1->addWidget(pictureLabel);
    hboxButton->addWidget(button);
    hboxButton->addWidget(button1);
    vbox1->addLayout(hboxButton);
    vbox2 = new QVBoxLayout();
    vbox2->addWidget(m_finder);
    vbox2->addWidget(textB);
    hbox = new QHBoxLayout(this);
    hbox->addLayout(vbox1);
    hbox->addLayout(vbox2);
    this->setLayout(hbox);
    connect(button, SIGNAL(clicked()), this, SLOT(OnPushButton()));
    connect(button1, SIGNAL(clicked()), this, SLOT(OnPushButton1()));
}

void ImageTest::OnPushButton()
{
    // 设置拍照，异步操作
    m_capture->capture();
}

void ImageTest::OnPushButton1()
{
    pictureLabel->setPixmap(QPixmap());
}

void ImageTest::showCamera(int id, const QImage &preview)
{
    Q_UNUSED(id);
    // 使用QPixMap::fromImage将QImage进行转换填充到Label控件中
    pictureLabel->setPixmap(QPixmap::fromImage(preview));
}

void ImageTest::tokenReply(QNetworkReply *reply)
{
    // 解析应答的内容
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << reply->errorString();
        return;
    }
    //输出应答内容
    const QByteArray reply_data =  reply->readAll();
    qDebug() << reply_data;

    // json解析
    QJsonParseError jsonErr;
    QJsonDocument doc = QJsonDocument::fromJson(reply_data, &jsonErr);
    QString accessToken;
    if(jsonErr.error == QJsonParseError::NoError) {
        QJsonObject obj = doc.object();
        if (obj.contains("access_token")) {
            accessToken = obj.take("access_token").toString();
        }
        textB->setText(accessToken);
    }
}
