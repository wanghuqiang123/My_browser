#include "History.h"


History::History(QMenu* parent)
	:QMenu(parent)
	, m_history(NULL)
{
	setTitle("History");
	makeClearAction();
}

bool History::setHistoryPoint(QWebEngineHistory* p)
{
	bool ret = true;
	ret = ret && (p != NULL);

	if (ret)
	{
		m_history = p;
	}

	return ret;
}

void History::addHistoryAction()
{
	if ( (historys_data.find((m_history->currentItem().title())) == historys_data.end()) && (m_history->currentItem().title() != ""))
	{
		HistoryAction* action = makeHistoryAction(m_history->currentItem().title());
		if (action != NULL)
		{
			addAction(action);
			connect(action,SIGNAL(SendUrl(const QString&)),this,SLOT(ReciveUrlFromAction(const QString&)));
			historys_data.insert(m_history->currentItem().title(), m_history->currentItem().url());
		}
	}
}

HistoryAction* History::makeHistoryAction(QString& s)
{
	HistoryAction* action = new HistoryAction();
	action->setText(s);
	return action;
}

void History::ReciveUrlFromAction(const QString& s)
{
	QUrl url = historys_data[s];
	emit SendToMainUrl(url);
}

void History::makeClearAction()
{
	QAction* action = addAction("Clear History");
	connect(action, SIGNAL(triggered(bool)), this, SLOT(ClearHisyory()));
}

void History::ClearHisyory()
{ //此函数的功能是清除历史记录；
	clear();		//清楚这之中的actionm
	makeClearAction();
	m_history->clear();		//清除web视图中的历史记录
	historys_data.clear();
}

History::~History()
{
	
}
