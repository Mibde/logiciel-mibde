#include "Commande.hpp"

extern connection C;

namespace pqxx {
  template<> struct string_traits<wxString> : public string_traits<char const*>
  {
    static const bool is_null(const wxString& str) noexcept
    {
      return str.IsNull();
    }

    static const char* c_str(const wxString& str) noexcept
    {
      return str.mb_str();
    }
  };
}


Commande::Commande(wxPanel* panel_parent, Membre* membre) : wxBoxSizer(wxHORIZONTAL), membre(membre)
{
    static_sizer_commandes = new wxStaticBoxSizer(wxHORIZONTAL, panel_parent, "Commandes");
    static_sizer_commandes->SetMinSize(wxSize(300, 200));
    this->panel_parent = panel_parent;
    scrole_commandes = new wxScrolledWindow(panel_parent);
    sizer_commandes = new wxBoxSizer(wxVERTICAL);
    
    sizer_valid_info = new wxBoxSizer(wxVERTICAL);
    sizer_prix = new wxBoxSizer(wxHORIZONTAL);
    sizer_monnaie = new wxBoxSizer(wxHORIZONTAL);
    sizer_rendre = new wxBoxSizer(wxHORIZONTAL);
    sizer_anuler_valider = new wxBoxSizer(wxHORIZONTAL);

    affiche_prix = new wxStaticText(panel_parent, -1, "Prix de la commande : 0.00");
    sizer_prix->Add(affiche_prix, 0, wxALL | wxEXPAND, 0);

    monnaie = new wxSpinCtrlDouble(panel_parent, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16384L, 0.0, 100.0, 0.0, 0.01);
    wxStaticText* text_monnaie = new wxStaticText(panel_parent, -1, "Monnaie : ");
    sizer_monnaie->Add(text_monnaie, 0, wxALL | wxEXPAND, 0);
    sizer_monnaie->Add(monnaie, 0, wxALL | wxEXPAND, 0);

    affiche_monnaie_rendu = new wxStaticText(panel_parent, -1, "Monnaie a rendre : 0.00");
    sizer_rendre->Add(affiche_monnaie_rendu, 0, wxALL | wxEXPAND, 0);

    sizer_valid_info->Add(sizer_prix, 0, wxALL | wxEXPAND, 0);
    sizer_valid_info->Add(sizer_monnaie, 0, wxALL | wxEXPAND, 0);
    sizer_valid_info->Add(sizer_rendre, 0, wxALL | wxEXPAND, 0);

    btn_anulation_commande = new wxButton(panel_parent, -1, "anuler");
    btn_validation_commande = new wxButton(panel_parent, -1, "valider");

    sizer_anuler_valider->Add(btn_anulation_commande, 0, wxALL | wxEXPAND, 0);
    sizer_anuler_valider->Add(btn_validation_commande, 0, wxALL | wxEXPAND, 0);

    sizer_valid_info->Add(sizer_anuler_valider, 0, wxALL | wxEXPAND, 0);

    scrole_commandes->SetSizer(sizer_commandes);
    static_sizer_commandes->Add(scrole_commandes, 1, wxALL | wxEXPAND, 0);
    this->Add(static_sizer_commandes, 1, wxALL | wxEXPAND, 0);
    this->Add(sizer_valid_info, 1, wxALL | wxEXPAND, 15);
    monnaie->Bind(wxEVT_SPINCTRLDOUBLE, &Commande::EventMonnaie, this);
    btn_anulation_commande->Bind(wxEVT_BUTTON, &Commande::EventAnulationCommande, this);
    btn_validation_commande->Bind(wxEVT_BUTTON, &Commande::EventValidationCommande, this);
}

void Commande::NewCommande(Article* article)
{
    wxString nom = article->GetNom();
    
    if (commandes.find(article) == commandes.end())
    {
        Produit* new_produit;
        if ((new_produit = new Produit(scrole_commandes, this, nom)))
        {   
            commandes[article] = new_produit;
            sizer_commandes->Add(new_produit, 0, wxALL | wxEXPAND, 0);
            sizer_commandes->Layout();
            scrole_commandes->FitInside();
            scrole_commandes->SetVirtualSize(sizer_commandes->GetSize());
            scrole_commandes->SetScrollRate(5, 5);
        }
        else
        {
            wxLogError("Une ereur et survenus au moment de l'ajous du produit");
        }
    }
    else{
        commandes[article]->AddProduit();
    }
    ReffrechMonnaieARendre();
    ReffrechTotal();
}
double Commande::CalculMonnaie(){
    double totale = CalculTotal();
    double monnaie_a_rendre = 0.0;
    double argent_doner = monnaie->GetValue();
    if(totale < argent_doner){
        monnaie_a_rendre = argent_doner-totale;
    }
    return monnaie_a_rendre;
}
double Commande::CalculTotal(){
    double totale = 0.0;
    for (auto it = commandes.begin(); it != commandes.end(); ++it)
    {
        totale += it->first->GetPrix()*it->second->GetNbProduit();
    }
    return totale;
}
void Commande::ReffrechTotal(){
    wxString afichage = wxString::Format("Prix de la commande : %5.2lf", CalculTotal());
    affiche_prix->SetLabel(afichage);
}
void Commande::ReffrechMonnaieARendre(){
    wxString afichage = wxString::Format("Monnaie a rendre : %5.2lf", CalculMonnaie());
    affiche_monnaie_rendu->SetLabel(afichage);
}
void Commande::EventMonnaie(wxCommandEvent& event){
    ReffrechMonnaieARendre();
}
void Commande::EventValidationCommande(wxCommandEvent& event){
    AjouterVente();  
    Validation();
    ClearCammande();
    ReffrechMonnaieARendre();
    ReffrechTotal();

}

