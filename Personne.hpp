#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <wx/wx.h>
#include <wx/checkbox.h>
#include <string>
#include <iostream>
using namespace std;
class Personne : public wxBoxSizer
{
private:
    wxCheckBox* testCheck;
    wxBoxSizer* box_persones;
public:
    Personne(wxPanel*, const wxString);

};







#endif 