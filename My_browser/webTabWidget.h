#pragma once
#include <QTabWidget>
#include <QEvent>
#include "webview.h"

class webTabWidget :public QTabWidget
{
public:
	webTabWidget(QWidget* parent = nullptr);

	virtual ~webTabWidget();

private:
	WebView* webview;

	WebView* createTabWebView();

	inline void resizeEvent(QResizeEvent* e);
};

