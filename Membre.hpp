#ifndef MEMBRE_HPP
#define MEMBRE_HPP

#include <wx/wx.h>
#include <vector>
#include <iostream>
#include <utility>
#include "Personne.hpp"
#include "SnackAddSup.hpp"
#include "Commande.hpp"
#include "Statistiques.hpp"
using namespace std;
class Personne;
class Statistiques;
class Commande;
class Membre : public wxStaticBoxSizer
{
public:
    Membre(wxPanel* panel_parent);
    void SupprimerPersonne(Personne* personne);
    vector<Personne*> membres;
    void MoodAdmin();
    void MoodUtilisateur();
    vector<pair<string, string>> GetListPersonne();
    void InitCommande(Commande* commande);
    void InitStatistiques(Statistiques* statistiques);
    void JustOnePersonne();
    bool GetIsNotCheck();
    void ModeCommandeAdmin();
    void ModeCommandeUse();
    wxArrayString NomPersonnes();
private:
    void NewMembre(wxCommandEvent& event);
    void InitPersonnes();
    bool Check();
    
    bool is_not_check;
    bool mode_commande;
    wxPanel* panel_parent;
    wxPanel* panel_membres;
    wxScrolledWindow* scrole_membres;
    wxBoxSizer* sizer_panel_membres;

    wxBoxSizer* sizer_membres;
    wxBoxSizer* sizer_scrole;
    wxBoxSizer* sizer_membres_button;
    wxButton* ajoute_personne;
    Commande* commande;
    Statistiques* statistiques;
};

#endif // MEMBRE_HPP
