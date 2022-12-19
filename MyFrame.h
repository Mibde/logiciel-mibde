#pragma once
#ifndef MYFRAME_H_INCLUDED
#define MYFRAME_H_INCLUDED

#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/sizer.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/datstrm.h>
#include <iostream>
#include<iomanip>
#include <fstream>
#include "Article.h"

enum CONSTE_BTN {
	BTN_AJOUTER_BOISON = wxID_HIGHEST + 1,
	BTN_SUPRIME_BOISON,
	BTN_AJOUTER_SNACK,
	BTN_SUPRIME_SNACK,
};

using namespace std;
class MyFrame : public wxFrame
{
public:
	int indexBoisson = 0;
	int indexSnack = 0;
	vector<Article*> liste_boisson;
	vector<Article*> liste_snack;
	wxPanel* panelAffichage;


	wxBoxSizer* sizer_init;
	wxBoxSizer* sizer_snack_et_boison;
	wxBoxSizer* sizer_comende;
	//static boison
	wxStaticBoxSizer* static_boison;

	wxBoxSizer* sizer_boison1;
	wxBoxSizer* sizer_boison2;

	wxBoxSizer* sizer_boison_iteme2;
	wxBoxSizer* sizer_boison_button2;
	//staatic snack
	wxStaticBoxSizer* static_snack;
	wxBoxSizer* sizer_snack1;
	wxBoxSizer* sizer_snack2;
	
	wxBoxSizer* sizer_snack_iteme2;
	wxBoxSizer* sizer_snack_button2;


	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	

private:
	wxString CheminsDeFicher();
	void EnregistrementBoissons();
	void RecuperationBoissons();
	void EnregistrementSnack();
	void RecuperationSnack();
	void AddBoisson(int);
	void AddSnack(int);
	void EventAjouteBoison(wxCommandEvent& event);
	void EventAjouteSnack(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()
};


#endif 