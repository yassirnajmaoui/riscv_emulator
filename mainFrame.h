#pragma once
#include <wx/wx.h>
#include <wx/textfile.h>
#include <wx/textctrl.h>
#include <string>
#include <sstream>
#include <vector>
class mainFrame : public wxFrame
{
	std::unique_ptr<wxTextCtrl> textbox;
	std::unique_ptr<wxTextCtrl> tokensTextbox;
	void onEditorTextChange();
public:
	mainFrame();
	~mainFrame();
	void OnOpen(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnRun(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

