#include "History.h"

History::History(QMenu* parent)
		:QMenu(parent)
		,m_history(NULL)
{
	setTitle("History");
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

void History::resetActions()
{
	if (historys_data.find(m_history->currentItem().title()) == historys_data.end())
	{
		addAction(m_history->currentItem().title());
		historys_data.insert(m_history->currentItem().title());
	}
}

History::~History()
{
	
}
