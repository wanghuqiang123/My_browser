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
#include <QToolBar>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
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
	QToolBar* tb;
	QLineEdit* line;
	/*method*/
	My_browser(QWidget* parent = nullptr);
	void resizeEvent(QResizeEvent* event);

	bool constrcut();
	bool initMenuBar();
	bool initOptionMenu(QMenuBar*);

	bool initToolBar();
	bool initToolBarItem(QToolBar* );
	bool makeToolBatItem(QPushButton*&,QHBoxLayout*,QString);

	bool makeAction(QAction*& , QWidget* , QString , int );

	bool initWebEngView();
protected slots:
	/*slot function*/
	void on_backButton_click();
	void on_forwardButton_click();
	void on_refreshButton_click();
	void on_goButton_click();
};
