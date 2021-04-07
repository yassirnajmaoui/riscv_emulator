#include "App.h"
wxIMPLEMENT_APP(app);

app::app()
{

}

app::~app()
{

}

bool app::OnInit()
{
	_mainFrame = new mainFrame();
	_mainFrame->Show();
	return true;
}
