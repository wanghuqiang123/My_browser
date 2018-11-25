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

}