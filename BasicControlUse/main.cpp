#include "basiccontroluse.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BasicControlUse w;
    w.show();
    return a.exec();
}
