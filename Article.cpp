#include "Article.hpp"
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
	sizer_article->Add(panel_imag_article, 0);
	sizer_article->Add(sizer_info_parame, 0);
	sizer_info_parame->Add(sizer_parame, 0);
	
	sizer_parame->Add(btn_sup_article, 0);
	sizer_parame->Add(btn_parame, 0);
	sizer_parame->Add(panel_icon_vegan, 0);

	sizer_info_parame->Add(sizer_info, 0);
	sizer_info->Add(btn_validation, 0, wxFIXED_MINSIZE);
	sizer_info->Add(prix_article, 0, wxFIXED_MINSIZE);
	sizer_info->Add(article, 0, wxFIXED_MINSIZE);
	this->SetSizer(sizer_article);
}
void Article::InitImageArticle() {
	wxInitAllImageHandlers();
	sizer_article = new wxBoxSizer(wxHORIZONTAL);
	sizer_info_parame = new wxBoxSizer(wxVERTICAL);
	sizer_info = new wxBoxSizer(wxHORIZONTAL);
	sizer_parame = new wxBoxSizer(wxHORIZONTAL);
	//image du snack
	panel_imag_article = new wxPanel(this, -1);
	wxBitmap parametre_imag(chemins_ime, wxBITMAP_TYPE_PNG);
	imagae_article = new wxStaticBitmap(panel_imag_article, wxID_ANY,
		parametre_imag);
	
	//image vegane
	InitIconVegan();
	
	//btn suprestion article
	InitSupArticle();


	//btn paramertre
	InitParame();


	btn_validation = new wxButton(this, -1, nom, wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, nom);
	prix_article = new wxSpinCtrlDouble(this, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16384L, 0.0, 100.0, prix, 0.01, nom);
	article = new wxSpinCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16284L, 0, 1000, nb_article, nom);
}

void Article::InitIconVegan(){
	panel_icon_vegan = new wxPanel(this, -1);
	wxBitmap parametre_icon_vegan("icon/vegan.jpg", wxBITMAP_TYPE_PNG);

	if(!(icon_vegan = new wxStaticBitmap(panel_icon_vegan, wxID_ANY,
		parametre_icon_vegan))){
			cout << "nulllll" << endl;
		}
}

void Article::InitSupArticle(){
	wxBitmap sup_bitmap("icon/moin.png", wxBITMAP_TYPE_PNG);

	btn_sup_article = new wxBitmapButton(this, -1, sup_bitmap);
}

void Article::InitParame(){
	wxBitmap parame("icon/parame.jpg", wxBITMAP_TYPE_JPEG_RESOURCE);

	btn_parame = new wxBitmapButton(this, -1, parame);
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




