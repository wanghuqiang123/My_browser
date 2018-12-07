#pragma once
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QListWidget>
#include <QMap>
#include <QWebEngineHistoryItem> 
#include <QWebEngineHistory>
#include <QString>
#include <QUrl>
#include "HistoryAction.h"
//目前的方案是只能继承自QAction
class History :public QMenu
{
	Q_OBJECT
public:
	explicit History(QMenu* parent = NULL);
	
	bool setHistoryPoint(QWebEngineHistory* p);
	~History();

	void addHistoryAction();
signals:
	void SendToMainUrl(const QUrl& s);
protected slots:
	void ReciveUrlFromAction(const QString&);
	void ClearHisyory();
private:

	void makeClearAction();

	HistoryAction* makeHistoryAction(QString& );
	QMap<QString,QUrl> historys_data;
	QWebEngineHistory* m_history;
	
};

