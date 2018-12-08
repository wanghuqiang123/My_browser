#pragma once
#include <QTabWidget>
#include <QEvent>
#include <QUrl>
#include <QString>
#include <QVector>
#include <QIcon>
#include <QTabBar>
#include "webview.h"

class WebView;
class webTabWidget :public QTabWidget
{
	Q_OBJECT
public:
	webTabWidget(QWidget* parent = nullptr);

	WebView* createTabWebView();

	virtual ~webTabWidget();
signals:
	void loadpressnum(int);
	void loadfinished();
	void startload();
private:
	QVector<WebView*>m_webview;
	bool setup_webview(WebView*);
	void initTabWidget();
};

