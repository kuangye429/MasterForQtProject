#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QHBoxLayout>

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
    // 禁用所有按钮
    void DisableAllButton();

    // 启用所有按钮
    void EnableAllButton();

    // 设置各种动画
    void setPosAnimation();

    void setGeometryAnimation();

    void setColorAnimation();

    void setWindowOpacityAnimation();

    void setOpacityAnimation();
    void InitUi();

private slots:
    void PosButtonClicked();
    void GeometryButtonClicked();
    void ColorButtonClicked();
    void WindowOpacityButtonClicked();
    void OpacityButtonClicked();
    void ResetButtonClicked();

private:
    Ui::MainWindow *ui;
    // 位置属性动画
    QPropertyAnimation* m_posAnimation;
    // 几何属性动画
    QPropertyAnimation* m_GeomertyAnimation;
    // 颜色属性动画
    QPropertyAnimation* m_ColorAnimation;
    // 窗口不透明度属性动画
    QPropertyAnimation* m_WindowOpacityAnimation;
    // 不透明属性动画
    QPropertyAnimation* m_OpacityAnimation;
};
#endif // MAINWINDOW_H
