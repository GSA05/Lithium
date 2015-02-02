#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    projectExplorer(new QStandardItemModel)
{
    ui->setupUi(this);
    QStandardItem *parentItem = projectExplorer->invisibleRootItem();
    QStandardItem *item1 = new QStandardItem(QString("Материалы"));
    item1->setIcon(QIcon(":/icons/Materials.bmp"));
    parentItem->appendRow(item1);
    QStandardItem *item2 = new QStandardItem(QString("Ячейки"));
    item2->setIcon(QIcon(":/icons/Cells.bmp"));
    parentItem->appendRow(item2);
    QStandardItem *item3 = new QStandardItem(QString("Геометрия"));
    parentItem->appendRow(item3);
    QStandardItem *item4 = new QStandardItem(QString("Параметры"));
    parentItem->appendRow(item4);
    ui->treeView->setModel(projectExplorer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
