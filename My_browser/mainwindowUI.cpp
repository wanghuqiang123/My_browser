#include "mainwindow.h"

My_browser::My_browser(QWidget* parent):QMainWindow(parent)
{
	resize(1000, 600);
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
	ret = ret && initToolBar();
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
	QMenu* menu = new QMenu("Option", mb);
	bool ret = (menu != NULL);

	if (ret)
	{
		QAction* action = NULL;

		ret = ret && makeAction(action, menu, "Quit", 0);
		if (ret)
		{
			menu->addAction(action);
			connect(action, SIGNAL(triggered(bool)), this, SLOT(onQuitSlot()));
		}
	}

	/**/
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

bool My_browser::initToolBar()
{
	bool ret = true;
	tb = new QToolBar();

	if (tb == NULL || !initToolBarItem(tb))
	{
		delete tb;
		ret = false;
	}
	else
	{
		addToolBar(Qt::TopToolBarArea, tb);
	}
	return ret;
}

bool My_browser::initToolBarItem(QToolBar* tb)
{
	bool ret = true;

	line = new QLineEdit(this);
	line->installEventFilter(this);

	QWidget* w = new QWidget(tb);
	QHBoxLayout* layout = new QHBoxLayout(w); //增加水平布局管理器

	if (line != NULL && w != NULL && layout != NULL)
	{
		QPushButton* btn = NULL;

		ret = ret && makeToolBatItem(btn,layout,":/My_browser/Icon/go-previous.png");
		if(ret)
		{
			connect(btn, SIGNAL(clicked(bool)), this,SLOT(on_backButton_click()));
		}

		ret = ret && makeToolBatItem(btn, layout, ":/My_browser/Icon/go-next.png");
		if(ret)
		{
			connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_forwardButton_click()));
		}

		ret = ret && makeToolBatItem(btn, layout, ":/My_browser/Icon/view-refresh.png");
		if (ret)
		{
			connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_refreshButton_click()));
		}

		layout->addWidget(line);  //在这里加入文本框，用于输入地址使用

		ret = ret && makeToolBatItem(btn, layout, ""); 
		//这里有点特殊，因为在制造函数中去掉了了按钮的tip标示，所以在下面重新附一个文本在按钮上显示
		if (ret)
		{
			btn->setText("Go");
			connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_goButton_click()));
		}

		//此下载按钮的功能是显示出下载的内容 的窗口，现在对应带槽函数还没实现
		ret = ret && makeToolBatItem(btn, layout, ":/My_browser/Icon/go-bottom.png");
		if (ret)
		{
			connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_goButtomBtn_click()));
		}

		if(ret)
		{
			
			tb->addWidget(w);
		}
	}
	else
	{
		ret = false;
	}
	return ret;
}

bool My_browser::initWebEngView()
{
	bool ret = true;

	webview = new WebView(this);//此处指针this父类也可以
	if (webview != NULL)
	{
		//webview->load(QUrl("http://www.baidu.com"));
		setCentralWidget(webview);    //关键步骤
	}
	else
	{
		ret = false;
	}

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

bool My_browser::makeToolBatItem(QPushButton*& btn,QHBoxLayout* layout , QString Icon)
{
	bool ret = true;

	btn = new QPushButton();

    if(btn != NULL)
    {
        btn->setIcon(QIcon(Icon));
		layout->addWidget(btn);
    }
    else
    {
        ret = false;
    }

	return ret;
}
//这里很重要，因为webview显示的网页默认大小，必须在这里让网页大小和窗口大小一致，不然会出bug
void My_browser::resizeEvent(QResizeEvent* event)
{
	webview->resize(this->centralWidget()->size());
}

bool My_browser::eventFilter(QObject* target, QEvent* event)
{
	if (target == this->line)
	{
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent *k = dynamic_cast<QKeyEvent *>(event);
			if (k->key() == Qt::Key_Return)
			{
				on_goButton_click();
				return true;
			}
		}
	}

	return QMainWindow::eventFilter(target, event);
}

My_browser::~My_browser()
{

}