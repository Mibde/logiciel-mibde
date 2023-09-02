#include "Historique.hpp"

Historique::Historique(wxScrolledWindow* dialog_parent, wxString date_et_heur, Journalier* journalier) : wxPanel(dialog_parent, -1), journalier(journalier)
{

    this->date_heur = date_et_heur;
    histoirque_sizer = new wxBoxSizer(wxHORIZONTAL);

    static_date_heur = new wxStaticText(this, wxID_ANY, date_et_heur);
    static_date_heur->SetMinSize(wxSize(250, 0));

    wxBitmap sup_bitmap("icon/moin.jpg", wxBITMAP_TYPE_JPEG);
    btn_sup_historique = new wxBitmapButton(this, -1, sup_bitmap);

    
    wxBitmap inf_bitmap("icon/iterrogation.jpg", wxBITMAP_TYPE_JPEG);
    btn_inf_historique = new wxBitmapButton(this, -1, inf_bitmap);

    histoirque_sizer->Add(static_date_heur, 0, wxALL | wxEXPAND, 0);
    histoirque_sizer->Add(btn_sup_historique, 0, wxALIGN_RIGHT| wxEXPAND);
    histoirque_sizer->Add(btn_inf_historique, 0, wxALIGN_RIGHT| wxEXPAND);

    this->SetSizer(histoirque_sizer);
    btn_sup_historique->Bind(wxEVT_BUTTON, &Historique::EventRetireHistorique, this);
    btn_inf_historique->Bind(wxEVT_BUTTON, &Historique::EventInfoHistorique, this);
}

void Historique::EventRetireHistorique(wxCommandEvent& event){
    deletCommande(date_heur);
    journalier->SupprimerHistorique(this);

}

void Historique::EventInfoHistorique(wxCommandEvent& event){
    wxString description = descriptionCommande(date_heur);

    wxMessageDialog* infoDialog = new wxMessageDialog(this, description, "Informations sur la commande " + date_heur, wxOK | wxICON_INFORMATION);
	
	infoDialog->ShowModal();
	infoDialog->Destroy();
}

void Historique::MoodUtilisateur(){
    btn_sup_historique->Enable(false);
}