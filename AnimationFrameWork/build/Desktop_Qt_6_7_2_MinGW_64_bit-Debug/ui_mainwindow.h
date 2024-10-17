/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *PosBtn;
    QPushButton *GeomertyBtn;
    QPushButton *ColorBtn;
    QPushButton *pushButton_4;
    QPushButton *OpacityBtn;
    QPushButton *ResetBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 40, 120, 80));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 255)"));
        PosBtn = new QPushButton(centralwidget);
        PosBtn->setObjectName("PosBtn");
        PosBtn->setGeometry(QRect(560, 40, 141, 28));
        GeomertyBtn = new QPushButton(centralwidget);
        GeomertyBtn->setObjectName("GeomertyBtn");
        GeomertyBtn->setGeometry(QRect(560, 110, 141, 28));
        ColorBtn = new QPushButton(centralwidget);
        ColorBtn->setObjectName("ColorBtn");
        ColorBtn->setGeometry(QRect(560, 180, 141, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(560, 250, 141, 28));
        OpacityBtn = new QPushButton(centralwidget);
        OpacityBtn->setObjectName("OpacityBtn");
        OpacityBtn->setGeometry(QRect(560, 320, 141, 28));
        ResetBtn = new QPushButton(centralwidget);
        ResetBtn->setObjectName("ResetBtn");
        ResetBtn->setGeometry(QRect(560, 390, 141, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        PosBtn->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\345\212\250\347\224\273", nullptr));
        GeomertyBtn->setText(QCoreApplication::translate("MainWindow", "\345\207\240\344\275\225\345\212\250\347\224\273", nullptr));
        ColorBtn->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262\345\212\250\347\224\273", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\344\270\215\351\200\217\346\230\216\345\272\246\345\212\250\347\224\273", nullptr));
        OpacityBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\215\351\200\217\346\230\216\345\272\246\345\212\250\347\224\273", nullptr));
        ResetBtn->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
