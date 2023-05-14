#include "Personne.hpp"

Personne::Personne(wxPanel* parent, Membre* membres, const wxString nom) : wxPanel(parent, -1), membre(membres)
{

    testCheck = new wxCheckBox(this, -1, nom);
    
    wxBitmap sup_bitmap("icon/moin.png", wxBITMAP_TYPE_PNG);

    btn_sup_personne = new wxBitmapButton(this, -1, sup_bitmap);
    size_personne = new wxBoxSizer(wxHORIZONTAL);
    size_personne->Add(testCheck, 0, wxALL | wxEXPAND, 0);
    size_personne->Add(btn_sup_personne, 0);
    this->SetSizer(size_personne);
    btn_sup_personne->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) { membre->SupprimerPersonne(this); });

}
