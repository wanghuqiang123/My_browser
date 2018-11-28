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
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>
#include <QProgressBar>
#include <QDockWidget>
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
	QToolBar* tb;
	QLineEdit* line;
	QProgressBar* PB;
	/*method*/
	My_browser(QWidget* parent = nullptr);
	void resizeEvent(QResizeEvent* event);

	bool constrcut();

	bool initToolBar();
	bool initToolBarItem(QToolBar* );
	bool makeToolBatItem(QPushButton*&,QHBoxLayout*,QString);

	bool initProgressBar(QVBoxLayout*);

	bool initWebEngView();
/*protected:
	bool eventFilter(QObject* target, QEvent* event);ÊÂ¼þ¹ýÂË
*/

protected slots:
	/*slot function*/
	void on_backButton_click();
	void on_forwardButton_click();
	void on_refreshButton_click();
	void on_goButton_click();
	void on_goButtomBtn_click();
	void webviewLoding(int);
};
