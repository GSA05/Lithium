#include "lithium.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lithium w;
	w.show();
	return a.exec();
}
