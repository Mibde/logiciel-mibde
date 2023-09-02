#include "Statistiques.hpp"

Statistiques::Statistiques(wxPanel* panel_parent, MyFrame* frame_parent, Membre* membre) : wxStaticBoxSizer(wxHORIZONTAL, panel_parent, "Statistiques"), frame_parent(frame_parent), membre(membre), panel_parent(panel_parent)
{
    mode_utilisateur = false;
    date_debus = new wxStaticText(panel_parent, -1, "Date de debut : ");
    date_fin = new wxStaticText(panel_parent, -1, "Date de fin : ");

    date_picker_debus = new wxDatePickerCtrl(panel_parent, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    date_picker_fin = new wxDatePickerCtrl(panel_parent, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    wxDateTime date = date_picker_debus->GetValue();
    str_debus = date.FormatISODate();
    date = date_picker_fin->GetValue();
    wxDateSpan span(1); // Durée d'un jour
    date.Add(span);
    str_fin = date.FormatISODate();

    wxArrayString snacks = frame_parent->NomSnacks();
    selection_snack = new wxChoice(panel_parent, -1, wxDefaultPosition, wxDefaultSize, snacks);
    selection_snack->SetSelection(0);

    wxArrayString personne = membre->NomPersonnes();
    selection_personne = new wxChoice(panel_parent, -1, wxDefaultPosition, wxDefaultSize, personne);
    selection_personne->SetSelection(0);

    valide_state = new wxButton(panel_parent, -1, "Valider");
    valide_state->SetMaxSize(wxSize(100, 50));


    sizer_date = new wxBoxSizer(wxHORIZONTAL);
    sizer_choice = new wxBoxSizer(wxHORIZONTAL);
    sizer_parame = new wxBoxSizer(wxVERTICAL);

    sizer_btn_validation = new wxBoxSizer(wxHORIZONTAL);

    sizer_date->Add(date_debus);
    sizer_date->Add(date_picker_debus, 0, wxRIGHT|wxEXPAND, 100);

    sizer_choice->Add(date_fin);
    sizer_choice->Add(date_picker_fin, 0, wxRIGHT|wxEXPAND, 100);

    
    sizer_date->Add(selection_snack, 0, wxALIGN_RIGHT|wxALL| wxEXPAND);
    sizer_choice->Add(selection_personne, 0, wxALIGN_RIGHT|wxALL| wxEXPAND);
    sizer_parame->Add(sizer_date, 0, wxALL|wxEXPAND, 0);
    sizer_parame->Add(sizer_choice, 0, wxALL|wxEXPAND, 0);
    sizer_btn_validation->Add(valide_state, 1, wxALL|wxEXPAND, 0);
    this->Add(sizer_parame, 0, wxALL|wxEXPAND, 0);
    this->Add(sizer_btn_validation, 0, wxALL|wxEXPAND, 0);

    valide_state->Bind(wxEVT_BUTTON, &Statistiques::EventAficheState, this);
    date_picker_debus->Bind(wxEVT_DATE_CHANGED, &Statistiques::OnDateSelectedDebus, this);
    date_picker_fin->Bind(wxEVT_DATE_CHANGED, &Statistiques::OnDateSelectedFin, this);
}

void Statistiques::UpdateSelectionSnack(){
    selection_snack->Clear();
    wxArrayString snacks = frame_parent->NomSnacks();
    selection_snack->Append(snacks);
    selection_snack->SetSelection(0);
    this->Layout();
}

void Statistiques::UpdateSelectionPersonne(){
    selection_personne->Clear();
    wxArrayString personnes = membre->NomPersonnes();
    selection_personne->Append(personnes);
    selection_personne->SetSelection(0);
    this->Layout();
}

void Statistiques::OnDateSelectedDebus(wxDateEvent& event)
{
    wxDateTime date = event.GetDate();
    str_debus = date.FormatISODate();
}

void Statistiques::OnDateSelectedFin(wxDateEvent& event)
{
    wxDateTime date = event.GetDate();
    wxDateSpan oneDay;
    oneDay.SetDays(1);
    date.Add(oneDay);
    //wxDateSpan span(1); // Durée d'un jour
    //date.Add(span);
    str_fin = date.FormatISODate();
}

void Statistiques::EventAficheState(wxCommandEvent& event)
{

    string type_snack = wxStringToString(selection_snack->GetString(selection_snack->GetSelection()));
    string type_personne = wxStringToString(selection_personne->GetString(selection_personne->GetSelection()));

    
    Journalier jour(panel_parent, str_debus, str_fin, type_snack, type_personne, mode_utilisateur);
    jour.ShowModal();

}

void Statistiques::MoodUtilisateur(){
    mode_utilisateur = true;
}

void Statistiques::MoodAdmin(){
    mode_utilisateur = false;
}