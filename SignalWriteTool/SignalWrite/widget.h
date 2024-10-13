#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QMouseEvent>
#include <QPainter>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
    bool eventFilter(QObject * obj, QEvent * event) override;
    void paintEvent(QPaintEvent *) override;
    bool saveBase64ImageToFile(const QString &base64, const QString &filePath);
private slots:
    void BtnClearSlot();
    void BtnConfirmSlot();
private:
    Ui::Widget *ui;
    QVector<QVector<QPoint> > vecPoint;
    void Paint(QPaintDevice * device);
};

#endif // WIDGET_H
