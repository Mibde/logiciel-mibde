#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <wx/wx.h>
#include <wx/checkbox.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "Membre.hpp"
#include "SnackAddSup.hpp"
using namespace std;
class Membre;
class Personne : public wxPanel
{
private:
    string nom;
    string prenom;
    wxBoxSizer* size_personne;
    wxCheckBox* testCheck;
    wxBitmapButton* btn_sup_personne;
    Membre* membre;
public:
    Personne(wxPanel*, Membre* membres, const string&, const string&);
    void MoodAdmin();
    void MoodUtilisateur();
    void EventRetirePersonne(wxCommandEvent& event);
    void EventActivierPersonne(wxCommandEvent& event);
    bool Check();
    pair<string, string> GetNom();
    wxString Afiche();
    

};







#endif 