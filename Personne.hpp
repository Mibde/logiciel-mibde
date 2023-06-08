#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <wx/wx.h>
#include <wx/checkbox.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Membre.hpp"

using namespace std;
class Membre;
class Personne : public wxPanel
{
private:
    wxBoxSizer* size_personne;
    wxCheckBox* testCheck;
    wxBitmapButton* btn_sup_personne;
    Membre* membre;
public:
    Personne(wxPanel*, Membre* membres, const wxString);
    void MoodAdmin();
    void MoodUtilisateur();
    

};







#endif 