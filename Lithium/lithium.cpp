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
    MacsinFile mc(list.data(list.index(0,0),0).toString());
    mc.add(1111,0);
}

void Lithium::on_removeButton_clicked()
{

}

//MacsinFile
MacsinFile::MacsinFile(QString path)
{
    pth=path;
    if(pth.size())
    {
        file.setFileName(pth);
        file.open(QIODevice::Text|QIODevice::ReadWrite);
        io.setDevice(&file);
    }
}

void MacsinFile::open(QString path)
{
    pth=path;
    if(pth.size())
    {
        file.setFileName(pth);
        file.open(QIODevice::Text|QIODevice::ReadWrite);
        io.setDevice(&file);
    }
}

MacsinFile::~MacsinFile()
{

}

void MacsinFile::add(int number, float conc)
{
    QString line;
    while(!io.atEnd())
    {
        line = io.readLine();
    }

}

void MacsinFile::remove(int number)
{

}
