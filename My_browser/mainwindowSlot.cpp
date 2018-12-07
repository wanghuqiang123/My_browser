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
	line->setText(webview->url().toString());  //���ı����е���ַ��ʾΪ��ʵ��ַ
}

void My_browser::webview_PagePrint()
{
	QPrintDialog dlg(this);    //������ӡ�Ի���
	dlg.setWindowTitle("Print");    //�Ի������

	if (dlg.exec() == QPrintDialog::Accepted)        //�ȴ������Ƿ� ѡ���Ǵ�ӡ
	{
		QPrinter* p = dlg.printer();               //��ȡ��ӡ������

		//���༭���е����ݴ�����ӡ����ӡ���ڶ������������õ���lambda�﷨����Ϊ��QWebEngine������Ҫһ���ص�����
		webview->page()->print(p, [=](bool) {});
	}
}

void My_browser::recive_url_fromhistory(const QUrl& url)
{
	webview->load(url);
}
void My_browser::webview_History()
{
	//�����ʷ��¼
	m_history->addHistoryAction();
}
