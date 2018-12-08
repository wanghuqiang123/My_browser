#include "webTabWidget.h"

webTabWidget::webTabWidget(QWidget* parent):QTabWidget(parent)
{
	//initTabWidget();
	setTabsClosable(true);

	//设置头标签的尺寸
	setStyleSheet("QTabBar::tab{width:200px;height:22px}");
}

void webTabWidget::initTabWidget()
{
	connect(this, &QTabWidget::tabCloseRequested, [this](int index) 
		{removeTab(index); delete m_webview[index]; m_webview.remove(index); 
	});
}
bool webTabWidget::createTabWebView()
{
	bool ret = true;
	WebView* webview = new WebView();
	if (webview != NULL)
	{
		addTab(webview,"loading...");
		m_webview.push_back(webview);
		setup_webview(webview);
		webview->load(QUrl("http://www.baidu.com"));
	}
	else
	{
		ret = false;
	}
	return ret;
}

bool webTabWidget::setup_webview(WebView* webview)
{
	bool ret = true;
	
	connect(webview, &QWebEngineView::loadProgress, [this](int progress) 
			{emit loadpressnum(progress); }
	);

	connect(webview, &QWebEngineView::iconChanged, [this, webview]() {
		int index = currentIndex();	//set currentWidgetTab webview icon
		setTabIcon(index, webview->icon()); 
	});
	connect(webview, &QWebEngineView::loadFinished, [this,webview](bool ok){	
		if (ok) { 
		int index = currentIndex();
		setTabText(index, webview->title());//set currentWidgetTab webview title
		emit loadfinished();
		}	}
	);
	connect(webview, &QWebEngineView::loadStarted, [this]() 
		{emit startload(); 
	});
	return ret;
}
webTabWidget::~webTabWidget()
{

}
