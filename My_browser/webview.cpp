#include <webview.h>

WebView::WebView(QWidget* parent):QWebEngineView(parent)
{

}



QWebEngineView* WebView::createWindow(QWebEnginePage::WebWindowType type)
{
	switch (type){
	case QWebEnginePage::WebBrowserTab: {
		return tabwidget->createTabWebView();
	}
	}
	return this;
}

void WebView::setWindowPoint(webTabWidget* p)
{
	tabwidget = p;
}