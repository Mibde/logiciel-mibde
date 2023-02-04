#include "MyFrame.hpp"
/*
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(CONSTE_BTN::BTN_AJOUTER_SNACK, MyFrame::EventAjouteSnack)
END_EVENT_TABLE()
*/
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    /*
    long styleflag = GetWindowStyle();
    SetWindowStyle(styleflag | wxSTAY_ON_TOP);
    */
    // Création du panel d'affichage
    

    panelAffichage = new wxPanel(this, -1);
    //les box
    sizer_init = new wxBoxSizer(wxVERTICAL);
    sizer_categorie = new wxBoxSizer(wxHORIZONTAL);
    sizer_comende = new wxBoxSizer(wxHORIZONTAL);
    //les static box*








    static_boison = new Categorie(panelAffichage, "Boison : ");
    static_snack = new Categorie(panelAffichage, "Snack : ");
    static_nouie = new Categorie(panelAffichage, "Nouie : ");
    static_diver = new Categorie(panelAffichage, "Diver : ");





    //la line
    wxStaticLine* ligneHoriz = new wxStaticLine(panelAffichage, -1);
    // ajour:
    //les aurgnisatons des stoke
    sizer_init->Add(sizer_categorie, 7, wxALL | wxEXPAND, 0);

    sizer_categorie->Add(static_boison, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_snack, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_nouie, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_diver, 1, wxALL | wxEXPAND, 5);
    wxButton* btn1 = new wxButton(panelAffichage, -1, "coucou");
    sizer_comende->Add(btn1, 0, wxALL | wxEXPAND, 0);
    //s�parations
    sizer_init->Add(ligneHoriz, 0, wxALL | wxEXPAND, 0);

    // vendre a une persone
    sizer_init->Add(sizer_comende, 1, wxALL | wxEXPAND, 0);
    panelAffichage->SetSizer(sizer_init);
    
    
}






