#pragma once
#include <wx/wx.h>
#include "mainFrame.h"
class app : public wxApp
{
	mainFrame* _mainFrame = nullptr;
public:
	app();
	~app();
	virtual bool OnInit();
};

