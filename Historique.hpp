#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED
#include <wx/wx.h>
#include <iostream>
#include "SnackAddSup.hpp"
#include "Journalier.hpp"

using namespace std;
class Journalier;
class Historique : public wxPanel
{
public:
    Historique(wxScrolledWindow*, wxString, Journalier*);
    void EventRetireHistorique(wxCommandEvent& event);
    void EventInfoHistorique(wxCommandEvent& event);
private:
    wxString date_heur;
    wxBoxSizer* histoirque_sizer;
    wxStaticText* static_date_heur;
    wxBitmapButton* btn_sup_historique;
    wxBitmapButton* btn_inf_historique;
    Journalier* journalier;
};

#endif