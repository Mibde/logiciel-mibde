#ifndef ARTICLE_H_INCLUDED
#define ARTiCLE_H_INCLUDED

// Le header wxWidgets de base
//@ts-ignore
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <string>
#include <iostream>
#include<iomanip>
#include <fstream>
using namespace std;


class Article : public wxPanel {
public:
	wxBoxSizer* sizer_article;
	wxPanel* panel_imag_article;
	string chemins_ime;
	wxStaticBitmap* imagae_article;
	wxButton* btn_validation;
	wxSpinCtrlDouble* prix_article;
	wxSpinCtrl* article;
	string nom;
	double prix;
	int nb_article;
	void InitImageArticle();
	void AddArticle();
	void EnregistreArticle(ofstream&);
	wxString nomArticle(wxString chemins);
	Article();
	Article(wxPanel*, const int, wxString, double, int);
};

#endif // ARTICLE_H_INCLUDED
