#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	My_browser* w = My_browser::NewInstance();
	
	int ret = -1;
	if (w != NULL)
	{
		w->show();
		ret = a.exec();
	}

	delete w;

	return ret;
}
