#include "mainFrame.h"
enum
{
    ID_Hello,
    ID_EXIT,
    ID_TEXTBOX,
    ID_RUN,
};

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
    EVT_MENU(ID_Hello, mainFrame::OnOpen)
    EVT_MENU(ID_EXIT, mainFrame::OnExit)
    EVT_MENU(ID_RUN, mainFrame::OnRun)
wxEND_EVENT_TABLE()

mainFrame::mainFrame() : wxFrame(nullptr, wxID_ANY, "RISC-V Emulator")
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "Open","Open file");
    menuFile->Append(ID_EXIT, "Exit", "Close the application");
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenu* menuRun = new wxMenu;
    menuRun->Append(ID_RUN, "TOKENIZE");
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "File");
    menuBar->Append(menuHelp, "Help");
    menuBar->Append(menuRun, "Run");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("");
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    textbox = std::make_unique<wxTextCtrl>(this, wxID_ANY, "",wxDefaultPosition,wxSize(500,250),wxTE_MULTILINE|wxTE_RICH|wxTE_RICH2);
    tokensTextbox = std::make_unique<wxTextCtrl>(this, wxID_ANY, "", wxDefaultPosition, wxSize(250,250), wxTE_MULTILINE | wxTE_RICH | wxTE_RICH2 | wxTE_READONLY);
    sizer->Add(textbox.get());
    sizer->Add(tokensTextbox.get());
    this->SetSizerAndFit(sizer);
}

mainFrame::~mainFrame()
{
}

void mainFrame::OnOpen(wxCommandEvent& event)
{
    wxString filePath;
    wxFileDialog fileDialog(this);
    if (fileDialog.ShowModal() != wxID_OK) return;
    filePath.Clear();
    filePath = fileDialog.GetPath();
    wxString str;
    wxTextFile textFile;
    textFile.Open(filePath);
    str = textFile.GetFirstLine() + "\n";
    while (!textFile.Eof())
    {
        str.append(textFile.GetNextLine() + "\n");
    }
    textbox->Clear();
    textbox->AppendText(str);
    event.Skip();
}

void mainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void mainFrame::OnRun(wxCommandEvent& event)
{
    wxString textContent = textbox->GetValue();
    std::stringstream ss(textContent.ToStdString());
    std::string line;
    std::vector<std::string> tokens;
    while (std::getline(ss, line))
    {
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(" ,", prev)) != std::string::npos)
        {
            if (pos > prev)
                tokens.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < line.length())
            tokens.push_back(line.substr(prev, std::string::npos));
    }
    tokensTextbox->Clear();
    for (auto& token : tokens)
    {
        if (token == ' ') {
            tokensTextbox->AppendText("space\n");
        }
        else
        {
            tokensTextbox->AppendText(token + "\n");
        }
    }
}

void mainFrame::onEditorTextChange()
{
  
}
