#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsColorizeEffect>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_posAnimation(nullptr)
    , m_GeomertyAnimation(nullptr)
    , m_ColorAnimation(nullptr)
    , m_WindowOpacityAnimation(nullptr)
    , m_OpacityAnimation(nullptr)
{
    ui->setupUi(this);
    InitUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisableAllButton()
{
    ui->PosBtn->setEnabled(false);
    ui->ColorBtn->setEnabled(false);
    ui->GeomertyBtn->setEnabled(false);
    ui->OpacityBtn->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->ResetBtn->setEnabled(false);
}

void MainWindow::EnableAllButton()
{
    ui->PosBtn->setEnabled(true);
    ui->ColorBtn->setEnabled(true);
    ui->GeomertyBtn->setEnabled(true);
    ui->OpacityBtn->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->ResetBtn->setEnabled(true);
}

void MainWindow::setPosAnimation()
{
    // 设置动画应用对象
    m_posAnimation->setTargetObject(ui->widget);

    // 设置动画属性
    m_posAnimation->setPropertyName("pos");

    // 设置动画起始位置
    QPoint startPoint(100,100);
    m_posAnimation->setStartValue(startPoint);
    // 设置动画结束位置
    m_posAnimation->setEndValue(startPoint + QPoint(500,400));

    // 设置动画持续时间
    m_posAnimation->setDuration(10000);

    // 关联动画信号
    connect(m_posAnimation, &QPropertyAnimation::stateChanged, this, [this](QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
    {
        if (newState == QAbstractAnimation::State::Running && oldState == QAbstractAnimation::State::Stopped)
        {
            // 动画开始运行，禁用所有按钮
            this->DisableAllButton();
        }
     });
    connect(m_posAnimation, &QPropertyAnimation::finished, this, [this]()
    {
        // 动画运行结束，解除禁用
        this->EnableAllButton();
    });
}

void MainWindow::setGeometryAnimation()
{
    // 1. 设置动画应用对象
    m_GeomertyAnimation->setTargetObject(ui->widget);
    // 2.设置动画属性
    m_GeomertyAnimation->setPropertyName("geometry");

    // 3.设置动画的起始和结束值
    m_GeomertyAnimation->setStartValue(QRect(0, 0, 10, 10));
    m_GeomertyAnimation->setEndValue(QRect(500, 400, 200, 200));

    // 4. 设置某个时间段的值
    // 用于在动画过程中设置关键帧的值
    m_GeomertyAnimation->setKeyValueAt(0.6, QRect(700, 200, 100, 100));

    // 5.设置动画的持续时间
    m_GeomertyAnimation->setDuration(2000);

    // 6.设置动画的缓和曲线
    m_GeomertyAnimation->setEasingCurve(QEasingCurve::Linear);

    // 7.设置动画的播放周期
    m_GeomertyAnimation->setLoopCount(1.0);


    // 8.关联动画信号
    connect(m_GeomertyAnimation, &QPropertyAnimation::stateChanged, this, [this](QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
    {
        if (newState == QAbstractAnimation::State::Running && oldState == QAbstractAnimation::State::Stopped)
        {
            this->DisableAllButton();
        }
    });

    connect(m_GeomertyAnimation, &QPropertyAnimation::finished, this, [this]()
    {
        this->EnableAllButton();
    });
}

void MainWindow::setColorAnimation()
{
    // 创建着色效果
    QGraphicsColorizeEffect* colorEffect = qobject_cast<QGraphicsColorizeEffect*>(
        ui->widget->graphicsEffect());
    delete colorEffect;

    // 添加着色效果
    colorEffect = new QGraphicsColorizeEffect(this);
    ui->widget->setGraphicsEffect(colorEffect);

    // 应用动画属性
    m_ColorAnimation->setTargetObject(colorEffect);
    m_ColorAnimation->setPropertyName("color");

    // 设置动画的起始和结束值
    m_ColorAnimation->setStartValue(QColor(Qt::red));
    m_ColorAnimation->setEndValue(QColor(Qt::blue));

    // 设置动画的持续时间
    m_ColorAnimation->setDuration(4000);

    // 设置动画的缓和曲线
    m_ColorAnimation->setEasingCurve(QEasingCurve::Linear);

    // 设置动画的播放周期
    m_ColorAnimation->setLoopCount(1.0);

    // 8. 关联动画信号
    connect(m_ColorAnimation, &QPropertyAnimation::stateChanged, this, [this](QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
    {
        if (newState == QAbstractAnimation::State::Running && oldState == QAbstractAnimation::State::Stopped)
        {
            this->DisableAllButton();
        }
    });

    connect(m_ColorAnimation, &QPropertyAnimation::finished, this, [this]()
    {
        this->EnableAllButton();
    });
}

void MainWindow::setWindowOpacityAnimation()
{
    // 1. 设置动画应用对象
    m_WindowOpacityAnimation->setTargetObject(this);
    // 2.设置动画属性
    m_WindowOpacityAnimation->setPropertyName("windowOpacity");
    // 3.设置动画的起始值
    m_WindowOpacityAnimation->setStartValue(0.1);
    m_WindowOpacityAnimation->setEndValue(1.0);

    // 4.设置动画的时间
    m_WindowOpacityAnimation->setDuration(3000);

    // 5.设置动画的缓和曲线
    m_WindowOpacityAnimation->setEasingCurve(QEasingCurve::Linear);

    // 6.设置动画的播放周期
    m_WindowOpacityAnimation->setLoopCount(1.0);

    // 7.关联动画信号
    connect(m_WindowOpacityAnimation, &QPropertyAnimation::stateChanged, this, [this](QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
    {
        if (newState == QAbstractAnimation::State::Running && oldState == QAbstractAnimation::State::Stopped)
        {
            // 动画开始运行，禁用所有按钮
            this->DisableAllButton();
        }
    });


    connect(m_WindowOpacityAnimation, &QPropertyAnimation::finished, this, [this]()
    {
        // 动画运行结束，解除禁用
        this->EnableAllButton();
    });
}

void MainWindow::setOpacityAnimation()
{
    // 1. 创建不透明度效果
    QGraphicsOpacityEffect* opacityEffect = qobject_cast<QGraphicsOpacityEffect*>(
        ui->widget->graphicsEffect());
    delete opacityEffect;
    // 没有着色效果就进行添加
    opacityEffect = new QGraphicsOpacityEffect(ui->widget);
    ui->widget->setGraphicsEffect(opacityEffect);

    // 2. 应用动画属性
    m_OpacityAnimation->setTargetObject(opacityEffect);

    // 3.设置动画属性
    m_OpacityAnimation->setPropertyName("opacity");

    // 4.设置动画的起始和结束值
    m_OpacityAnimation->setStartValue(0.0);
    m_OpacityAnimation->setEndValue(1.0);

    // 5.设置动画的持续事件
    m_OpacityAnimation->setDuration(3000);


    // 6.设置动画的缓和曲线
    m_OpacityAnimation->setEasingCurve(QEasingCurve::Linear);

    // 7.设置动画的播放周期
    m_OpacityAnimation->setLoopCount(1);


    connect(m_OpacityAnimation, &QPropertyAnimation::stateChanged, this, [this](QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
    {
        if (newState == QAbstractAnimation::State::Running && oldState == QAbstractAnimation::State::Stopped)
        {
            this->DisableAllButton();
        }
    });


    connect(m_OpacityAnimation, &QPropertyAnimation::finished, this, [this]()
    {
        this->EnableAllButton();
    });
}

void MainWindow::InitUi()
{
    m_posAnimation = new QPropertyAnimation(ui->widget);
    m_GeomertyAnimation = new QPropertyAnimation(ui->widget);
    m_ColorAnimation = new QPropertyAnimation(ui->widget);
    m_WindowOpacityAnimation = new QPropertyAnimation(ui->widget);
    m_OpacityAnimation = new QPropertyAnimation(ui->widget);
    connect(ui->PosBtn, &QPushButton::clicked, this, &MainWindow::PosButtonClicked);
    connect(ui->ColorBtn, &QPushButton::clicked, this, &MainWindow::ColorButtonClicked);
    connect(ui->GeomertyBtn, &QPushButton::clicked, this, &MainWindow::GeometryButtonClicked);
    connect(ui->OpacityBtn, &QPushButton::clicked, this, &MainWindow::OpacityButtonClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::WindowOpacityButtonClicked);
    connect(ui->ResetBtn, &QPushButton::clicked, this, &MainWindow::ResetButtonClicked);
}

void MainWindow::PosButtonClicked()
{
    // 设置动画属性
    setPosAnimation();
    m_posAnimation->start();
}

void MainWindow::GeometryButtonClicked()
{
    setGeometryAnimation();
    m_GeomertyAnimation->start();
}

void MainWindow::ColorButtonClicked()
{
    setColorAnimation();
    m_ColorAnimation->start();
}

void MainWindow::WindowOpacityButtonClicked()
{
    setWindowOpacityAnimation();
    m_WindowOpacityAnimation->start();
}

void MainWindow::OpacityButtonClicked()
{
    setOpacityAnimation();
    m_OpacityAnimation->start();
}

void MainWindow::ResetButtonClicked()
{
    int w = ui->widget->width();
    int h = ui->widget->height();
    ui->widget->setGeometry(100,100,w,h);
}
