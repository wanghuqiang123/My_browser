#include "webTabWidget.h"

webTabWidget::webTabWidget(QWidget* parent):QTabWidget(parent)
{

}

WebView* webTabWidget::createTabWebView()
{
	webview = new WebView();
	setCurrentWidget(webview);
}

void webTabWidget::resizeEvent(QResizeEvent* e)
{
	//����tabwidget���仯���ڴ�С
	webview->resize(this->size());
}

webTabWidget::~webTabWidget()
{

}
