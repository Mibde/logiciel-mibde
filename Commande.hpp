#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED

#include <wx/wx.h>
#include <wx/event.h>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <pqxx/pqxx> 
#include "Article.hpp"
#include "Produit.hpp"
#include "SnackAddSup.hpp"
#include "Membre.hpp"
using namespace std;
using namespace pqxx;
class Produit;
class Article;
class Membre;

class Commande : public wxBoxSizer
{
public:
    void AugmentArticle(Produit*);
    Commande(wxPanel*, Membre*);
    void SupprimerProduit(Produit* produit);
    void DestroyProduit(Produit* produit);
    map<Article*, Produit*> commandes;
    void NewCommande(Article*);
    void MoodUtilisateur();
    void MoodAdmin();

private:
    Membre* membre;    

    wxPanel* panel_parent;

    wxScrolledWindow* scrole_commandes;

    wxStaticBoxSizer* static_sizer_commandes;

    wxButton* btn_anulation_commande;
    wxButton* btn_validation_commande;


    wxBoxSizer* sizer_commandes;
    wxBoxSizer* sizer_scrole;
    wxBoxSizer* sizer_valid_info;
    wxBoxSizer* sizer_prix;
    wxBoxSizer* sizer_monnaie;
    wxBoxSizer* sizer_rendre;
    wxBoxSizer* sizer_anuler_valider;
    wxStaticText* affiche_prix;
    wxSpinCtrlDouble* monnaie;
    wxStaticText* affiche_monnaie_rendu;

    double CalculTotal();
    void ReffrechTotal();
    double CalculMonnaie();
    void ReffrechMonnaieARendre();
    void EventMonnaie(wxCommandEvent& event);
    void ClearCammande();
    void Anulation();
    void Validation();
    void AjouterVente();
    void EventAnulationCommande(wxCommandEvent& event);
    void EventValidationCommande(wxCommandEvent& event);
};

#endif 
