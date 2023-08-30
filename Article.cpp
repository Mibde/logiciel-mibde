#include "Article.hpp"

Article::Article(wxPanel* panel_parent, Categorie* categorie, wxString nom, wxString chemins_image, double prix, double prix_achat, int nb_article, int rupture, vector<bool> caracteristique, wxString descriptif, Commande* commande) : wxPanel(panel_parent, wxID_ANY), categorie(categorie), commande(commande), nom(nom){
	//initialisations des widget
	this->panel_parent = panel_parent;
	this->prix = prix;
	this->prix_achat = prix_achat;
	this->nb_article = nb_article;
	this->rupture = rupture;
	this->caracteristique = caracteristique;
	this->descriptif = descriptif;
	chemins_ime = chemins_image;
	is_rupture = nb_article<= rupture;
	InitImageArticle();
	//apelle des widget
	AddArticle();
	btn_sup_article->Bind(wxEVT_BUTTON, [this, categorie](wxCommandEvent& event) { categorie->SupprimerArticle(this);});
	btn_parame->Bind(wxEVT_BUTTON, &Article::EventParame, this);
	btn_info->Bind(wxEVT_BUTTON, &Article::EventInfo, this);
	btn_validation->Bind(wxEVT_BUTTON, &Article::EventVenteProduit, this);
	prix_article->Bind(wxEVT_SPINCTRLDOUBLE, &Article::EventModifiePrix, this);
	article->Bind(wxEVT_SPINCTRL, &Article::EventModifieArticle, this);


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
wxImage Article::LoadImage(const wxString& imagePath) {
    // Vérifier si le format est pris en charge
    wxImage image;
    if (wxImage::CanRead(imagePath)) {
        // Charger l'image dans l'objet wxImage
        image.LoadFile(imagePath);
    }
    return image;
}

wxImage Article::IconImage(const wxString& imagePath) {
    // Vérifier si le format est pris en charge
    wxImage image = LoadImage(imagePath);
    image.Rescale(29, 29);
    return image;
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

	//icon rupture
	rupture_panel = new wxPanel(this, -1);

	wxImage image = LoadImage(chemins_ime);
	if(image.IsOk()){
		image.Rescale(80, 70);
		imagae_article = new wxStaticBitmap(panel_imag_article, wxID_ANY, wxBitmap(image));
	}else{
		wxImage erreur("icon/absent.jpeg", wxBITMAP_TYPE_JPEG);
		erreur.Rescale(80, 70);
		wxBitmap bimap_imag(erreur);
		imagae_article = new wxStaticBitmap(panel_imag_article, wxID_ANY, bimap_imag);
	}
	
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
	MoodAdmin();
}

void Article::InitIcon(string chemin_icon){
	panel_icon_article.push_back(new wxPanel(this, -1));
	wxImage imageIcon = IconImage(chemin_icon);
	wxBitmap bitmap_icon(imageIcon);
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
	
	wxImage image_rouge = IconImage("icon/rouge.jpg");
	wxImage image_vert = IconImage("icon/vert.png");

	ruptrue_icon_rouge = new wxBitmap(image_rouge);
	ruptrue_icon_vert = new wxBitmap(image_vert);
	if(is_rupture){
		rupture_Bitmap = new wxStaticBitmap(rupture_panel, wxID_ANY, *ruptrue_icon_rouge);
	}else{
		rupture_Bitmap = new wxStaticBitmap(rupture_panel, wxID_ANY, *ruptrue_icon_vert);	
	}

}

void Article::InitSupArticle(){
	wxImage imag = IconImage("icon/moin.jpg");
	wxBitmap sup_bitmap(imag);

	btn_sup_article = new wxBitmapButton(this, -1, sup_bitmap);
}

void Article::InitParame(){
	wxImage imag = IconImage("icon/parame.jpg");
	wxBitmap parame(imag);

	btn_parame = new wxBitmapButton(this, -1, parame);
}

void Article::InitInfo(){
	wxImage imag = IconImage("icon/iterrogation.jpg");
	wxBitmap info(imag);

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
	InfoArticle dialo(panel_parent, nom, chemins_ime, prix, prix_achat, nb_article, rupture, caracteristique, descriptif);
        if (dialo.ShowModal() == wxID_OK)
        {
            descriptif = dialo.GetDescriptif();
            caracteristique = dialo.GetCaracteristique();
            rupture = dialo.GetRupture();
            nb_article = dialo.GetStock();
			
            prix = dialo.GetPrix();
			prix_achat = dialo.GetPrixAchat();
			if ((dialo.GetChemin() != ""))
            	chemins_ime = dialo.GetChemin();

			wxImage image = LoadImage(chemins_ime);
			wxBitmap bimap_imag;
			if(image.IsOk()){
				image.Rescale(80, 70);
				bimap_imag = wxBitmap(image);
			}else{
				wxImage erreur("icon/absent.jpeg", wxBITMAP_TYPE_JPEG);
				erreur.Rescale(80, 70);
				wxBitmap bimap_imag = wxBitmap(erreur);
			}
		
			imagae_article->SetBitmap(bimap_imag);

			prix_article->SetValue(prix);
			article->SetValue(nb_article);
			ConfirmeVente();
			chargeIcon();
			deleteSnackPeutContenir(wxStringToString(nom));
			addAttributesToSnack(wxStringToString(nom), caracteristique);
			updateSnack(wxStringToString(nom), prix, prix_achat, wxStringToString(descriptif), nb_article, rupture, wxStringToString(chemins_ime));
			this->Layout();
        }
		
}


void Article::EventInfo(wxCommandEvent& event){
	wxMessageDialog* infoDialog = new wxMessageDialog(this, descriptif, "Informations sur l'article " + nom, wxOK | wxICON_INFORMATION);
	
	infoDialog->ShowModal();
	infoDialog->Destroy();
}
void Article::AnuleProduit(){
	article->SetValue(article->GetValue()+1);
}
void Article::EventVenteProduit(wxCommandEvent& event){
	if(article->GetValue()>0){
		article->SetValue(article->GetValue()-1);
		commande->NewCommande(this);
	}
	
}

wxString Article::GetNom(){
	return nom;
}

double Article::GetPrix(){
	return prix;
}
double Article::GetPrixAchat(){
	return prix_achat;
}
void Article::AnulationsVente(){
	article->SetValue(nb_article);
}

void Article::ConfirmeVente(){
	nb_article = article->GetValue();
	is_rupture = nb_article <= rupture;
	if(is_rupture){
		rupture_Bitmap->SetBitmap(*ruptrue_icon_rouge);
	}else{
		rupture_Bitmap->SetBitmap(*ruptrue_icon_vert);	
	}
	updateSnackStrock(wxStringToString(nom), nb_article);
}
void Article::MoodAdmin(){
	btn_validation->Enable(false);
	prix_article->Enable(true);
	article->Enable(true);
	btn_sup_article->Enable(true);
	btn_parame->Enable(true);
}
void Article::MoodUtilisateur(){
	prix_article->Enable(false);
	article->Enable(false);
	btn_sup_article->Enable(false);
	btn_parame->Enable(false);
	btn_validation->Enable(true);
}

void Article::EventModifiePrix(wxCommandEvent& event){
	prix = prix_article->GetValue();
	updateSnackPrice(wxStringToString(nom), prix);
}

void Article::EventModifieArticle(wxCommandEvent& event){
	ConfirmeVente();
}


