#ifndef LITHIUM_H
#define LITHIUM_H

#include <QtWidgets/QMainWindow>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
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
    void open(QString path); // открывает файл
    void close(); // закрывает файл
    void add(int number, float conc); // добавляет изотоп в материалы с заданной концентрацией
    void remove(int number); // убирает изотоп из материалов

private:
    QString pth;
    QFile fileIn,fileOut;
    QTextStream in,out;
    QRegularExpression iztp,cncr,iztp_add;
};

#endif // LITHIUM_H
