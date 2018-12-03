#pragma once
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QListWidget>
#include <QSet>
#include <QWebEngineHistoryItem> 
#include <QWebEngineHistory>
#include <QString>
//目前的方案是只能继承自QAction
class History :public QMenu
{
	//Q_OBJECT
public:
	explicit History(QMenu* parent = NULL);
	
	bool setHistoryPoint(QWebEngineHistory* p);
	void resetActions();

	~History();
private:
	QSet<QString> historys_data;
	QWebEngineHistory* m_history;
	
};

