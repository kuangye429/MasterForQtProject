#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QRect>

enum DrawType{
    ELLIPSE,
    RECT,
    LINE,
    ROUND,
    TEXT,
    PICTURE,
    NULLDRAW
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event) override;

private slots:
    void DrawEllipse();
    void DrawRect();
    void DrawLine();
    void DrawRound();
    void DrawText();
    void DrawPicture();

private:
    Ui::MainWindow *ui;
    QPixmap pix;
    QPixmap tempPix;
    QPoint  startPoint;
    QPoint  endPoint;
    bool    isDrawing;
    DrawType drawType;
};
#endif // MAINWINDOW_H
