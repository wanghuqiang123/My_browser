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
private:
	/*struct history_struct
	{
		QString title;
		QUrl url;
		/*history_struct(const history_struct& rhs)
		{
			title = rhs.title;
			url = rhs.url;
		}

		 history_struct(const QUrl& u)
		{
			url = u;
		}
		 history_struct(const QString& s, const QUrl& u)
		{
			title = s;
			url = u;
		}
		history_struct& operator=(const history_struct& rhs)
		{
			title = rhs.title;
			url = rhs.url;
		}

		bool operator==(const history_struct& rhs)
		{
			bool ret = true;
			if ( url != rhs.url)
			{
				ret = false;
			}
			return ret;
		}
	};*/
	HistoryAction* makeHistoryAction(QString& );
	QMap<QString,QUrl> historys_data;
	QWebEngineHistory* m_history;
	
};

