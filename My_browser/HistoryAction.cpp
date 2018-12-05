#include "HistoryAction.h"

HistoryAction::HistoryAction(QWidget* parent):QAction(parent)
{
	connect(this, SIGNAL(triggered(bool)), this, SLOT(MousePress()));
}

//bool HistoryAction::event(QEvent* e)
//{
//	if (e->type() == QEvent::MouseButtonPress)
//	{
//		emit SendUrl(text());
//	}
//
//	return QAction::event(e);//这是直接调用父类中的event().
//}

void HistoryAction::MousePress()
{
	emit SendUrl(text());
}

HistoryAction::~HistoryAction()
{

}
