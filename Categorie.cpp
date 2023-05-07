#include "Categorie.hpp"


Categorie::Categorie(wxPanel* panel_parent, wxString nom) : wxStaticBoxSizer(wxVERTICAL, panel_parent, nom)
{
    
    this->panel_parent = panel_parent;

    scrole_categorie = new wxScrolledWindow(panel_parent);

    sizer_categorie = new wxBoxSizer(wxVERTICAL);


    sizer_categorie_button = new wxBoxSizer(wxHORIZONTAL);
    
    
    

    ajoute_article = new wxButton(panel_parent, -1, "ajoute");

    
    
    sizer_categorie_button->Add(ajoute_article, 1);

    scrole_categorie->SetSizer(sizer_categorie);
    scrole_categorie->FitInside();
    scrole_categorie->SetScrollRate(5, 5);
    this->Add(scrole_categorie, 10, wxALL | wxEXPAND, 0);
    
    this->Add(sizer_categorie_button, 1, wxEXPAND, 0);

    ajoute_article->Bind(wxEVT_BUTTON, &Categorie::EventAjouteArticle, this);
    
}


void Categorie::EventAjouteArticle(wxCommandEvent& event) {
    wxInitAllImageHandlers();

    wxString chemins_image = CheminsDeFicher();

    if (chemins_image == "") {
        wxMessageBox("tu na pas rensenier de Fichier");
    }
    else {
        Article* tmp;
        if((tmp = new Article(scrole_categorie, wxID_ANY, chemins_image, 0.0, 0)))
        {
            liste_aliment.push_back(tmp);
        
            sizer_categorie->Add(tmp, 0, wxALL | wxEXPAND, 0);
            panel_parent->Layout();
        }else{
            wxLogError("Une Erreur et survenus au moment de l'ajous de l'article");
        }
    }

    
}


wxString Categorie::CheminsDeFicher() {
    wxFileDialog openFileDialog(panel_parent, _("Open PNG file"), "", "", "PNG files (*.png)|*.png", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
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