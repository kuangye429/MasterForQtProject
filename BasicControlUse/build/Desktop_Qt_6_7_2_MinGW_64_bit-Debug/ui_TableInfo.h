/********************************************************************************
** Form generated from reading UI file 'TableInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEINFO_H
#define UI_TABLEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *btnConfim;
    QPushButton *btnCan;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_age;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_work;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(304, 241);
        btnConfim = new QPushButton(Form);
        btnConfim->setObjectName("btnConfim");
        btnConfim->setGeometry(QRect(40, 180, 93, 28));
        btnCan = new QPushButton(Form);
        btnCan->setObjectName("btnCan");
        btnCan->setGeometry(QRect(150, 180, 93, 28));
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 50, 221, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName("lineEdit_name");

        horizontalLayout->addWidget(lineEdit_name);

        widget1 = new QWidget(Form);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(40, 90, 221, 27));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEdit_age = new QLineEdit(widget1);
        lineEdit_age->setObjectName("lineEdit_age");

        horizontalLayout_2->addWidget(lineEdit_age);

        widget2 = new QWidget(Form);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(40, 130, 221, 27));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lineEdit_work = new QLineEdit(widget2);
        lineEdit_work->setObjectName("lineEdit_work");

        horizontalLayout_3->addWidget(lineEdit_work);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        btnConfim->setText(QCoreApplication::translate("Form", "\347\241\256\345\256\232", nullptr));
        btnCan->setText(QCoreApplication::translate("Form", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("Form", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "\350\201\214\344\270\232\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEINFO_H
