#include <mainwindow.h>

void My_browser::on_backButton_click()
{
	webview->back();
}

void My_browser::on_forwardButton_click()
{
	webview->forward();
}


void My_browser::on_refreshButton_click()
{
	webview->reload();
}

void My_browser::on_goButton_click()
{
	QString url = line->text();
	if (!url.startsWith("http://") && !url.startsWith("https://"))
	{
		url = "http://" + url;
	}
	line->setText(url);
	webview->load(QUrl(url));
}

void My_browser::onQuitSlot()
{
	close();
}
void My_browser::on_goButtomBtn_click()
{
	
}