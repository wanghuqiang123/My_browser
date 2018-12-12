#include "webTabWidget.h"

webTabWidget::webTabWidget(QWidget* parent):QTabWidget(parent)
{
	initTabWidget();
	setTabsClosable(true);

	_addTabButton();  
	//设置头标签的尺寸
	setStyleSheet("QTabBar::tab{width:180px;height:30px}");//样式表
}

void webTabWidget::initTabWidget()
{
	connect(this, &QTabWidget::tabCloseRequested, [this](int index) {
		removeTab(index); 
		delete m_webview[index]; 
		m_webview.remove(index); 
		emit loadpressnum(100);
		if (m_webview.size() == 0) {
			emit CloseSingal();  //if no one webview,emit a close signal to mainwindow to close;
		}
	});
	connect(this, &QTabWidget::tabBarClicked, [this](int index) {
		emit currentUrl(m_webview[index]->url());//每切换一个页面，就把网址框中的网址设置为当前页面的网址
	});
	
}
WebView* webTabWidget::createTabWebView()
{
	WebView* webview = new WebView();
	if (webview != NULL)
	{
		addTab(webview,"New Tab");
		setCurrentWidget(webview);

		m_webview.push_back(webview);
		setup_webview(webview);
	}
	return webview;
}

bool webTabWidget::setup_webview(WebView* webview)
{
	bool ret = true;
	webview->setWindowPoint(this);   //把tabwidget的指针传给当前webview内存中的变量
	connect(webview, &QWebEngineView::loadProgress, [this,webview](int progress) {
		emit loadpressnum(progress); 
		emit currentUrl(webview->url());
	});
	connect(webview, &QWebEngineView::iconChanged, [this, webview]() {
		int index = m_webview.indexOf(webview);	
		setTabIcon(index, webview->icon());	//set currentWidgetTab webview icon
	});
	connect(webview, &QWebEngineView::loadFinished, [this,webview](bool ok){	
		if (ok) { 
		int index = m_webview.indexOf(webview);//现在的webview在容器的哪个位置；对应的下标
		setTabText(index, webview->title());//set currentWidgetTab webview title
		}	
	});
	connect(webview, &QWebEngineView::loadStarted, [this]() {
		emit startload(); 
	});
	connect(webview, &QWebEngineView::titleChanged, [this, webview](const QString&) {
		emit send_Title_url(webview->page()->history()->currentItem().title()
			, webview->page()->history()->currentItem().url());
	});
	return ret;
}
WebView* webTabWidget::currrnt_widget()
{
	return m_webview[currentIndex()];
}

void webTabWidget::_addTabButton()
{
	QPushButton* tb = new QPushButton();
	tb->setText("+");
	setCornerWidget(tb);   //在tabwidget的右上角设置QPushButton
	connect(tb, &QAbstractButton::clicked, [this](bool) {
		createTabWebView();
	});   //当被按下的时候添加一个空web标签页
}

webTabWidget::~webTabWidget()
{
}
