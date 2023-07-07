#ifndef STATISTIQUES_H_INCLUDED
#define STATISTIQUES_H_INCLUDED
#include <wx/wx.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "MyFrame.hpp"
#include "Membre.hpp"
using namespace std;

class MyFrame;
class Statistiques : public wxStaticBoxSizer{
public:
    Statistiques(wxPanel* panel_parent, MyFrame* frame_parent, Membre* membre);
    void UpdateSelectionSnack();
    void UpdateSelectionPersonne();
private:
    MyFrame* frame_parent;
    Membre* membre;

    // afiche le texte

    wxStaticText* date_debus;
    wxStaticText* date_fin;

    wxDatePickerCtrl* date_picker_debus;
    wxDatePickerCtrl* date_picker_fin;

    wxBoxSizer* sizer_debus;
    wxBoxSizer* sizer_fin;

    wxChoice* selection_snack;
    wxChoice* selection_personne;
};





#endif 