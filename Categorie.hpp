#ifndef CATEGORIE_H_INCLUDED
#define CATEGORIE_H_INCLUDED


#include <wx/wx.h>
#include <wx/scrolwin.h>
#include <wx/statline.h>
#include <wx/sizer.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <vector>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/datstrm.h>
#include <iostream>
#include <algorithm>
#include "Article.hpp"
#include "InfoArticle.hpp"
#include "Commande.hpp"
#include "SnackAddSup.hpp"

using namespace std;
class Article;
class Commande;
class Categorie : public wxStaticBoxSizer
{
private:
    string nom;
    //la liste des aliment
    vector<Article*> liste_aliment;

    //la coposant de scrole
    wxScrolledWindow* scrole_categorie;

    //les box 
    wxBoxSizer* sizer_categorie;
	wxBoxSizer* sizer_categorie_button;
    wxFrame* frame_parent;
    wxButton* ajoute_article;
    wxPanel* panel_parent;
    Commande* commande;

    void InitArtilce();
public:
    void MoodAdmin();
    void MoodUtilisateur();
    void SupprimerArticle(Article*);
    Categorie(wxPanel*, string, Commande*);
    void EventAjouteArticle(wxCommandEvent& event);
    wxString CheminsDeFicher();
};


#endif 