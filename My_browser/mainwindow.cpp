#include "mainwindow.h"

My_browser::My_browser(QWidget* parent):QMainWindow(parent)
{
	resize(1200, 600);
}

My_browser* My_browser::NewInstance()
{
	My_browser* instance = new My_browser();

	if ((instance == NULL) || !instance->constrcut())
	{
		delete instance;
		instance = NULL;
	}
	
	return instance;
}

bool My_browser::constrcut()
{
	bool ret = true;
	
	ret = ret && initMenuBar();
	ret = ret && initWebEngView();

	return ret;
}
bool My_browser::initMenuBar()
{
	bool ret = true;
	
	QMenuBar* mb = menuBar();
	
	ret = ret && initOptionMenu(mb);

	return ret;
}

bool My_browser::initOptionMenu(QMenuBar* mb)
{
	QMenu* menu = new QMenu("opetion", mb);
	bool ret = (menu != NULL);

	if (ret)
	{
		QAction* action = NULL;

		ret = ret && makeAction(action, menu, "quit", 0);
		if (ret)
		{
			menu->addAction(action);
		}
	}

	if (ret)
	{
		mb->addMenu(menu);

	}
	else
	{
		delete menu;
	}

	return ret;
}

bool My_browser::initWebEngView()
{
	bool ret = true;

	webview = new WebView(this);
	webview->load(QUrl("http://www.baidu.com"));
	setCentralWidget(webview);    //¹Ø¼ü²½Öè

	return ret;
}


bool My_browser::makeAction(QAction*& action, QWidget* parent, QString text, int short_key)
{
	bool ret = true;

	action = new QAction(text, parent);

	if (action != NULL)
	{
		action->setShortcut(QKeySequence(short_key));
	}
	else
	{
		ret = false;
	}

	return ret;
}
void My_browser::resizeEvent(QResizeEvent* event)
{
	//webview->resize(this->size().width(),this->size().height()-50);
	webview->resize(this->centralWidget()->size());
}

My_browser::~My_browser()
{
	delete webview;
	delete mb;
}