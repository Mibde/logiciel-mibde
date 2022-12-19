#include "Article.h"
Article::Article() {

}
Article::Article(wxPanel* panel_parent, const int IDBTN, wxString chemins_image, double prix, int nb_article) : wxPanel(panel_parent, IDBTN) {
	//initialisations des widget
	this->prix = prix;
	this->nb_article = nb_article;
	chemins_ime = chemins_image;
	nom = nomArticle(chemins_ime);
	InitImageArticle();
	//apelle des widget
	AddArticle();
}
void Article::AddArticle() {
	sizer_article->Add(panel_imag_article, 1);
	sizer_article->Add(btn_validation, 1);
	sizer_article->Add(prix_article, 1);
	sizer_article->Add(article, 1);
	this->SetSizer(sizer_article);
}
void Article::InitImageArticle() {
	wxInitAllImageHandlers();
	sizer_article = new wxBoxSizer(wxHORIZONTAL);
	panel_imag_article = new wxPanel(this, -1);
	wxBitmap parametre_imag(chemins_ime, wxBITMAP_TYPE_PNG);
	imagae_article = new wxStaticBitmap(panel_imag_article, wxID_ANY,
		parametre_imag);
	btn_validation = new wxButton(this, -1, nom, wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, nom);
	prix_article = new wxSpinCtrlDouble(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 16384L, 0.0, 100.0, prix, 0.01, nom);
	article = new wxSpinCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 16284L, 0, 1000, nb_article, nom);
}

void Article::EnregistreArticle(ofstream& myoflus) {
	prix = prix_article->GetValue();
	nb_article = article->GetValue();
	myoflus << chemins_ime << " " << prix << " " << nb_article << endl;

}
wxString Article::nomArticle(wxString chemins) {
	int i = 0;
	wxString nom = "";
	while (chemins[i] != '.') {
		nom += chemins[i];
		if (chemins[i] == '/') {
			nom = "";
		}
		i++;
	}

	return nom;
}




