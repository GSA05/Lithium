#include "lithium.h"
#include <QFileDialog>

//Lithium
Lithium::Lithium(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    currentDir = QString();
    ui.listView->setModel(&list);

    uiDialog.setupUi(&tempDialog);
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
        ui.tempButton->setEnabled(true);
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

void Lithium::on_tempButton_clicked()
{
    if(tempDialog.exec())
    {
        for(int i = 0; i <= list.rowCount(); i++)
        {
            MacsinFile mc(list.data(list.index(i,0),0).toString());
            mc.changeTemp(uiDialog.tempEdit->text().toFloat(),uiDialog.checkBox->isChecked() ? "*" : uiDialog.izotEdit->text());
        }
    }
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
    QDir dir("./bck");
    QString name = QFileInfo(pth).fileName();
    if(pth.size())
    {
        if(!dir.exists())
        {
            QDir::current().mkdir("bck");
        }
        if(!QFile::copy(pth,dir.absoluteFilePath(name)))
        {
            QFile::remove(dir.absoluteFilePath(name));
            QFile::copy(pth,dir.absoluteFilePath(name));
        }
        fileIn.setFileName(dir.absoluteFilePath(name));
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


void MacsinFile::changeTemp(float temp, QString pattern)
{
    QString line,lineBefore;
    int c = 0;
    int i = 0;
    int n = 0;
    bool change = false;
    if(pattern == "*")
    {
        while(!in.atEnd())
        {
            c++;
            lineBefore = line;
            line = in.readLine();
            if(c>5)
            {
                if(change)
                {
                    i++;
                    if(i == n)
                    {
                        line.replace(1,12,QString("%1").arg(temp,12,'e',5));
                        i = 0;
                        change = false;
                    }
                }
                if(!change && QRegularExpression(" ( \\d{3,4})+").match(line).hasMatch())
                {
                    change = true;
                    n = 3 + (lineBefore.mid(5,3).trimmed().toInt() > 0 ? 1 : 0) * 2;
                }
            }
            if(!line.isEmpty()) out<<line<<endl;
        }
    }
    else
    {

    }
}
