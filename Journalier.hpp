#ifndef JOURNALIER_H_INCLUDED
#define JOURNALIER_H_INCLUDED
#include <wx/wx.h>
#include <vector>
#include <iostream>
#include "Historique.hpp"
#include "SnackAddSup.hpp"
using namespace std;

class Historique;
class Journalier : public wxDialog{
public:
    Journalier(wxPanel*, wxString, string, string);
    vector<Historique*> historiques_journer;
    void SupprimerHistorique(Historique* historique);
private:
    

    wxBoxSizer* journalier_sizer;
    wxBoxSizer* historique_sizer;

    wxScrolledWindow* scrole_historique;


};
#endif