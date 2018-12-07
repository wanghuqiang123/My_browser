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
	//根据tabwidget来变化窗口大小
	webview->resize(this->size());
}

webTabWidget::~webTabWidget()
{

}
