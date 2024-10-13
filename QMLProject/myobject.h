#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QtQml>
#include "string.h"

class MyObject : public QObject
{
    Q_OBJECT

public:
    explicit MyObject(QObject *parent = nullptr);
    void func();
    void setIValue(int newValue);
    int getValue();
    void setsString(QString newString);
    QString getString();
    static MyObject* getInstance();
signals:
    void iValueChanged();
    void sStringChanged();
    void cppSignal(QVariant i, QVariant s);
public slots:
    void cppSlot(QVariant i, QVariant s);
private:
//    int m_iValue;
//    QString m_sString;
//    Q_PROPERTY(int m_iValue READ m_iValue WRITE setIValue NOTIFY iValueChanged)
//    Q_PROPERTY(QString m_sString READ m_sString WRITE setIValue NOTIFY iValueChanged)
public slots:
};

#endif // MYOBJECT_H
