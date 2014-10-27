#ifndef LITHIUM_H
#define LITHIUM_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "ui_lithium.h"

class Lithium : public QMainWindow
{
	Q_OBJECT

public:
	Lithium(QWidget *parent = 0);
	~Lithium();

private:
	Ui::LithiumClass ui;
};

#endif // LITHIUM_H
