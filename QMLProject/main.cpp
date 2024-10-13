#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include <myobject.h>
#include <QObject>
#include <qobjectdefs.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // 全局对象  上下文对象
    QQmlContext* context = engine.rootContext();
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen->virtualGeometry();
    //context->setContextProperty("SCREEN_WIDTH",800);
    qmlRegisterType<MyObject>("MyObj", 1,0, "MyObject");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // 在Cpp端绑定与QML的信号
    auto list = engine.rootObjects();
    auto window = list.first();
    // 查找当前组件的子对象
    auto buttonObj = list.first()->findChildren<QObject *>("myButton");
    QObject::connect(window, SIGNAL(qmlSig(QVariant, QVariant)),
                     MyObject::getInstance(), SLOT(cppSlot(QVariant, QVariant)));
    QObject::connect(MyObject::getInstance(), SIGNAL(cppSignal(QVariant, QVariant)),
                     window, SLOT(qmlSlot(QVariant, QVariant)));

    // 通过C++端调用QML函数
    QVariant res;
    QVariant arg1 = 123;
    QVariant arg2 = "112";
    QMetaObject::invokeMethod(window, "qmlFunc",
                              Q_RETURN_ARG(QVariant,res),
                              Q_ARG(QVariant,arg1),
                              Q_ARG(QVariant,arg2)); // 调用QML端的函数
    qDebug()<<res;

    return app.exec();
}
