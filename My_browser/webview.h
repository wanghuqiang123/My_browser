#pragma once
#include <QWebEngineView>
#include <QWebEngineProfile>
#include "webTabWidget.h"

class webTabWidget;
class WebView :public QWebEngineView
{
	Q_OBJECT
public:
	WebView(QWidget* parent = nullptr);

	void setWindowPoint(webTabWidget* p);
protected:
	webTabWidget* tabwidget;
	QWebEngineView* createWindow(QWebEnginePage::WebWindowType type);
}; 