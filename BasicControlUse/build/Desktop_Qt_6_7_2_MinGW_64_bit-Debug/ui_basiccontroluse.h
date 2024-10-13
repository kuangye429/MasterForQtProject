/********************************************************************************
** Form generated from reading UI file 'basiccontroluse.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICCONTROLUSE_H
#define UI_BASICCONTROLUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BasicControlUse
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BasicControlUse)
    {
        if (BasicControlUse->objectName().isEmpty())
            BasicControlUse->setObjectName("BasicControlUse");
        BasicControlUse->resize(800, 600);
        centralwidget = new QWidget(BasicControlUse);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(tab);
        widget->setObjectName("widget");

        horizontalLayout->addWidget(widget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        graphicsView = new QGraphicsView(tab_2);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout_2->addWidget(graphicsView);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        BasicControlUse->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BasicControlUse);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        BasicControlUse->setMenuBar(menubar);
        statusbar = new QStatusBar(BasicControlUse);
        statusbar->setObjectName("statusbar");
        BasicControlUse->setStatusBar(statusbar);

        retranslateUi(BasicControlUse);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BasicControlUse);
    } // setupUi

    void retranslateUi(QMainWindow *BasicControlUse)
    {
        BasicControlUse->setWindowTitle(QCoreApplication::translate("BasicControlUse", "BasicControlUse", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("BasicControlUse", "TableWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("BasicControlUse", "GraphicView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BasicControlUse: public Ui_BasicControlUse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICCONTROLUSE_H
