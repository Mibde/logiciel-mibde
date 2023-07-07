#include "Membre.hpp"

Membre::Membre(wxPanel* panel_parent) : wxStaticBoxSizer(wxVERTICAL, panel_parent, "Membres")
{
    is_not_check = true;

    this->SetMinSize(wxSize(300, 200));
    this->panel_parent = panel_parent;
    scrole_membres = new wxScrolledWindow(panel_parent);
    sizer_membres = new wxBoxSizer(wxVERTICAL);

    sizer_membres_button = new wxBoxSizer(wxHORIZONTAL);
    ajoute_personne = new wxButton(panel_parent, -1, "ajoute");
    sizer_membres_button->Add(ajoute_personne, 1);

    scrole_membres->SetSizer(sizer_membres);
    this->Add(scrole_membres, 1, wxALL | wxEXPAND, 0);
    this->Add(sizer_membres_button, 0, wxEXPAND, 0);
    InitPersonnes();
    ajoute_personne->Bind(wxEVT_BUTTON, &Membre::NewMembre, this);

}
void Membre::InitCommande(Commande* commande){
    this->commande = commande;
}
void Membre::InitStatistiques(Statistiques* statistiques){
    this->statistiques = statistiques;
}
void Membre::InitPersonnes(){
    vector<personne> personnes = getPersonnes();

    Personne* new_personne;
    
    for(personne p : personnes){
        
        if(new_personne = new Personne(scrole_membres, this, p.nom, p.prenom)){
            membres.push_back(new_personne);
            sizer_membres->Add(new_personne, 0, wxALL | wxEXPAND, 0);
            sizer_membres->Layout();
            scrole_membres->FitInside();
            scrole_membres->SetVirtualSize(sizer_membres->GetSize());
            scrole_membres->SetScrollRate(5, 5);
        }
    }
}
void Membre::NewMembre(wxCommandEvent& event)
{
    wxTextEntryDialog nom_is(this->panel_parent, wxT("Le Nom du nouvaus menbre"), wxT("Ajouter un membre"));
    wxTextEntryDialog prenom_is(this->panel_parent, wxT("Le Prenom du nouvaus menbre"), wxT("Ajouter un membre"));
    string nom;
    string prenom;
    if (nom_is.ShowModal() == wxID_OK && prenom_is.ShowModal() == wxID_OK)
    {
        nom = wxStringToString(nom_is.GetValue());
        prenom = wxStringToString(prenom_is.GetValue());
        if(nom != "" && prenom != ""){
            Personne* new_personne;
            if (nomInactif(nom, prenom) && (new_personne = new Personne(scrole_membres, this, nom, prenom)))
            {
                membres.push_back(new_personne);
                sizer_membres->Add(new_personne, 0, wxALL | wxEXPAND, 0);
                sizer_membres->Layout();
                scrole_membres->FitInside();
                scrole_membres->SetVirtualSize(sizer_membres->GetSize());
                scrole_membres->SetScrollRate(5, 5);
                if(estInactif(nom, prenom))
                    ActiverPersonne(nom, prenom);

                if (notExitePersonne(nom, prenom))
                    enregistrerPersonne(nom, prenom);
                statistiques->UpdateSelectionPersonne();
            }
        }
        
    }
    nom_is.Destroy();
    prenom_is.Destroy();
}

void Membre::SupprimerPersonne(Personne* personne) {
    // Parcours de tous les éléments du sizer
    for (unsigned int i = 0; i < sizer_membres->GetItemCount(); i++) {
        // Obtention de l'élément sizer correspondant
        wxSizerItem* item = sizer_membres->GetItem(i);
        // Comparaison du pointeur
        if (item->GetWindow() == personne) {
            // Suppression de l'élément du sizer
            sizer_membres->Remove(i);
            // Suppression de l'élément du vecteur de personnes
            auto it = find(membres.begin(), membres.end(), personne);
            if (it != membres.end()) {
                membres.erase(it);
            }
            // Destruction de l'objet personne
            personne->Destroy();
            break;
        }
    }
    statistiques->UpdateSelectionPersonne();
    sizer_membres->Layout();
}

void Membre::MoodAdmin(){
    ajoute_personne->Enable(true);
    for(Personne* art : membres){
        art->MoodAdmin();
    }
}
void Membre::MoodUtilisateur(){
    ajoute_personne->Enable(false);
    for(Personne* art : membres){
        art->MoodUtilisateur();
    }
}

vector<pair<string, string>> Membre::GetListPersonne(){
    vector<pair<string, string>> vendeurs;
    for(Personne* p : membres){
        if(p->Check()){
            vendeurs.push_back(p->GetNom());
        }
    }
    return vendeurs;
}

bool Membre::Check(){
    bool cocher = false;
    for(Personne* p : membres){
        cocher |= p->Check();
    }
    return cocher;
}

void Membre::JustOnePersonne(){
    if(mode_commande){
        bool check = Check();
        if(is_not_check && check){
            commande->MoodUtilisateur();
            is_not_check = false;
        }else if(!is_not_check && !check){
            commande->MoodAdmin();
            is_not_check = true;
        }
    }
    
} 
bool Membre::GetIsNotCheck(){
    return is_not_check;
}
void Membre::ModeCommandeAdmin(){
    mode_commande = false; 
}
void Membre::ModeCommandeUse(){
    mode_commande = true;
}

wxArrayString Membre::NomPersonnes(){
    wxArrayString nom_prenom;
    nom_prenom.Add(wxString("Toute les personnes"));
    for(Personne* p : membres){
        nom_prenom.Add(p->Afiche());
    }
    return nom_prenom;
}