#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QRect>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>

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
    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    // 鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    // 鼠标双击事件
    void mouseDoubleClickEvent(QMouseEvent *event);
    // 绘制图形事件
    void paintEvent(QPaintEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event);
    // 键盘松开事件
    void keyReleaseEvent(QKeyEvent *event);

    // 事件过滤器
    bool eventFilter(QObject *obj, QEvent *event);

    // 右键菜单
    void contextMenuEvent(QContextMenuEvent *event);
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
    QTimer* m_pTimer;
    int m_nClickCnt;
    bool m_bLongPress;
    QMenu *popMenu;     // 右键弹出菜单
    QAction *action1;   // 功能1
    QAction *action2;   // 功能2
    QAction *action3;   // 退出
};
#endif // MAINWINDOW_H
