#ifndef LITHIUM_H
#define LITHIUM_H

#include <QtWidgets/QMainWindow>
#include <QStringListModel>
#include <QFileInfo>
#include <QTextStream>
#include <QRegularExpression>
#include "ui_lithium.h"
#include "tempdialog.h"

class Lithium : public QMainWindow
{
	Q_OBJECT

public:
	Lithium(QWidget *parent = 0);
	~Lithium();
    static void makeBackup(QFileInfo path);

private slots:
    void on_openAction_triggered();
    void on_quitAction_triggered();
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_tempButton_clicked();

private:
	Ui::LithiumClass ui;
    tempDialog tempDlg;
    QString currentDir;
    QStringListModel list;
};

#endif // LITHIUM_H
