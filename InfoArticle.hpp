#ifndef INFOARTICLE_H_INCLUDED
#define INFOARTICLE_H_INCLUDED

#include <wx/wx.h>
#include <wx/scrolwin.h>
#include <wx/statline.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>

#include <string>
#include <vector>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/datstrm.h>
#include <iostream>
#include <algorithm>
using namespace std;
class InfoArticle : public wxDialog{
private:
    //les box sizer
    wxBoxSizer* sizer_premier;
    wxBoxSizer* sizer_chemin;
    wxBoxSizer* sizer_prix;
    wxBoxSizer* sizer_stock;
    wxBoxSizer* sizer_rupture;
    wxBoxSizer* sizer_caracteristique;
    wxBoxSizer* sizer_descriptif;

    wxButton* button_image;
    wxStaticText* text_chemin;

    wxSpinCtrlDouble* spin_prix;
    wxSpinCtrl* spin_stock;
    wxSpinCtrl* spin_rupture; 

    wxCheckListBox* check_caracteristique;
    wxTextCtrl* text_descriptif;
    void EventCheminImage(wxCommandEvent& event);
    wxString CheminsDeFicher();
public:
    wxString GetDescriptif();
    vector<bool> GetCaracteristique();
    int GetRupture();
    int GetStock();
    double GetPrix();
    wxString GetChemin();
    void InitInfoArticle(wxPanel*, const wxString, wxString, double, int, int, vector<bool>, wxString);
    InfoArticle(wxPanel*, const wxString);
    InfoArticle(wxPanel*, const wxString, wxString, double, int, int, vector<bool>, wxString);
};



#endif 