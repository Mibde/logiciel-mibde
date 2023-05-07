#pragma once
#ifndef MYFRAME_H_INCLUDED
#define MYFRAME_H_INCLUDED

#include <wx/wx.h>
#include <wx/scrolwin.h>
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


#include "Categorie.hpp"
#include "Membre.hpp"

using namespace std;
class MyFrame : public wxFrame
{
private:
	int indexBoisson = 0;
	int indexSnack = 0;
	vector<Article*> liste_boisson;
	vector<Article*> liste_snack;
	wxPanel* panelAffichage;


	wxBoxSizer* sizer_init;
	wxBoxSizer* sizer_categorie;
	wxBoxSizer* sizer_comende;
	//static boison
	Categorie* static_boison;
	Categorie* static_snack;
	Categorie* static_nouie;
	Categorie* static_diver;
	Membre* membres;
	wxScrolledWindow* scrole_boison;






public:


	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	


};


#endif 