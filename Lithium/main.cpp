#include "lithium.h"
#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lithium w;
    MainWindow m;
    //w.show();
    m.show();
	return a.exec();
}
