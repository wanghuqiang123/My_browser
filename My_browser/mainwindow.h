#pragma once

#include <QMainWindow>
#include <QWebEngineView>
#include <QAction>
#include <QMenuBar>
#include <QUrl>
#include <QMenu>
#include <QTabWidget>
#include <QMap>
#include <QString>
#include <QVBoxLayout>
#include <webview.h>

class My_browser : public QMainWindow
{
	Q_OBJECT

public:
	static My_browser* NewInstance();
	~My_browser();

private:
	/*data memory*/
	WebView* webview;
	QMenuBar* mb;
	/*method*/
	My_browser(QWidget* parent = nullptr);
	void resizeEvent(QResizeEvent* event);

	bool constrcut();
	bool initMenuBar();
	bool initOptionMenu(QMenuBar*);
	bool makeAction(QAction*& , QWidget* , QString t, int );

	bool initWebEngView();


};
