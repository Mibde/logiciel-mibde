#include "Membre.hpp"

Membre::Membre(wxPanel* panel_parent) : wxStaticBoxSizer(wxVERTICAL, panel_parent, "Membres")
{
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
    name_is.SetTextValidator(wxFILTER_ALPHA);
    wxString nom;

    if (name_is.ShowModal() == wxID_OK && ((nom = name_is.GetValue()) != ""))
    {
        Personne* new_personne;
        if ((new_personne = new Personne(scrole_membres, nom)))
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

