#include "webTabWidget.h"

webTabWidget::webTabWidget(QWidget* parent):QTabWidget(parent)
{
	initTabWidget();
	setTabsClosable(true);

	_addTabButton();  
	//����ͷ��ǩ�ĳߴ�
	setStyleSheet("QTabBar::tab{width:180px;height:30px}");//��ʽ��
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
		emit currentUrl(m_webview[index]->url());//ÿ�л�һ��ҳ�棬�Ͱ���ַ���е���ַ����Ϊ��ǰҳ�����ַ
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
	webview->setWindowPoint(this);   //��tabwidget��ָ�봫����ǰwebview�ڴ��еı���
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
		int index = m_webview.indexOf(webview);//���ڵ�webview���������ĸ�λ�ã���Ӧ���±�
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
	setCornerWidget(tb);   //��tabwidget�����Ͻ�����QPushButton
	connect(tb, &QAbstractButton::clicked, [this](bool) {
		createTabWebView();
	});   //�������µ�ʱ�����һ����web��ǩҳ
}

webTabWidget::~webTabWidget()
{
}
