#include "Statistiques.hpp"

Statistiques::Statistiques(wxPanel* panel_parent, MyFrame* frame_parent, Membre* membre) : wxStaticBoxSizer(wxVERTICAL, panel_parent, "Statistiques"), frame_parent(frame_parent), membre(membre), panel_parent(panel_parent)
{
    
    date_debus = new wxStaticText(panel_parent, -1, "Date de debus : ");
    date_fin = new wxStaticText(panel_parent, -1, "Date de fin : ");

    date_picker_debus = new wxDatePickerCtrl(panel_parent, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    date_picker_fin = new wxDatePickerCtrl(panel_parent, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    wxDateTime date = date_picker_debus->GetValue();
    str_debus = date.FormatISODate();
    date = date_picker_fin->GetValue();
    str_fin = date.FormatISODate();

    wxArrayString snacks = frame_parent->NomSnacks();
    selection_snack = new wxChoice(panel_parent, -1, wxDefaultPosition, wxDefaultSize, snacks);
    selection_snack->SetSelection(0);

    wxArrayString personne = membre->NomPersonnes();
    selection_personne = new wxChoice(panel_parent, -1, wxDefaultPosition, wxDefaultSize, personne);
    selection_personne->SetSelection(0);

    valide_state = new wxButton(panel_parent, -1, "Valide");

    sizer_debus = new wxBoxSizer(wxHORIZONTAL);
    sizer_fin = new wxBoxSizer(wxHORIZONTAL);

    sizer_debus->Add(date_debus);
    sizer_debus->Add(date_picker_debus);

    sizer_fin->Add(date_fin);
    sizer_fin->Add(date_picker_fin);

    this->Add(sizer_debus);
    this->Add(sizer_fin);
    this->Add(selection_snack);
    this->Add(selection_personne);
    this->Add(valide_state);

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
    str_fin = date.FormatISODate();
}

void Statistiques::EventAficheState(wxCommandEvent& event)
{

    string type_snack = wxStringToString(selection_snack->GetString(selection_snack->GetSelection()));
    string type_personne = wxStringToString(selection_personne->GetString(selection_personne->GetSelection()));

    if(str_debus == str_fin){
        Journalier jour(panel_parent, str_debus, type_snack, type_personne);
        jour.ShowModal();
    }else{

    }
}