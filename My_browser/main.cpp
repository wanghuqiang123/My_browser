#include "mainwindow.h"
#include <QtWidgets/QApplication>

class QIcon;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/My_browser/Icon/AppLogoColor.png"));
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
