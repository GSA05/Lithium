#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unkmacsin.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    projectExplorer(new UNKCase)
{
    ui->setupUi(this);

    QStandardItem *parentItem = new QStandardItem;
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
    projectExplorer->setRootItem(parentItem);
    ui->treeView->setModel(projectExplorer);

    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen(Qt::black);
    scene->addLine(0,90,180,90,pen);
    scene->addLine(90,0,90,180,pen);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openAction_triggered()
{
    QFileDialog *diag = new QFileDialog(this,tr("Открыть..."),QDir::current().dirName(),tr("Macsin файлы (*.mc *.dat);;Все файлы (*.*)"));
    QStringList fileNames("");
    if(!(fileNames = diag->getOpenFileNames(this,tr("Open..."),QDir::current().dirName(),tr("Macsin файлы (*.mc *.dat);;Все файлы (*.*)"))).empty())
    {
        //currentDir = diag->directory().currentPath();
        for(QStringList::iterator i = fileNames.begin(); i != fileNames.end(); ++i)
        {
            QStandardItem *item = new QStandardItem(*i);
            UNKMacsin *mac = new UNKMacsin;
            mac->load(QFileInfo(*i));
            //projectExplorer->findItems(QString("Ячейки")).first()->appendRow(item);
        }
    }
}
