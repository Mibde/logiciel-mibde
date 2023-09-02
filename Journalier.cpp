#include "Journalier.hpp"

Journalier::Journalier(wxPanel* parent, wxString wx_date_debus, wxString wx_date_fin, string type_snack, string type_personne, bool mode_utilisateur) : wxDialog(parent, -1, wxString(wxStringToString(wx_date_debus) + " a " + wxStringToString(wx_date_fin)), wxDefaultPosition, wxSize(500, 500))
{
    historique_sizer = new wxBoxSizer(wxVERTICAL);
    journalier_sizer = new wxBoxSizer(wxVERTICAL);

    scrole_historique = new wxScrolledWindow(this);

    string date_debus = wxStringToString(wx_date_debus);
    string date_fin = wxStringToString(wx_date_fin);
    
    scrole_historique->SetSizer(historique_sizer);

    float prix =0.0f, prix_achat= 0.0f, prix_spes= 0.0f, prix_achat_spes=0.0f, benefe=0.0f, benefe_spes=0.0f;
    int occurrence =0;
    

    if(type_snack == "Tout snacks" && type_personne == "Tout le monde"){
        list_commande = listCommandeJour(date_debus, date_fin);

        prix = CommandePrixJour(date_debus, date_fin);
        prix_achat = CommandePrixAchatJour(date_debus, date_fin);
        benefe = prix-prix_achat;
        wxString afichage_prix = wxString::Format("Total des commandes : %5.2f prix d'achat %5.2f et benefice %5.2f ", prix, prix_achat, benefe);

        journalier_sizer->Add(new wxStaticText(this, -1, afichage_prix));

        
    }
    else if(type_personne == "Toute le monde"){
        list_commande = listCommandeJourSnack(date_debus, date_fin, type_snack);

        prix = CommandePrixJourSnack(date_debus, date_fin, type_snack);
        prix_achat = CommandePrixAchatJourSnack(date_debus, date_fin, type_snack);

        prix_spes = CommandePrixJourSnackSpesific(date_debus, date_fin, type_snack, occurrence);
        
        prix_achat_spes = CommandePrixAchatJourSnackSpesific(date_debus, date_fin, type_snack);
        cout << prix_spes << endl;
        cout << prix_achat_spes << endl;
        benefe = prix-prix_achat;
        benefe_spes = prix_spes-prix_achat_spes;
        wxString afichage_prix = wxString::Format("Total des commandes et de %5.2f\net a un prix d'achat de %5.2f et un benefice de %5.2f ", prix, prix_achat, benefe);
        wxString afichage_prix_specific = wxString::Format("Total des %s et de %5.2f pour %d \navec un prix d'achat de %5.2f et un benefice de %5.2f ", wxString(type_snack), prix_spes, occurrence, prix_achat_spes, benefe_spes);

        journalier_sizer->Add(new wxStaticText(this, -1, afichage_prix));
        journalier_sizer->Add(new wxStaticText(this, -1, afichage_prix_specific));
    }
    else if(type_snack == "Tout snacks") {
        list_commande = listCommandeJourPersone(date_debus, date_fin, type_personne);
        prix = CommandePrixJourPersonne(date_debus, date_fin, type_personne);
        prix_achat = CommandePrixAchatJourPersonne(date_debus, date_fin, type_personne);
        benefe = prix-prix_achat;
        wxString afichage_prix = wxString::Format("Total les commande faite par %s : %5.2f \nprix d'achat %5.2f et benefice %5.2f", wxString(type_personne), prix, prix_achat, benefe);
        journalier_sizer->Add(new wxStaticText(this, -1, afichage_prix));

    }
    else{
        list_commande = listCommandeJourSnackPersone(date_debus, date_fin, type_snack, type_personne);

        prix = CommandePrixJourPersonneSnack(date_debus, date_fin, type_snack, type_personne);
        prix_achat = CommandePrixAchatJourPersonneSnack(date_debus, date_fin, type_snack, type_personne);
        prix_spes = CommandePrixJourPersonneSnackSpesific(date_debus, date_fin, type_snack, type_personne, occurrence);
        prix_achat_spes = CommandePrixAchatJourPersonneSnackSpesific(date_debus, date_fin, type_snack, type_personne);

        wxString afichage_prix = wxString::Format("Total des commande contenant %s et faite par %s : %5.2f \nprix d'achat %5.2f et benefice %5.2f",wxString(type_snack), wxString(type_personne), prix, prix_achat, prix-prix_achat);
        wxString afichage_prix_specific = wxString::Format("Total des %s vendu par %s et de %5.2f pour %d \net a un prix d'achat de %5.2f et un benefice de %5.2f",wxString(type_snack), wxString(type_personne), prix_spes, occurrence, prix_achat_spes, prix_spes-prix_achat_spes);

        journalier_sizer->Add(new wxStaticText(this, -1, afichage_prix));
        journalier_sizer->Add(new wxStaticText(this, -1, afichage_prix_specific));
    }


    Historique* histo;
    for(string s : list_commande){
        wxString wxs = wxString(s);
        histo = new Historique(scrole_historique, wxs, this);
        if(mode_utilisateur)
            histo->MoodUtilisateur();
        historiques_journer.push_back(histo);
        historique_sizer->Add(histo, 0, wxALL | wxEXPAND);
        this->Layout();
    }
    scrole_historique->SetScrollbars(1, 1, 0, 0);
    scrole_historique->SetSizer(historique_sizer);
    historique_sizer->Fit(scrole_historique);

    // Activer les barres de défilement
    scrole_historique->SetScrollbars(20, 20, 50, 50);
    scrole_historique->EnableScrolling(true, true);

    journalier_sizer->Add(scrole_historique, 1, wxEXPAND);
    //SetSizerAndFit(journalier_sizer);
    this->SetSizer(journalier_sizer);
}

void Journalier::SupprimerHistorique(Historique* historique) {
    // Parcours de tous les éléments du sizer
    for (unsigned int i = 0; i < historique_sizer->GetItemCount(); i++) {
        // Obtention de l'élément sizer correspondant
        wxSizerItem* item = historique_sizer->GetItem(i);
        // Comparaison du pointeur
        if (item->GetWindow() == historique) {
            // Suppression de l'élément du sizer
            historique_sizer->Remove(i);
            // Suppression de l'élément du vecteur de historiques
            auto it = find(historiques_journer.begin(), historiques_journer.end(), historique);
            if (it != historiques_journer.end()) {
                historiques_journer.erase(it);
            }
            // Destruction de l'objet historique
            historique->Destroy();
            break;
        }
    }
    historique_sizer->Layout();
}