#include "webTabWidget.h"

webTabWidget::webTabWidget(QWidget* parent):QTabWidget(parent)
{
	initTabWidget();
	setTabsClosable(true);

	_addTabButton();  
	setProfile();
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
	setWebPage(webview);			//设置网页的配置文件，cookie等
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

bool webTabWidget::setProfile()
{
	bool ret = true;
	this->m_profile = QWebEngineProfile::defaultProfile();
	if (m_profile != NULL)
	{   //默认cookie为临时会话，短暂存储
		m_profile->setPersistentCookiesPolicy(QWebEngineProfile::NoPersistentCookies);
		//设置cookie的文件的存放路径
		m_profile->setPersistentStoragePath("C:\\Qt\\QT_file\\VS_Qt\\My_browser\\profile");
		//使用内存缓存类型来存储浏览过的网页信息，默认情况下是硬盘存储，一直保留，但是这是测试代码，因此用内存缓存即可
		m_profile->setHttpCacheType(QWebEngineProfile::MemoryHttpCache);
	}
	else
	{
		ret = false;
	}
	return ret;
}

bool webTabWidget::setWebPage(WebView* webview)
{
	bool ret = true;
	QWebEnginePage* page = new QWebEnginePage(m_profile,webview);
	if (page != NULL)
	{
		webview->setPage(page);
	}
	else
	{
		ret = false;
	}
	return ret;
}

void webTabWidget::clearCookie(bool)
{
	//清除所有的cookie记录
	m_profile->cookieStore()->deleteAllCookies();
	//清除浏览器所有的历史记录
	//m_profile->clearAllVisitedLinks();
}
webTabWidget::~webTabWidget()
{
	
}
