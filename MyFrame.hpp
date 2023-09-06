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
#include <iomanip>
#include <fstream>
#include "Commande.hpp"
#include "SnackAddSup.hpp"
#include "Categorie.hpp"
#include "Membre.hpp"
#include "Statistiques.hpp"
#include "Article.hpp"

#define ID_MOOD_ADMIN (wxID_HIGHEST + 1)
#define ID_MOOD_UTILISATEUR (wxID_HIGHEST + 2)

using namespace std;
class Categorie;
class Statistiques;

class MyFrame : public wxFrame
{
private:
	
	int indexBoisson = 0;
	int indexSnack = 0;

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

	Commande* commande;

	Statistiques* statistiques;

	bool mood_utilisateur;


public:


	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	
	void OnExit();
	void OnAdmin();
	void OnUtilisateur();
	void DesactiveUtilisateur();
	void DesactiveAdmin();
	wxArrayString NomSnacks();

};


#endif 