#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

// #ifdef Q_OS_LINUX
//     QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
//     QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
//     QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
// #else
//     QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
//     QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
//     QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
// #endif
    MainWindow w;
    w.show();
    return a.exec();
}
