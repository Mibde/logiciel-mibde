#ifndef MEMBRE_HPP
#define MEMBRE_HPP

#include <wx/wx.h>
#include <vector>
#include <iostream>
#include "Personne.hpp"
using namespace std;
class Personne;
class Membre : public wxStaticBoxSizer
{
public:
    Membre(wxPanel* panel_parent);
    void SupprimerPersonne(Personne* personne);
    vector<Personne*> membres;

private:
    void NewMembre(wxCommandEvent& event);

    wxPanel* panel_parent;
    wxPanel* panel_membres;
    wxScrolledWindow* scrole_membres;
    wxBoxSizer* sizer_panel_membres;

    wxBoxSizer* sizer_membres;
    wxBoxSizer* sizer_scrole;
    wxBoxSizer* sizer_membres_button;
    wxButton* ajoute_article;
    
};

#endif // MEMBRE_HPP
