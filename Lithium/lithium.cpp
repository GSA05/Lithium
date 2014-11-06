#include "lithium.h"
#include <QFileDialog>

//Lithium
Lithium::Lithium(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    currentDir = QString();
    ui.listView->setModel(&list);
}

Lithium::~Lithium()
{

}

void Lithium::on_openAction_triggered()
{
    QFileDialog *diag = new QFileDialog(this,tr("Open..."),currentDir,tr("Macsin Files (*.mc);;All Files (*.*)"));
    QStringList fileNames("");
    if(!(fileNames = diag->getOpenFileNames(this,tr("Open..."),currentDir,tr("Macsin Files (*.mc);;All Files (*.*)"))).empty())
    {
        currentDir = diag->directory().currentPath();
        list.setStringList(fileNames);
    }
}

void Lithium::on_quitAction_triggered()
{
    qApp->quit();
}

void Lithium::on_addButton_clicked()
{

}

void Lithium::on_removeButton_clicked()
{

}

//MacsinFile
MacsinFile::MacsinFile(QString path)
{
    pth=path;
}
