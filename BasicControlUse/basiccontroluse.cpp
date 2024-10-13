#include "basiccontroluse.h"
#include "ui_basiccontroluse.h"
#include <QContextMenuEvent>
#include <QMessageBox>
#include <QTransform>

BasicControlUse::BasicControlUse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BasicControlUse)
{
    ui->setupUi(this);
    InitTableUi();
    InitTreeUi();
    InitGraphicsView();
}

BasicControlUse::~BasicControlUse()
{
    delete ui;
}

// 初始化TableWidget
void BasicControlUse::InitTableUi()
{
    QHBoxLayout *hLayout = new QHBoxLayout();
    // 创建QTableWidget
    tableWidget = new QTableWidget(this);
    hLayout->addWidget(tableWidget);
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(4);
    tableWidget->setSortingEnabled(true);
    tableWidget->setHorizontalHeaderLabels(QStringList()<<" "<<"姓名"<<"年龄"<<"性别");

    // 添加菜单
    actionMenu = new QMenu(ui->tabWidget);
    actionMenu->setStyleSheet(QStringLiteral("background-color: rgb(99, 99, 99);"));
    addAction1 = new QAction(ui->tabWidget);
    addAction1->setText("增加");
    deleteAction1 = new QAction(ui->tabWidget);
    deleteAction1->setText("删除");
    clearAction1 = new QAction(ui->tabWidget);
    clearAction1->setText("清空");
    deleteCheckAction1 = new QAction(ui->tabWidget);
    deleteCheckAction1->setText("删除指定行");
    actionMenu->addAction(addAction1);
    actionMenu->addAction(deleteAction1);
    actionMenu->addAction(clearAction1);
    actionMenu->addAction(deleteCheckAction1);
    tableWidget->setColumnWidth(0, 24);


    // 设置这个QMenu为这个QMainWindow的上下文菜单
    connect(addAction1, &QAction::triggered, this, &BasicControlUse::Add);
    connect(deleteAction1, &QAction::triggered, this, &BasicControlUse::Delete);
    connect(clearAction1, &QAction::triggered, this, &BasicControlUse::Clear);
    connect(deleteCheckAction1, &QAction::triggered, this, &BasicControlUse::DeleteCheck);
    ui->widget->setLayout(hLayout);
}

// 初始化TreeWidget
void BasicControlUse::InitTreeUi()
{
    treeWidget = new QTreeWidget(this);
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(treeWidget);
    Widget2 = new QWidget();
    ui->tabWidget->addTab(Widget2, "TreeWidget");
    Widget2->setLayout(hLayout);
    // 添加顶层节点
    QTreeWidgetItem *topItem1 = new QTreeWidgetItem(treeWidget);
    topItem1->setText(0, "百度");
    treeWidget->addTopLevelItem(topItem1);

    // 设置表头隐藏，展开所有项
    //treeWidget->setHeaderHidden(true);
    // 设置展开
    //treeWidget->expandAll();

    // 顶层节点添加子节点
    QTreeWidgetItem *item2 = new QTreeWidgetItem(topItem1);
    item2->setText(0, "研发部");
    QTreeWidgetItem *item3 = new QTreeWidgetItem(topItem1);
    item3->setText(0, "销售部");

    QTreeWidgetItem *topItem2 = new QTreeWidgetItem(treeWidget);
    topItem2->setText(0, "腾讯");
    topItem2->setCheckState(0, Qt::Checked);
    treeWidget->addTopLevelItem(topItem2);

    QTreeWidgetItem *topItem21 = new QTreeWidgetItem(topItem2);
    topItem21->setText(0, "研发部");
    topItem21->setCheckState(0, Qt::Checked);
    QTreeWidgetItem *topItem22 = new QTreeWidgetItem(topItem2);
    topItem22->setText(0, "销售部");
    topItem22->setCheckState(0, Qt::Checked);

    connect(treeWidget, &QTreeWidget::itemClicked, this, &BasicControlUse::SlotClicked);
}

void BasicControlUse::contextMenuEvent(QContextMenuEvent *event)
{
    actionMenu->exec(event->globalPos());
}

void BasicControlUse::Add()
{
    int rowCount = tableWidget->rowCount();
    tableWidget->insertRow(rowCount);
    for (int column = 1; column < tableWidget->columnCount(); ++column)
    {
        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);  //是否设置选中框
        QTableWidgetItem *item = new QTableWidgetItem(QString("%1-%2").arg(rowCount + 1).arg(column + 1));
        tableWidget->setItem(rowCount, 0, check);
        tableWidget->setItem(rowCount, column, item);
    }
}

void BasicControlUse::Delete()
{
    int currentRow = tableWidget->currentRow();
    if(currentRow != -1) {
        tableWidget->removeRow(currentRow);
    } else {
        QMessageBox::warning(this, "错误", "请先选择一行以删除。");
    }
    update();
}

void BasicControlUse::update()
{
    for (int i = 0; i < tableWidget->rowCount(); i++) {
        for (int j = 0; j < tableWidget->columnCount(); j++) {
            QTableWidgetItem *check = new QTableWidgetItem();
            check->setCheckState(Qt::Unchecked);  //是否设置选中框
            QTableWidgetItem *item = new QTableWidgetItem(QString("%1-%2").arg(i + 1).arg(j + 1));
            tableWidget->setItem(i, 0, check);
            tableWidget->setItem(i, j, item);
        }
    }
}

void BasicControlUse::InitGraphicsView()
{
    // 创建视图
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 200, 200);

    QGraphicsRectItem *item1 = new QGraphicsRectItem(0,0,20,20);
    item1->setBrush(Qt::red);
    item1->setPos(10,0);
    //scene->addItem(item1);

    QGraphicsRectItem *item2 = new QGraphicsRectItem(0,0,20,20);
    item2->setBrush(Qt::green);
    item2->setPos(40,0);
    //scene->addItem(item2);
    //新建图形项组
    QGraphicsItemGroup *group = new QGraphicsItemGroup;
    group->addToGroup(item1);
    group->addToGroup(item2);
    scene->addItem(group);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    //手型拖动
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    scene->setSceneRect(0, 0, 800, 800);

}

void BasicControlUse::mousePressEvent(QMouseEvent *event)
{

}

void BasicControlUse::Clear()
{
    int num = tableWidget->rowCount();
    for (int i = num; i >= 0; i--) {
        tableWidget->removeRow(i);
    }
}

void BasicControlUse::DeleteCheck()
{
    while(tableWidget->selectedItems().count() > 0) {
        int rowIdx = tableWidget->selectedItems()[0]->row();
        tableWidget->removeRow(rowIdx);
    }
    if (!tableWidget) {
        return;
    }
    for(int i = tableWidget->rowCount(); i >=0; i--){
        QTableWidgetItem *item = tableWidget->item(i,0);
        if (item && item->checkState() == Qt::Checked) {
            tableWidget->removeRow(i);
        }
    }
    update();
}

void BasicControlUse::SlotClicked(QTreeWidgetItem *item, int column)
{
    for(int i = 0; i < item->childCount(); i++) {
        QTreeWidgetItem * pChildItem = item->child(i);
        pChildItem->setCheckState(0, item->checkState(0));
    }
}

