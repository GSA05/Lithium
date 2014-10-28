#include "lithium.h"
#include <QFileDialog>

//Lithium
Lithium::Lithium(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    currentDir = QString();
}

Lithium::~Lithium()
{

}

void Lithium::on_openAction_triggered()
{
    QFileDialog *diag = new QFileDialog(this,tr("Open..."),QString(),tr("Macsec Files (*.mc);;All Files (*.*)"));
    QStringList fileNames;
    if(diag->exec())
    {
        fileNames = diag->selectedFiles();
        currentDir = diag->directory().currentPath();
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

//MacsecFile
MacsecFile::MacsecFile(QString path)
{
    pth=path;
}
