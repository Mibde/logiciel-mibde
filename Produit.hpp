#ifndef PRODUIT_H_INCLUDED
#define PRODUIT_H_INCLUDED
#include <wx/wx.h>
#include <wx/checkbox.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Commande.hpp"

using namespace std;
class Commande;
class Produit : public wxPanel
{
private:
    int nb_produit;
    wxBoxSizer* size_produit;
    wxStaticText* text_produit;
    wxBitmapButton* btn_sup_produit;
    Commande* commande;
    wxString nom;
    wxString afichage;
public:
    int GetNbProduit();
    Produit(wxPanel*, Commande*, const wxString);
    void SupProduit();
    void AddProduit();

};







#endif 