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
	
	ret = ret && initToolBar();
	ret = ret && initWebEngView();

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
	//line->installEventFilter(this);  ��װ�¼�������

	QWidget* w = new QWidget(tb);
	
	QVBoxLayout* VLayout = new QVBoxLayout(w);
	QHBoxLayout* layout = new QHBoxLayout(); //����ˮƽ���ֹ�����

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

		layout->addWidget(line);  //����������ı������������ַʹ��
		connect(line, SIGNAL(returnPressed()), this, SLOT(on_goButton_click()));//���û�����Enter����ʱ��

		ret = ret && makeToolBatItem(btn, layout, ""); 
		//�����е����⣬��Ϊ�����캯����ȥ�����˰�ť��tip��ʾ���������������¸�һ���ı��ڰ�ť����ʾ
		if (ret)
		{
			btn->setText("Go");
			connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_goButton_click()));
		}

		//�����ذ�ť�Ĺ�������ʾ�����ص����� �Ĵ��ڣ����ڶ�Ӧ���ۺ�����ûʵ��
		ret = ret && makeToolBatItem(btn, layout, ":/My_browser/Icon/go-bottom.png");
		if (ret)
		{
			connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_goButtomBtn_click()));
		}

		VLayout->addLayout(layout);//��ˮƽ���ֹ������������У�

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

bool My_browser::initProgressBar(QVBoxLayout* layout)
{
	bool ret = true;

	if (layout != NULL)
	{
		PB = new QProgressBar();
		if (PB != NULL)
		{
			PB->setMaximumHeight(10);

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

bool My_browser::initWebEngView()
{
	bool ret = true;

	webview = new WebView(this);//�˴�ָ��this����Ҳ����
	if (webview != NULL)
	{
		//webview->load(QUrl("http://www.baidu.com"));
		setCentralWidget(webview);    //�ؼ�����

		connect(webview, SIGNAL(loadProgress(int)),this,SLOT(webviewLoding(int)));
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