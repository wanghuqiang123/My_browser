#include <mainwindow.h>

void My_browser::on_backButton_click()
{
	m_currenttab->currrnt_widget()->back();
}

void My_browser::on_forwardButton_click()
{
	m_currenttab->currrnt_widget()->forward();
}

void My_browser::on_refreshButton_click()
{
	m_currenttab->currrnt_widget()->reload();
}

void My_browser::on_goButton_click()
{
	QString url = line->text();
	if (!url.startsWith("http://") && !url.startsWith("https://"))
	{
		url = "http://" + url;
	}
	m_currenttab->currrnt_widget()->load(QUrl(url));//在当前页面载入
}

void My_browser::webviewLoding(int progress)
{
	PB->setValue(progress);
	if (progress == 100)
	{
		PB->setVisible(false);
	}
}

/*void My_browser::webview_PagePrint()
{
	QPrintDialog dlg(this);    //弹出打印对话框
	dlg.setWindowTitle("Print");    //对话框标题

	if (dlg.exec() == QPrintDialog::Accepted)        //等待按下是否 选择是打印
	{
		QPrinter* p = dlg.printer();               //获取打印机对象

		//将编辑器中的内容传给打印机打印，第二个参数这里用到了lambda语法，因为在QWebEngine这里需要一个回调函数
		//m_currenttab->currrnt_widget()->page()->print(p, [=](bool ok) { });
	}
}*/

void My_browser::recive_url_fromhistory(const QUrl& url)
{
	m_currenttab->currrnt_widget()->load(url);
}
void My_browser::webview_History(QString& s,QUrl& url)
{
	//添加历史记录
	m_history->addHistoryAction(s,url);
}

void My_browser::browser_exit()
{
	close();
}