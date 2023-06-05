#include "Membre.hpp"

Membre::Membre(wxPanel* panel_parent) : wxStaticBoxSizer(wxVERTICAL, panel_parent, "Membres")
{
    this->SetMinSize(wxSize(300, 200));
    this->panel_parent = panel_parent;
    scrole_membres = new wxScrolledWindow(panel_parent);
    sizer_membres = new wxBoxSizer(wxVERTICAL);

    sizer_membres_button = new wxBoxSizer(wxHORIZONTAL);
    ajoute_article = new wxButton(panel_parent, -1, "ajoute");
    sizer_membres_button->Add(ajoute_article, 1);

    scrole_membres->SetSizer(sizer_membres);
    this->Add(scrole_membres, 1, wxALL | wxEXPAND, 0);
    this->Add(sizer_membres_button, 0, wxEXPAND, 0);

    ajoute_article->Bind(wxEVT_BUTTON, &Membre::NewMembre, this);
}

void Membre::NewMembre(wxCommandEvent& event)
{
    wxTextEntryDialog name_is(this->panel_parent, wxT("Le Nom Prenom du nouvaus menbre (sans acens)"), wxT("Ajouter un membre"));
    wxString nom;

    if (name_is.ShowModal() == wxID_OK && ((nom = name_is.GetValue()) != ""))
    {
        Personne* new_personne;
        if ((new_personne = new Personne(scrole_membres, this, nom)))
        {   
            membres.push_back(new_personne);
            sizer_membres->Add(new_personne, 0, wxALL | wxEXPAND, 0);
            sizer_membres->Layout();
            scrole_membres->FitInside();
            scrole_membres->SetVirtualSize(sizer_membres->GetSize());
            scrole_membres->SetScrollRate(5, 5);
        }
        else
        {
            wxLogError("Une ereur et survenus au moment de l'ajous de la person");
        }
    }
    name_is.Destroy();
}

void Membre::SupprimerPersonne(Personne* personne) {
    // Parcours de tous les éléments du sizer
    for (unsigned int i = 0; i < sizer_membres->GetItemCount(); i++) {
        // Obtention de l'élément sizer correspondant
        wxSizerItem* item = sizer_membres->GetItem(i);
        // Comparaison du pointeur
        if (item->GetWindow() == personne) {
            // Suppression de l'élément du sizer
            sizer_membres->Remove(i);
            // Suppression de l'élément du vecteur de personnes
            auto it = find(membres.begin(), membres.end(), personne);
            if (it != membres.end()) {
                membres.erase(it);
            }
            // Destruction de l'objet personne
            personne->Destroy();
            break;
        }
    }
    sizer_membres->Layout();
}


