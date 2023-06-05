#include "Personne.hpp"

Personne::Personne(wxPanel* parent, Membre* membres, const wxString nom) : wxPanel(parent, -1), membre(membres)
{
    
    testCheck = new wxCheckBox(this, -1, nom);
    
    wxBitmap sup_bitmap("icon/moin.png", wxBITMAP_TYPE_PNG);

    btn_sup_personne = new wxBitmapButton(this, -1, sup_bitmap);
    btn_sup_personne->SetMinSize(btn_sup_personne->GetSize());
    btn_sup_personne->SetMaxSize(btn_sup_personne->GetSize());
    size_personne = new wxBoxSizer(wxHORIZONTAL);
    testCheck->SetMinSize(wxSize(255, 0));
    size_personne->Add(testCheck, 0, wxALL | wxEXPAND, 0);
    size_personne->Add(btn_sup_personne, wxALIGN_RIGHT| wxEXPAND);
    this->SetSizer(size_personne);
    btn_sup_personne->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) { membre->SupprimerPersonne(this); });

}
