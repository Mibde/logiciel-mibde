#include "Categorie.hpp"


Categorie::Categorie(wxPanel* panel_parent, string nom, Commande* commande) : wxStaticBoxSizer(wxVERTICAL, panel_parent, wxString(nom+" : ")), commande(commande), panel_parent(panel_parent), nom(nom)
{
    scrole_categorie = new wxScrolledWindow(panel_parent);

    sizer_categorie = new wxBoxSizer(wxVERTICAL);


    sizer_categorie_button = new wxBoxSizer(wxHORIZONTAL);
    
    
    

    ajoute_article = new wxButton(panel_parent, -1, "ajoute");

    
    
    sizer_categorie_button->Add(ajoute_article, 1);

    scrole_categorie->SetSizer(sizer_categorie);
    scrole_categorie->FitInside();
    scrole_categorie->SetScrollRate(5, 5);
    this->Add(scrole_categorie, 10, wxALL | wxEXPAND, 0);
    
    this->Add(sizer_categorie_button, 1, wxEXPAND, 0);
    InitArtilce();
    ajoute_article->Bind(wxEVT_BUTTON, &Categorie::EventAjouteArticle, this);
    
}

void Categorie::InitArtilce(){
    vector<Snack> snacks = getSnacks(nom);
    for(Snack s : snacks){
        Article* tmp;
        vector<bool> list_caracterisitque =  checkArticleComposition(s.nomSnack);

        if(tmp = new Article(scrole_categorie, this, s.nomSnack, s.cheminVersImage, s.prix, s.prixAchat, s.quantite, s.rupture, list_caracterisitque, s.description, commande))
        {
            liste_aliment.push_back(tmp);
                    
            sizer_categorie->Add(tmp, 0, wxALL | wxEXPAND, 0);
            panel_parent->Layout();
        }
    }
}

void Categorie::EventAjouteArticle(wxCommandEvent& event) {
    //wxInitAllImageHandlers();
    wxTextEntryDialog name_is(panel_parent, wxT("Le nom de l'article (sans acens)"), wxT("Ajouter un article"));
    name_is.SetTextValidator(wxFILTER_ALPHA);
    string nom_snack;

    if (name_is.ShowModal() == wxID_OK && ((nom_snack = name_is.GetValue()) != ""))
    {
        bool init = false;
        string descriptif;
        vector<bool> caracteristique;
        int rupture;
        int stock;
        double prix;
        double prix_achat;
        string chemin;
        int res;
        
        if(unique_ptr<Snack> s = exiteSnack(nom_snack)){
            //cout << "la il y a le chemin : " << s->cheminVersImage << endl;
            descriptif = s->description;
            caracteristique = checkArticleComposition(nom_snack);
            rupture = s->rupture;
            stock = s->quantite;
            prix = s->prix;
            chemin = s->cheminVersImage;
            init = true;
            replaceSnack(nom_snack);
            if(!verifyTypeA(nom_snack, nom)){
                updateTypeA(nom_snack, nom);
            }
        }else if(!chercheSnack(nom_snack)){
            InfoArticle dialo(panel_parent, nom_snack);
            res = dialo.ShowModal();
            if (res == wxID_OK)
            {
                descriptif = dialo.GetDescriptif();
                caracteristique = dialo.GetCaracteristique();
                rupture = dialo.GetRupture();
                stock = dialo.GetStock();
                prix = dialo.GetPrix();
                prix_achat = dialo.GetPrixAchat();
                chemin = dialo.GetChemin();
                createSnack(nom_snack, prix, prix_achat, descriptif, stock, 1, rupture, nom, chemin);
                addAttributesToSnack(nom_snack, caracteristique);
                init = true;
            }
        }
        
        
        Article* tmp;
        if(init && res != wxID_CANCEL &&(tmp = new Article(scrole_categorie, this, nom_snack, chemin, prix, prix_achat, stock, rupture, caracteristique, descriptif, commande)))
        {
            
            liste_aliment.push_back(tmp);
                    
            sizer_categorie->Add(tmp, 0, wxALL | wxEXPAND, 0);
            statistiques->UpdateSelectionSnack();
            panel_parent->Layout();
        }

    }
    name_is.Destroy();
}


wxString Categorie::CheminsDeFicher() {
    wxFileDialog openFileDialog(panel_parent, _("Open PNG file"), "", "", "PNG files (*.png)|*.png", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return "";     // the user changed idea...

    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
    wxFileInputStream input_stream(openFileDialog.GetPath());
    if (!input_stream.IsOk())
    {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return "";
    }
    return openFileDialog.GetPath();
}

void Categorie::SupprimerArticle(Article* article) {
    // Parcours de tous les éléments du sizer
    for (unsigned int i = 0; i < sizer_categorie->GetItemCount(); i++) {
        // Obtention de l'élément sizer correspondant
        wxSizerItem* item = sizer_categorie->GetItem(i);
        // Comparaison du pointeur
        if (item->GetWindow() == article) {
            // Suppression de l'élément du sizer
            sizer_categorie->Remove(i);
            sizer_categorie->Detach(article);
            // Suppression de l'élément du vecteur de liste_aliment
            auto it = find_if(liste_aliment.begin(), liste_aliment.end(), [=](Article* a) { return a == article; });
            if (it != liste_aliment.end()) {
                liste_aliment.erase(it);
            }
            deleteSnack(wxStringToString(article->GetNom()));
            // Destruction de l'objet article
            article->Destroy();
            break;
        }
    }
    statistiques->UpdateSelectionSnack();
    sizer_categorie->Layout();
}

void Categorie::MoodAdmin(){
    ajoute_article->Enable(true);
    for(Article* art : liste_aliment){
        art->MoodAdmin();
    }
}
void Categorie::MoodUtilisateur(){
    ajoute_article->Enable(false);
    for(Article* art : liste_aliment){
        art->MoodUtilisateur();
    }
}

wxArrayString Categorie::NomSnacks(){
    wxArrayString noms;
    for(Article* a : liste_aliment){
        noms.Add(a->GetNom());
    }
    return noms;
}

void Categorie::initStatistiques(Statistiques* statistiques){
    this->statistiques = statistiques;
}