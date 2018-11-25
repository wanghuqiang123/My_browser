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
	QWidget* w = new QWidget(tb);
	QHBoxLayout* layout = new QHBoxLayout(w); //����ˮƽ���ֹ�����

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

		layout->addWidget(line);  //����������ı������������ַʹ��

		ret = ret && makeToolBatItem(btn, layout, ""); 
		//�����е����⣬��Ϊ�����캯����ȥ�����˰�ť��tip��ʾ���������������¸�һ���ı��ڰ�ť����ʾ
		if (ret)
		{
			btn->setText("Go");
			connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_goButton_click()));
		}

		ret = ret && makeToolBatItem(btn, layout, ":/My_browser/Icon/go-bottom.png");
		if (ret)
		{
			
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

	webview = new WebView(this);
	if (webview != NULL)
	{
		webview->load(QUrl("http://www.baidu.com"));
		setCentralWidget(webview);    //�ؼ�����
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
//�������Ҫ����Ϊwebview��ʾ����ҳĬ�ϴ�С����������������ҳ��С�ʹ��ڴ�Сһ�£���Ȼ���bug
void My_browser::resizeEvent(QResizeEvent* event)
{
	webview->resize(this->centralWidget()->size());
}

My_browser::~My_browser()
{

}