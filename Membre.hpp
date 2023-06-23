#ifndef MEMBRE_HPP
#define MEMBRE_HPP

#include <wx/wx.h>
#include <vector>
#include <iostream>
#include <utility>
#include "Personne.hpp"
#include "SnackAddSup.hpp"
using namespace std;
class Personne;
class Membre : public wxStaticBoxSizer
{
public:
    Membre(wxPanel* panel_parent);
    void SupprimerPersonne(Personne* personne);
    vector<Personne*> membres;
    void MoodAdmin();
    void MoodUtilisateur();
    vector<pair<string, string>> GetListPersonne();

private:
    void NewMembre(wxCommandEvent& event);
    void InitPersonnes();
    wxPanel* panel_parent;
    wxPanel* panel_membres;
    wxScrolledWindow* scrole_membres;
    wxBoxSizer* sizer_panel_membres;

    wxBoxSizer* sizer_membres;
    wxBoxSizer* sizer_scrole;
    wxBoxSizer* sizer_membres_button;
    wxButton* ajoute_personne;
    
};

#endif // MEMBRE_HPP