void Commande::EventAnulationCommande(wxCommandEvent& event){
    Anulation();
    ClearCammande();
    ReffrechMonnaieARendre();
    ReffrechTotal();
}

void Commande::Validation(){
    for (auto it = commandes.begin(); it != commandes.end(); ++it)
        it->first->ConfirmeVente();
}
void Commande::Anulation(){
    for (auto it = commandes.begin(); it != commandes.end(); ++it)
        it->first->AnulationsVente();
}

void Commande::ClearCammande(){
    for (auto it = commandes.begin(); it != commandes.end(); ++it)
    {
        // Suppression de l'élément du sizer
        sizer_commandes->Detach(it->second);
            
        // Suppression de l'élément de la map
        Produit* tmp = it->second;
        commandes.erase(it);
            
        // Destruction de l'objet produit
        tmp->Destroy();

    }

    sizer_commandes->Layout();
}

void Commande::SupprimerProduit(Produit* produit) 
{
    AugmentArticle(produit);
    if (produit->GetNbProduit() > 1){
        produit->SupProduit();
    }else{
        DestroyProduit(produit);
    }
    ReffrechMonnaieARendre();
    ReffrechTotal();
}

void Commande::AugmentArticle(Produit* produit){
    for (auto it = commandes.begin(); it != commandes.end(); ++it)
    {
        if (it->second == produit)
        {
            it->first->AnuleProduit();
            break;
        }
    }
}

void Commande::DestroyProduit(Produit* produit)
{
    for (auto it = commandes.begin(); it != commandes.end(); ++it)
    {
        if (it->second == produit)
        {
            // Suppression de l'élément du sizer
            sizer_commandes->Detach(produit);
            
            // Suppression de l'élément de la map
            commandes.erase(it);
            
            // Destruction de l'objet produit
            produit->Destroy();
            break;
        }
    }

    sizer_commandes->Layout();
}

void Commande::MoodUtilisateur(){
    btn_anulation_commande->Enable(true);
    btn_validation_commande->Enable(true);
}

void Commande::MoodAdmin(){
    ClearCammande();
    btn_anulation_commande->Enable(false);
    btn_validation_commande->Enable(false);
}

void Commande::AjouterVente() {
    try {
        vector<pair<string, string>> vendeurs = membre->GetListPersonne();
        work txn(C);

        // Insertion de la vente dans la table HISTORIQUE_VENTE avec la date actuelle
        string insertVente = "INSERT INTO HISTORIQUE_VENTE (DATE_ET_HEURE) VALUES (CURRENT_TIMESTAMP)";
        txn.exec(insertVente);

        // Récupération de la date et heure de la vente insérée
        result res = txn.exec("SELECT DATE_ET_HEURE FROM HISTORIQUE_VENTE ORDER BY DATE_ET_HEURE DESC LIMIT 1");
        string dateVente = res[0][0].as<string>();

        // Insertion des articles vendus dans la table CONTENU_VENTE
        string insertContenuVente = "INSERT INTO CONTENU_VENTE (NOM_SNACK, DATE_ET_HEURE, OCCURRENCE) VALUES ($1, $2, $3)";

        for (auto article = commandes.begin(); article != commandes.end(); ++article){

            txn.exec_params(insertContenuVente, article->first->GetNom(), dateVente, article->second->GetNbProduit());
        }

        // Insertion des vendeurs dans la table VENDU_PAR
        string insertVenduPar = "INSERT INTO VENDU_PAR (DATE_ET_HEURE, NOM, PRENOM) VALUES ($1, $2, $3)";
        for (const auto& vendeur : vendeurs) {
            txn.exec_params(insertVenduPar, dateVente, vendeur.first, vendeur.second);
        }

        txn.commit();

    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de l'ajout de la vente : " << e.what() << std::endl;
    }
}