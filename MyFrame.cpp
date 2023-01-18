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
    sizer_snack_et_boison = new wxBoxSizer(wxHORIZONTAL);
    sizer_comende = new wxBoxSizer(wxHORIZONTAL);
    //les static box
    static_boison = new wxStaticBoxSizer(wxHORIZONTAL, panelAffichage, "Boison : ");

    scrole_boison = new wxScrolledWindow(panelAffichage);

    sizer_boison1 = new wxBoxSizer(wxVERTICAL);
    sizer_boison2 = new wxBoxSizer(wxVERTICAL);

    sizer_boison_iteme2 = new wxBoxSizer(wxVERTICAL);
    sizer_boison_button2 = new wxBoxSizer(wxHORIZONTAL);
    
    sizer_boison2->Add(sizer_boison_iteme2, 5, wxALL | wxEXPAND, 0);
    sizer_boison2->Add(sizer_boison_button2, 1, wxALL | wxEXPAND, 0);

    wxButton* ajoute_boison = new wxButton(panelAffichage, -1, "ajoute");
    wxButton* suprime_boison = new wxButton(panelAffichage, -1, "suprime");
    
    sizer_boison_button2->Add(ajoute_boison, 1);
    sizer_boison_button2->Add(suprime_boison, 1);

    /*
    sizer_boison1->Add(boison1, 1, wxALL | wxEXPAND, 0);
    sizer_boison2->Add(boison2, 1, wxALL | wxEXPAND, 0);
    */
    scrole_boison->SetSizer(sizer_boison1);
    scrole_boison->FitInside();
    scrole_boison->SetScrollRate(5, 5); 
    static_boison->Add(scrole_boison, 1, wxALL | wxEXPAND, 0);
    static_boison->Add(sizer_boison2, 1, wxALL | wxEXPAND, 0);
    
    
    //cafer->Destroy();
    static_snack = new wxStaticBoxSizer(wxHORIZONTAL, panelAffichage, "Snack : ");
    sizer_snack1 = new wxBoxSizer(wxVERTICAL);
    sizer_snack2 = new wxBoxSizer(wxVERTICAL);
    static_snack->Add(sizer_snack1, 1, wxALL | wxEXPAND, 0);
    static_snack->Add(sizer_snack2, 1, wxALL | wxEXPAND, 0);
    sizer_snack_iteme2 = new wxBoxSizer(wxVERTICAL);
    sizer_snack_button2 = new wxBoxSizer(wxHORIZONTAL);


    sizer_snack2->Add(sizer_snack_iteme2, 5, wxALL | wxEXPAND, 0);
    sizer_snack2->Add(sizer_snack_button2, 1, wxALL | wxEXPAND, 0);

    wxButton* ajoute_snack = new wxButton(panelAffichage, -1, "ajoute");
    wxButton* suprime_snack = new wxButton(panelAffichage, -1, "suprime");

    sizer_snack_button2->Add(ajoute_snack, 1);
    sizer_snack_button2->Add(suprime_snack, 1);

    //la line
    wxStaticLine* ligneHoriz = new wxStaticLine(panelAffichage, -1);
    // ajour:
    //les aurgnisatons des stoke
    sizer_init->Add(sizer_snack_et_boison, 7, wxALL | wxEXPAND, 0);

    sizer_snack_et_boison->Add(static_boison, 1, wxALL | wxEXPAND, 5);
    sizer_snack_et_boison->Add(static_snack, 1, wxALL | wxEXPAND, 5);
    wxButton* btn1 = new wxButton(panelAffichage, -1, "coucou");
    sizer_comende->Add(btn1, 0, wxALL | wxEXPAND, 0);
    //s�parations
    sizer_init->Add(ligneHoriz, 0, wxALL | wxEXPAND, 0);

    // vendre a une persone
    sizer_init->Add(sizer_comende, 1, wxALL | wxEXPAND, 0);
    panelAffichage->SetSizer(sizer_init);
    ajoute_boison->Bind(wxEVT_BUTTON, &MyFrame::EventAjouteBoison, this);
    ajoute_snack->Bind(wxEVT_BUTTON, &MyFrame::EventAjouteSnack, this);
    
}







void MyFrame::EventAjouteSnack(wxCommandEvent& event) {
    wxInitAllImageHandlers();

    wxString chemins_image = CheminsDeFicher();

    if (chemins_image == "") {
        wxMessageBox("tu na pas rens�nier de Fichier");
    }
    else {

        liste_snack.push_back(new Article(panelAffichage, wxID_ANY, chemins_image, 0.0, 0));

        AddSnack(liste_snack.size() - 1);
        
    }

}
void MyFrame::EventAjouteBoison(wxCommandEvent& event) {
    wxInitAllImageHandlers();

    wxString chemins_image = CheminsDeFicher();

    if (chemins_image == "") {
        wxMessageBox("tu na pas rensenier de Fichier");
    }
    else {
        
        liste_boisson.push_back(new Article(scrole_boison, wxID_ANY, chemins_image, 0.0, 0));
        
        AddBoisson(liste_boisson.size()-1);
        this->Refresh();
        this->Update();
    }
    
}
void MyFrame::AddBoisson(int index) {
    if (index <10)
        sizer_boison1->Add(liste_boisson[index], 0, wxALL | wxEXPAND, 0);
    else
        sizer_boison_iteme2->Add(liste_boisson[index], 0, wxALL | wxEXPAND, 0);
}
void MyFrame::AddSnack(int index) {
    if (index <10)
        sizer_snack1->Add(liste_snack[index], 0, wxALL | wxEXPAND, 0);
    else
        sizer_snack_iteme2->Add(liste_snack[index], 0, wxALL | wxEXPAND, 0);
}


wxString MyFrame::CheminsDeFicher() {
    wxFileDialog openFileDialog(this, _("Open PNG file"), "", "", "PNG files (*.png)|*.png", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return "";     // the user changed idea...

    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
    wxFileInputStream input_stream(openFileDialog.GetPath());
    if (!input_stream.IsOk())
    {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return "";
    }
    return openFileDialog.GetPath();
}

