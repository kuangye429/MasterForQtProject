#ifndef BASICCONTROLUSE_H
#define BASICCONTROLUSE_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMenu>
#include <QAction>
#include <QCheckBox>
#include <QTreeWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QWheelEvent>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class BasicControlUse;
}
QT_END_NAMESPACE

class BasicControlUse : public QMainWindow
{
    Q_OBJECT

public:
    BasicControlUse(QWidget *parent = nullptr);
    ~BasicControlUse();
private:
    void InitTableUi();
    void InitTreeUi();
    void contextMenuEvent(QContextMenuEvent *event);
    void update();
    void InitGraphicsView();

protected:
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void Add();
    void Delete();
    void Clear();
    void DeleteCheck();
    void SlotClicked(QTreeWidgetItem* item, int column);

private:
    Ui::BasicControlUse *ui;
    QTableWidget *tableWidget;
    QMenu *actionMenu;
    QAction *addAction1;
    QAction *deleteAction1;
    QAction *clearAction1;
    QAction *deleteCheckAction1;
    QWidget* Widget2;
    QTreeWidget * treeWidget;
};
#endif // BASICCONTROLUSE_H
