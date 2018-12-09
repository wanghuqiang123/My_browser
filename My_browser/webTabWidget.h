#pragma once
#include <QTabWidget>
#include <QEvent>
#include <QUrl>
#include <QString>
#include <QVector>
#include <QIcon>
#include <QTabBar>
#include <QWebEnginePage>
#include <QWebEngineHistory>
#include <QWebEngineHistoryItem>
#include "webview.h"

class WebView;
class webTabWidget :public QTabWidget
{
	Q_OBJECT
public:
	webTabWidget(QWidget* parent = nullptr);

	WebView* createTabWebView();
	WebView* currrnt_widget();

	virtual ~webTabWidget();
signals:
	void loadpressnum(int);
	void send_Title_url(QString&,QUrl&);
	void CloseSingal();
	void startload();
	void currentUrl(QUrl&);
private:
	QVector<WebView*>m_webview;
	bool setup_webview(WebView*);
	void initTabWidget();
};

