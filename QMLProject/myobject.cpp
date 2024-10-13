#include "myobject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::setIValue(int newValue)
{
//    if (m_iValue == newValue){
//        return;
//    }
//    m_iValue = newValue;
//    emit iValueChanged();
}

int MyObject::getValue()
{
    //return m_iValue;
}

void MyObject::setsString(QString newString)
{
//    if (m_sString == newString)
//    {
//        return;
//    }
//    m_sString = newString;
//    emit sStringChanged();
}

QString MyObject::getString()
{
   // return m_sString;
}

MyObject *MyObject::getInstance()
{
    MyObject *object = new MyObject;
    return object;
}

void MyObject::cppSlot(QVariant i, QVariant s)
{
    qDebug() << i << s;
}
