#include "Personne.hpp"


Personne::Personne(wxPanel* parent, const wxString nom) : wxBoxSizer(wxHORIZONTAL)
{

    testCheck = new wxCheckBox(parent, -1, nom);
    this->Add(testCheck, 0, wxALL | wxEXPAND, 0);
}