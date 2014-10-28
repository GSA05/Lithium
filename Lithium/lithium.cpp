#include "lithium.h"
#include <QFileDialog>

Lithium::Lithium(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Lithium::~Lithium()
{

}

void Lithium::on_openAction_triggered()
{
    QFileDialog *diag = new QFileDialog(this,tr("Открыть..."));
    diag->exec();
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
