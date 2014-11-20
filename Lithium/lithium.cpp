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
    QFileDialog *diag = new QFileDialog(this,tr("Open..."),currentDir,tr("Macsin Files (*.mc *.dat);;All Files (*.*)"));
    QStringList fileNames("");
    if(!(fileNames = diag->getOpenFileNames(this,tr("Open..."),currentDir,tr("Macsin Files (*.mc *.dat);;All Files (*.*)"))).empty())
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
    this->open(path);
    iztp.setPattern("  (\d{3,4})+");
    cncr.setPattern("  (\S+e[+-]\S{2})+");
}

void MacsinFile::open(QString path)
{
    pth=path;
    if(pth.size())
    {
        if(!QFile::copy(pth,pth+".bck"))
        {
            QFile::remove(pth+".bck");
            QFile::copy(pth,pth+".bck");
        }
        fileIn.setFileName(pth+".bck");
        fileIn.open(QIODevice::Text|QIODevice::ReadOnly);
        in.setDevice(&fileIn);
        fileOut.setFileName(pth);
        fileOut.open(QIODevice::Text|QIODevice::Truncate|QIODevice::WriteOnly);
        out.setDevice(&fileOut);
    }
}

MacsinFile::~MacsinFile()
{
    fileIn.close();
    fileOut.close();
}

void MacsinFile::add(int number, float conc)
{
    QString line;
    int c=0;
    bool mat=false;
    bool add=false;
    QRegularExpressionMatchIterator remi;
    while(!in.atEnd())
    {
        c++;
        line = in.readLine();
        if(c>5)
        {
            if((remi=iztp.globalMatch(line)).next().hasMatch())
            {
                mat=true;
            }

        }
        if(!line.isEmpty()) out<<line<<endl;
    }

}

void MacsinFile::remove(int number)
{

}
