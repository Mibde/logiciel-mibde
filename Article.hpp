#ifndef ARTICLE_H_INCLUDED
#define ARTICLE_H_INCLUDED

// Le header wxWidgets de base
//@ts-ignore
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <string>
#include <iostream>
#include<iomanip>
#include <fstream>
#include <vector>
#include "Categorie.hpp"
#include "InfoArticle.hpp"
#include "Commande.hpp"
#include "SnackAddSup.hpp"
using namespace std;
class Categorie;
class Article : public wxPanel {
private:
	wxPanel* panel_parent;
	vector<wxPanel*> panel_icon_article;
	vector<wxStaticBitmap*> icon_article;
	wxBoxSizer* sizer_article;
	wxBoxSizer* sizer_info_parame;
	wxBoxSizer* sizer_info;
	wxBoxSizer* sizer_parame;
	wxBoxSizer* sizer_parame_icon;

	wxPanel* panel_imag_article;

	wxString  chemins_ime;
	wxStaticBitmap* imagae_article;

	wxBitmapButton* btn_sup_article;
	wxBitmapButton* btn_parame;
	wxBitmapButton* btn_info;

	wxButton* btn_validation;

	wxSpinCtrlDouble* prix_article;

	wxSpinCtrl* article;
	wxString nom;

	double prix;
	double prix_achat;

	int nb_article;

	wxPanel* rupture_panel;
	wxStaticBitmap* rupture_Bitmap;
	wxBitmap* ruptrue_icon_rouge;
	wxBitmap* ruptrue_icon_vert;


	int rupture;
	bool is_rupture;
	vector<bool> caracteristique;
	wxString descriptif;

	Categorie* categorie;
	
	Commande* commande;
	void InitInfo();
	void InitIcon(string);
	void InitSupArticle();
	void InitParame();
	void InitImageArticle();
	void AddArticle();
	void chargeIcon();
	void AddIcon();
	void RuptureIcone();
	wxImage IconImage(const wxString& imagePath);
	wxImage LoadImage(const wxString& imagePath);
public:
	void MoodAdmin();
	void MoodUtilisateur();
	void ConfirmeVente();
	void AnulationsVente();
	void AnuleProduit();
	wxString GetNom();
	double GetPrix();
	double GetPrixAchat();
	void EventParame(wxCommandEvent& event);
	void EventInfo(wxCommandEvent& event);
	void EventVenteProduit(wxCommandEvent& event);
	void EventModifiePrix(wxCommandEvent& event);
	void EventModifieArticle(wxCommandEvent& event);
	Article(wxPanel*, Categorie*, wxString, wxString, double, double, int, int, vector<bool>, wxString, Commande*);

	
};

#endif // ARTICLE_H_INCLUDED
