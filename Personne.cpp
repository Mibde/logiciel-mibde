#include "Personne.hpp"

Personne::Personne(wxPanel* parent, Membre* membres, const string& nom, const string& prenom) : wxPanel(parent, -1), membre(membres), nom(nom), prenom(prenom)
{
    
    testCheck = new wxCheckBox(this, -1, wxString(nom + " " + prenom));
    
    wxBitmap sup_bitmap("icon/moin.png", wxBITMAP_TYPE_PNG);

    btn_sup_personne = new wxBitmapButton(this, -1, sup_bitmap);
    btn_sup_personne->SetMinSize(btn_sup_personne->GetSize());
    btn_sup_personne->SetMaxSize(btn_sup_personne->GetSize());
    size_personne = new wxBoxSizer(wxHORIZONTAL);
    testCheck->SetMinSize(wxSize(255, 0));
    size_personne->Add(testCheck, 0, wxALL | wxEXPAND, 0);
    size_personne->Add(btn_sup_personne, wxALIGN_RIGHT| wxEXPAND);
    this->SetSizer(size_personne);
    btn_sup_personne->Bind(wxEVT_BUTTON, &Personne::EventRetirePersonne, this);
    testCheck->Bind(wxEVT_CHECKBOX, &Personne::EventActivierPersonne, this);
}
void Personne::EventRetirePersonne(wxCommandEvent& event){
    membre->SupprimerPersonne(this);
    desactiverPersonne(nom, prenom);

}
void Personne::MoodAdmin(){
    btn_sup_personne->Enable(true);
}

void Personne::MoodUtilisateur(){
    btn_sup_personne->Enable(false);
}

bool Personne::Check(){
    return testCheck->GetValue();
}

pair<string, string> Personne::GetNom(){
    return pair<string, string> (nom, prenom);
}

void Personne::EventActivierPersonne(wxCommandEvent& event){
    membre->JustOnePersonne();
}

wxString Personne::Afiche(){
    return wxString(nom+ " " + prenom);
}