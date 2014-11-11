#ifndef LITHIUM_H
#define LITHIUM_H

#include <QtWidgets/QMainWindow>
#include <QStringListModel>
#include <QFile>
#include "ui_lithium.h"

class Lithium : public QMainWindow
{
	Q_OBJECT

public:
	Lithium(QWidget *parent = 0);
	~Lithium();

private slots:
    void on_openAction_triggered();
    void on_quitAction_triggered();
    void on_addButton_clicked();
    void on_removeButton_clicked();

private:
	Ui::LithiumClass ui;
    QString currentDir;
    QStringListModel list;
};

class MacsinFile
{
public:
    MacsinFile(QString path = "");
    ~MacsinFile();
    open(QString path);

private:
    QString pth;
    QFile file;
    QTextStream io;
};

#endif // LITHIUM_H
