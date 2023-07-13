#include "Journalier.hpp"

Journalier::Journalier(wxPanel* parent, wxString titre, string type_snack, string type_personne) : wxDialog(parent, -1, titre, wxDefaultPosition, wxSize(500, 500))
{
    historique_sizer = new wxBoxSizer(wxVERTICAL);
    journalier_sizer = new wxBoxSizer(wxVERTICAL);

    scrole_historique = new wxScrolledWindow(this);

    string date = wxStringToString(titre);
    
    scrole_historique->SetSizer(historique_sizer);
    vector<string> list_commande;
    if(type_snack == "Tout snacks" && type_personne == "Toute les personnes")
        list_commande = listCommandeJour(date);
    else if(type_personne == "Toute les personnes")
        list_commande = listCommandeJourSnack(date, type_snack);
    else if(type_snack == "Tout snacks") 
        list_commande = listCommandeJourPersone(date, type_personne);
    else
        list_commande = listCommandeJourSnackPersone(date, type_snack, type_personne);
    Historique* histo;
    for(string s : list_commande){
        wxString wxs = wxString(s);
        histo = new Historique(scrole_historique, wxs, this);
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