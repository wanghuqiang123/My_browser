#include <mainwindow.h>

void My_browser::on_backButton_click()
{
	webview->back();
}

void My_browser::on_forwardButton_click()
{
	//webview->forward();
}

void My_browser::on_refreshButton_click()
{
	//webview->reload();
}

void My_browser::on_goButton_click()
{
	QString url = line->text();
	if (!url.startsWith("http://") && !url.startsWith("https://"))
	{
		url = "http://" + url;
	}
	//line->setText(url);
	//webview->load(QUrl(url));
}

void My_browser::webviewLoding(int progress)
{
	PB->setValue(progress);
	line->setText(webview->url().toString());  //将文本框中的网址显示为真实网址
}

void My_browser::webview_PagePrint()
{
	QPrintDialog dlg(this);    //弹出打印对话框
	dlg.setWindowTitle("Print");    //对话框标题

	if (dlg.exec() == QPrintDialog::Accepted)        //等待按下是否 选择是打印
	{
		QPrinter* p = dlg.printer();               //获取打印机对象

		//将编辑器中的内容传给打印机打印，第二个参数这里用到了lambda语法，因为在QWebEngine这里需要一个回调函数
		webview->page()->print(p, [=](bool) {});
	}
}

void My_browser::recive_url_fromhistory(const QUrl& url)
{
	webview->load(url);
}
void My_browser::webview_History()
{
	//添加历史记录
	m_history->addHistoryAction();
}
