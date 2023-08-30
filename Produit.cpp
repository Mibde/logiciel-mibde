#include "Produit.hpp"

Produit::Produit(wxPanel* parent, Commande* commande, wxString nom) : wxPanel(parent, -1), commande(commande)
{

    this->nom = nom;
    nb_produit = 1;
    afichage = wxString::Format("%s X%d",nom, nb_produit);
    text_produit = new wxStaticText(this, -1, afichage);
    
    wxBitmap sup_bitmap("icon/moin.jpg", wxBITMAP_TYPE_JPEG);

    btn_sup_produit = new wxBitmapButton(this, -1, sup_bitmap);
    btn_sup_produit->SetMinSize(btn_sup_produit->GetSize());
    btn_sup_produit->SetMaxSize(btn_sup_produit->GetSize());
    size_produit = new wxBoxSizer(wxHORIZONTAL);
    text_produit->SetMinSize(wxSize(255, 0));
    size_produit->Add(text_produit, 0, wxALL | wxEXPAND, 0);
    size_produit->Add(btn_sup_produit, wxALIGN_RIGHT| wxEXPAND);
    this->SetSizer(size_produit);
    btn_sup_produit->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) { commande->SupprimerProduit(this); });

}

int Produit::GetNbProduit(){
    return nb_produit;
}
void Produit::SupProduit(){
    nb_produit--;
    afichage = wxString::Format("%s X%d",nom, nb_produit);
    text_produit->SetLabel(afichage);
}

void Produit::AddProduit(){
    nb_produit++;
    afichage = wxString::Format("%s X%d",nom, nb_produit);
    text_produit->SetLabel(afichage);
}