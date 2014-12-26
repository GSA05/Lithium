#include "lithium.h"
#include "unkmacsin.h"
#include <QFileDialog>
#include <QMessageBox>

//Lithium
Lithium::Lithium(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    currentDir = QString();
    ui.listView->setModel(&list);

    //uiTempDialog.setupUi(&tempDialog);
}

Lithium::~Lithium()
{

}

void Lithium::makeBackup(QFileInfo path)
{
    QDir dir(path.absoluteDir());
    QString name = path.fileName();
    if(path.isFile())
    {
        dir.mkdir("bck");
        dir.cd("bck");
        if(!QFile::copy(path.absoluteFilePath(),dir.absoluteFilePath(name)))
        {
            QFile::remove(dir.absoluteFilePath(name));
            QFile::copy(path.absoluteFilePath(),dir.absoluteFilePath(name));
        }
    }
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

}

void Lithium::on_removeButton_clicked()
{

}

void Lithium::on_tempButton_clicked()
{
    if(tempDlg.exec())
    {
        for(int i = 0; i < list.rowCount(); i++)
        {
            UNKMacsin mac;
            QString path = list.data(list.index(i,0),0).toString();
            makeBackup(QFileInfo(path));
            mac.load(QFileInfo(path));
            mac.changeTemp(tempDlg.getTemp());
            mac.save(QFileInfo(path));
        }
        QMessageBox::information(this,"Сообщение","Все файлы успешно изменены. Резервная копия файлов в папке bck.");
    }
}
