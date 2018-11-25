#include <webview.h>

WebView::WebView(QWidget* parent):QWebEngineView(parent)
{

}

QWebEngineView* WebView::createWindow(QWebEnginePage::WebWindowType type)
{
	Q_UNUSED(type)

	return this;
}