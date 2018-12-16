#include "mainwindow.h"

My_browser::My_browser(QWidget* parent):QMainWindow(parent)
{
	resize(1000, 600);
	setWindowTitle("Browser");
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
	
	//ret = ret && initWebEngView();
	ret = ret && initTab_webview();  //先初始化web页面
	ret = ret && initToolBar();
	
	return ret;
}
bool My_browser::initToolBar()
{
	bool ret = true;
	tb = new QToolBar("TopToolBar");

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
	//line->installEventFilter(this);  安装事件过滤器

	QWidget* w = new QWidget(tb);
	
	QVBoxLayout* VLayout = new QVBoxLayout(w);
	QHBoxLayout* layout = new QHBoxLayout(); //增加水平布局管理器

	if (line != NULL && w != NULL && layout != NULL && VLayout != NULL)
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
		connect(line, SIGNAL(returnPressed()), this, SLOT(on_goButton_click()));//当用户按下Enter键的时候

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
			initMenuItem(btn);
		}

		VLayout->addLayout(layout);//将水平布局管理器加入其中；

		ret = ret && initProgressBar(VLayout);//make ProgressBar
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

bool My_browser::initMenuItem(QPushButton* btn)
{
	QMenu* menu = new QMenu(btn);
	
	bool ret = (menu != NULL);
	if (ret)
	{
		QAction* action = NULL;
		
		ret = ret && initSubHistoryMenu(menu);
		if (ret)
		{
			menu->addSeparator();
		}

		ret = ret && initMoreToolMenu(menu);
		{
			menu->addSeparator();    //添加一个分隔器
		}

		//退出选项
		ret = ret && makeAction(action, menu, "Exit(E)", Qt::CTRL + Qt::SHIFT + Qt::Key_Q);
		if (ret)
		{
			connect(action, SIGNAL(triggered(bool)), this, SLOT(browser_exit()));
			menu->addAction(action);
		}
		//此选项用于触发测试，正式发布请删除
		/****************************/
			ret = ret && makeAction(action, menu, "test js", 0);
			if (ret)
			{
				connect(action, &QAction::triggered, [this]() {
					//m_currenttab->current_widget()->page()->runJavaScript("myFunction()");
					//谨慎使用，因为有时候javascript的代码会造成应用程序的阻塞？
				});
				menu->addAction(action);
			}
		/*****************************/
	}
	if (ret)
	{
		btn->setMenu(menu);
	}
	else
	{
		delete menu;
	}
	return ret;
}

bool My_browser::initSubHistoryMenu(QMenu* menu)
{
	bool ret = true;
	
	m_history = new History();
	menu->addMenu(m_history);
	//接受来自action点击后传来的url，传给槽函数
	connect(m_history, SIGNAL(SendToMainUrl(const QUrl)), this, SLOT(recive_url_fromhistory(const QUrl)));

	return ret;
}

bool My_browser::initMoreToolMenu(QMenu* parent)
{
	bool ret = true;
	QMenu* menu = new QMenu();
	QAction* action = NULL;
	if (menu != NULL)
	{
		menu->setTitle("More Tool");
		
		ret = ret && makeAction(action, menu, "clear all cookie", 0);
		if (ret)
		{
			connect(action, SIGNAL(triggered(bool)),m_currenttab,SLOT(clearCookie()));
			menu->addAction(action);
		}
	}
	else
	{
		ret = false;
		delete menu;
	}
	if (ret)
	{
		parent->addMenu(menu);
	}
	return ret;
}
bool My_browser::initProgressBar(QVBoxLayout* layout)
{
	bool ret = true;

	if (layout != NULL)
	{
		PB = new QProgressBar();
		if (PB != NULL)
		{
			PB->setMaximumHeight(10);
			PB->setVisible(false);
			//当加载，进度条显示；这里用的lambda表达式，完成后就隐藏
			connect(m_currenttab, &webTabWidget::startload, [this]() {PB->show(); });
			layout->addWidget(PB);
		}
		else
		{
			ret = false;
		}
	}
	else
	{
		ret = false;
	}

	return ret;
}
//bool My_browser::initWebEngView()
//{
//	bool ret = true;
//
//	webview = new WebView(this);//此处指针this父类也可以
//	if (webview != NULL)
//	{
//		setCentralWidget(webview);    //关键步骤
//	
//		connect(webview, SIGNAL(loadProgress(int)),this,SLOT(webviewLoding (int)));
//		connect(webview, SIGNAL(loadProgress(int)), this, SLOT(webview_History()));
//		
//		webview->load(QUrl("http://www.baidu.com"));//试验作用
//	}
//	else
//	{
//		ret = false;
//	}
//
//	return ret;
//}
bool My_browser::initTab_webview()
{
	bool ret = true;
	webTabWidget* tab = new webTabWidget();
	if (tab && (tab->createTabWebView() != nullptr))  //启动程序初始化打开打开一个网络页面
	{
		m_currenttab = tab;
		setCentralWidget(tab);
		if(m_currenttab != NULL){
			connect(m_currenttab, SIGNAL(loadpressnum(int)), this, SLOT(webviewLoding(int)));
			connect(m_currenttab, SIGNAL(currentUrl(QUrl&)), this,SLOT(setlinetext(QUrl)));  //将文本框中的网址显示为真实网址
			connect(m_currenttab, SIGNAL(CloseSingal()), this, SLOT(browser_exit()));
			connect(m_currenttab, SIGNAL(send_Title_url(QString,QUrl)), this, SLOT(webview_History(QString,QUrl)));
		}
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

bool My_browser::makeAction(QAction*& action, QWidget* parent, QString text, int key)
{
	bool ret = true;

	action = new QAction(text, parent);

	if (action != NULL)
	{
		action->setShortcut(QKeySequence(key));
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
	 m_currenttab->currentWidget()->resize(this->centralWidget()->size());
}

/*bool My_browser::eventFilter(QObject* target, QEvent* event)
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
}*/
My_browser::~My_browser()
{

}