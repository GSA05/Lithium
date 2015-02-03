#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    projectExplorer(new QStandardItemModel)
{
    ui->setupUi(this);
    QStandardItem *parentItem = projectExplorer->invisibleRootItem();
    QStandardItem *item = new QStandardItem(QString("Материалы"));
    item->setIcon(QIcon(":/icons/Materials.bmp"));
    item->setEditable(false);
    parentItem->appendRow(item);
    item = new QStandardItem(QString("Ячейки"));
    item->setIcon(QIcon(":/icons/Cells.bmp"));
    item->setEditable(false);
    parentItem->appendRow(item);
    item = new QStandardItem(QString("Геометрия"));
    item->setEditable(false);
    parentItem->appendRow(item);
    item = new QStandardItem(QString("Параметры"));
    item->setEditable(false);
    parentItem->appendRow(item);
    ui->treeView->setModel(projectExplorer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
