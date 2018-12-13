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
#include <QWebEngineProfile>
#include <QWebEngineCookieStore>
#include <QPushButton>
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
public slots:
	void clearCookie(bool);
private:
	QVector<WebView*>m_webview;
	QWebEngineProfile* m_profile;
	bool setup_webview(WebView*);
	bool setProfile();
	bool setWebPage(WebView*);
	void initTabWidget();
	void _addTabButton();
};

