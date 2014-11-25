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
    iztp.setPattern(" \\d{3,4}");
    cncr.setPattern("  (\\S+e[+-]\\S{2})+");
}

void MacsinFile::open(QString path)
{
    pth = path;
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
    int c = 0;
    int i = 0;
    bool nw = false;
    int add = 0;
    iztp_add.setPattern(QString(number));
    QRegularExpressionMatch temp;
    QRegularExpressionMatchIterator remi;
    QRegularExpressionMatch remid;
    while(!in.atEnd())
    {
        c++;
        line = in.readLine();
        if(c>5)
        {
            if(add)
            {
                if(nw)
                {
                    line.append(QString("%1").arg(conc,12,'e',5));
                }
                else
                {
                    line.replace((add-1)*12+1,12,QString("%1").arg(conc,12,'e',5));
                }
                add = 0;
            }
            temp = QRegularExpression(" ( \\d{3,4})+").match(line);
            if((remi = iztp.globalMatch(temp.captured(0))).hasNext())
            {
                //QStringList t = remi.capturedTexts();
                i = 0;
                while(remi.hasNext())
                {
                    i++;
                    if(remi.next().captured(0).trimmed() == QString(number))
                    {
                        add = i;
                        nw = false;
                        break;
                    }
                }
                if(!add)
                {
                    line += QString("%1").arg(number,5);
                    add = i + 1;
                    nw = true;
                }
            }
        }
        if(!line.isEmpty()) out<<line<<endl;
    }

}

void MacsinFile::remove(int number)
{

}
