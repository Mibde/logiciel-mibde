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
#include <vector>
using namespace std;


class Article : public wxPanel {
private:

	vector<wxPanel*> panel_icon_article;
	vector<wxStaticBitmap*> icon_article;
	wxBoxSizer* sizer_article;
	wxBoxSizer* sizer_info_parame;
	wxBoxSizer* sizer_info;
	wxBoxSizer* sizer_parame;

	wxPanel* panel_imag_article;

	string chemins_ime;
	wxStaticBitmap* imagae_article;

	wxBitmapButton* btn_sup_article;
	wxBitmapButton* btn_parame;

	wxButton* btn_validation;

	wxSpinCtrlDouble* prix_article;

	wxSpinCtrl* article;
	string nom;

	double prix;

	int nb_article;
public:

	void InitIcon(string);
	void InitSupArticle();
	void InitParame();
	void InitImageArticle();
	void AddArticle();
	void EnregistreArticle(ofstream&);
	wxString nomArticle(wxString chemins);
	Article();
	Article(wxPanel*, const int, wxString, double, int);
};

#endif // ARTICLE_H_INCLUDED
