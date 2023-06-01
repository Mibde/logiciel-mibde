#include "Article.hpp"

Article::Article(wxPanel* panel_parent, Categorie* categorie, wxString nom, wxString chemins_image, double prix, int nb_article, int rupture, vector<bool> caracteristique, wxString descriptif) : wxPanel(panel_parent, wxID_ANY), categorie(categorie) {
	//initialisations des widget
	this->panel_parent = panel_parent;
	this->prix = prix;
	this->nb_article = nb_article;
	this->rupture = rupture;
	this->caracteristique = caracteristique;
	this->descriptif = descriptif;
	chemins_ime = chemins_image;
	this->nom = nom;
	InitImageArticle();
	//apelle des widget
	AddArticle();
	btn_sup_article->Bind(wxEVT_BUTTON, [this, categorie](wxCommandEvent& event) { categorie->SupprimerArticle(this); });
	btn_parame->Bind(wxEVT_BUTTON, &Article::EventParame, this);
	btn_info->Bind(wxEVT_BUTTON, &Article::EventInfo, this);
}
void Article::AddArticle() {
	sizer_article->Add(panel_imag_article, 0);
	sizer_article->Add(sizer_info_parame, 0);
	sizer_info_parame->Add(sizer_parame, 0);
	
	sizer_parame->Add(btn_sup_article, 0);
	sizer_parame->Add(btn_parame, 0);
	sizer_parame->Add(btn_info, 0);
	sizer_parame->Add(rupture_panel, 0);
	sizer_parame->Add(sizer_parame_icon, 0);
	//icon article
	AddIcon();
	

	
	sizer_info_parame->Add(sizer_info, 0);
	sizer_info->Add(btn_validation, 0, wxFIXED_MINSIZE);
	sizer_info->Add(prix_article, 0, wxFIXED_MINSIZE);
	sizer_info->Add(article, 0, wxFIXED_MINSIZE);
	
	this->SetSizer(sizer_article);
}

void Article::AddIcon(){
	if(caracteristique[0])
		InitIcon("icon/halal.jpg");
	if(caracteristique[1])
		InitIcon("icon/kosher.png");
	if(caracteristique[2])
		InitIcon("icon/recyclable.png");
	if(caracteristique[3])
		InitIcon("icon/vegan.jpg");
	if(caracteristique[4])
		InitIcon("icon/vegetarian.png");
}

void Article::InitImageArticle() {
	wxInitAllImageHandlers();
	sizer_article = new wxBoxSizer(wxHORIZONTAL);
	sizer_info_parame = new wxBoxSizer(wxVERTICAL);
	sizer_info = new wxBoxSizer(wxHORIZONTAL);
	sizer_parame = new wxBoxSizer(wxHORIZONTAL);
	sizer_parame_icon = new wxBoxSizer(wxHORIZONTAL);

	//image du snack
	panel_imag_article = new wxPanel(this, -1);
	wxBitmap parametre_imag(chemins_ime, wxBITMAP_TYPE_PNG);
	imagae_article = new wxStaticBitmap(panel_imag_article, wxID_ANY,
		parametre_imag);
	
	//btn suprestion article
	InitSupArticle();


	//btn paramertre
	InitParame();

	//btn informations article
	InitInfo();

	//Indication rupture
	RuptureIcone();

	btn_validation = new wxButton(this, -1, nom, wxDefaultPosition, wxDefaultSize, 0L, wxDefaultValidator, nom);
	prix_article = new wxSpinCtrlDouble(this, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16384L, 0.0, 100.0, prix, 0.01, nom);
	article = new wxSpinCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16284L, 0, 1000, nb_article, nom);
}

void Article::InitIcon(string chemin_icon){
	panel_icon_article.push_back(new wxPanel(this, -1));
	wxBitmap bitmap_icon(chemin_icon, wxBITMAP_TYPE_PNG);
	wxStaticBitmap* tmp;
	if(tmp = new wxStaticBitmap(panel_icon_article[panel_icon_article.size()-1], wxID_ANY,
		bitmap_icon)){
			icon_article.push_back(tmp);
	}else{
		wxLogError("Prebleme de creations d'une icon");
	}
	sizer_parame_icon->Add(panel_icon_article[panel_icon_article.size()-1], 0);
}
void Article::RuptureIcone(){
	rupture_panel = new wxPanel(this, -1);
	wxBitmap ruptrue_icon("icon/rouge.jpg", wxBITMAP_TYPE_JPEG_RESOURCE);
	rupture_Bitmap = new wxStaticBitmap(rupture_panel, wxID_ANY, ruptrue_icon);
}
void Article::InitSupArticle(){
	wxBitmap sup_bitmap("icon/moin.png", wxBITMAP_TYPE_PNG);

	btn_sup_article = new wxBitmapButton(this, -1, sup_bitmap);
}

void Article::InitParame(){
	wxBitmap parame("icon/parame.jpg", wxBITMAP_TYPE_JPEG_RESOURCE);

	btn_parame = new wxBitmapButton(this, -1, parame);
}

void Article::InitInfo(){
	wxBitmap info("icon/iterrogation.jpg", wxBITMAP_TYPE_JPEG_RESOURCE);

	btn_info = new wxBitmapButton(this, -1, info);
}



void Article::chargeIcon(){
	wxSizerItemList children = sizer_parame_icon->GetChildren();
    for (wxSizerItem* item : children)
    {
        wxPanel* panel = dynamic_cast<wxPanel*>(item->GetWindow());
        if (panel)
        {
            sizer_parame_icon->Detach(panel);
            panel->Destroy();
        }
    }
	icon_article.clear();
	panel_icon_article.clear();
	AddIcon();


}


void Article::EventParame(wxCommandEvent& event){
	InfoArticle dialo(panel_parent, nom, chemins_ime, prix, nb_article, rupture, caracteristique, descriptif);
        if (dialo.ShowModal() == wxID_OK)
        {
            descriptif = dialo.GetDescriptif();
            caracteristique = dialo.GetCaracteristique();
            rupture = dialo.GetRupture();
            nb_article = dialo.GetStock();
			
            prix = dialo.GetPrix();
			if ((dialo.GetChemin() != ""))
            	chemins_ime = dialo.GetChemin();
			wxBitmap bitmap_icon(chemins_ime, wxBITMAP_TYPE_PNG);
		
			imagae_article->SetBitmap(bitmap_icon);

			prix_article->SetValue(prix);
			article->SetValue(nb_article);
			
			chargeIcon();
			
        }
		this->Layout();
}


void Article::EventInfo(wxCommandEvent& event){
	wxMessageDialog* infoDialog = new wxMessageDialog(this, descriptif, "Informations sur l'article " + nom, wxOK | wxICON_INFORMATION);
	
	infoDialog->ShowModal();
	infoDialog->Destroy();
}

