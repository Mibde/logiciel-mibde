#include "MyFrame.hpp"

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {

    // Création du panel d'affichage
    

    panelAffichage = new wxPanel(this, -1);
    //les box
    sizer_init = new wxBoxSizer(wxVERTICAL);
    sizer_categorie = new wxBoxSizer(wxHORIZONTAL);
    sizer_comende = new wxBoxSizer(wxHORIZONTAL);
    //les static box
    //les commande des client
    commande = new Commande(panelAffichage);
    //les categorie darticle proposer
    static_boison = new Categorie(panelAffichage, "Boison : ", commande);
    static_snack = new Categorie(panelAffichage, "Snack : ", commande);
    static_nouie = new Categorie(panelAffichage, "Nouie : ", commande);
    static_diver = new Categorie(panelAffichage, "Diver : ", commande);

    //la line
    wxStaticLine* ligneHoriz = new wxStaticLine(panelAffichage, -1);
    // ajour:
    //les aurgnisatons des stoke
    sizer_init->Add(sizer_categorie, 10, wxALL | wxEXPAND, 0);

    sizer_categorie->Add(static_boison, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_snack, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_nouie, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_diver, 1, wxALL | wxEXPAND, 5);
    
    membres = new Membre(panelAffichage);
    sizer_comende->Add(membres, 0, wxALL | wxEXPAND, 0);

    
    sizer_comende->Add(commande, 0, wxALL | wxEXPAND, 0);
    
    //separations
    sizer_init->Add(ligneHoriz, 0, wxALL | wxEXPAND, 0);

    // vendre a une persone
    sizer_init->Add(sizer_comende, 4, wxALL | wxEXPAND, 0);
    panelAffichage->SetSizer(sizer_init);
    
    
}






