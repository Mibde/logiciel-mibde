#include "InfoArticle.hpp"

InfoArticle::InfoArticle(wxPanel* parent, const wxString nom) : wxDialog(parent, -1, nom, wxDefaultPosition, wxSize(500, 700)){
    InitInfoArticle(parent, nom, _(""), 0.0, 0.0, 0, 0, vector<bool>{false, false, false, false, false}, _(""));
}

InfoArticle::InfoArticle(wxPanel* parent, const wxString nom, wxString chemin, double prix, double prix_achat, int stock, int rupture, vector<bool> caracteristique_presedente, wxString descriptif) : wxDialog(parent, -1, nom, wxDefaultPosition, wxSize(500, 700)){
    InitInfoArticle(parent, nom, chemin, prix, prix_achat, stock, rupture, caracteristique_presedente, descriptif);
}

void InfoArticle::InitInfoArticle(wxPanel* parent, const wxString nom, wxString chemin, double prix,double prix_achat, int stock, int rupture, vector<bool> caracteristique_presedente, wxString descriptif){
    button_image = new wxButton(this, -1, "Image");
    text_chemin = new wxStaticText(this, -1, chemin);

    sizer_chemin = new wxBoxSizer(wxHORIZONTAL);
    sizer_chemin->Add(button_image, 1);
    sizer_chemin->Add(text_chemin, 1);

    sizer_prix = new wxBoxSizer(wxVERTICAL);
    spin_prix = new wxSpinCtrlDouble(this, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16384L, 0.0, 100.0, prix, 0.01);
    sizer_prix->Add(new wxStaticText(this, -1, "Prix"), 1);
    sizer_prix->Add(spin_prix, 1);

    sizer_prix_achat = new wxBoxSizer(wxVERTICAL);
    spin_prix_achat = new wxSpinCtrlDouble(this, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16384L, 0.0, 100.0, prix_achat, 0.01);
    sizer_prix_achat->Add(new wxStaticText(this, -1, "prix d'achat"), 1);
    sizer_prix_achat->Add(spin_prix_achat, 1);

    sizer_stock = new wxBoxSizer(wxVERTICAL);
    spin_stock = new wxSpinCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16284L, 0, 1000, stock);
    sizer_stock->Add(new wxStaticText(this, -1, "Stock"), 1);
    sizer_stock->Add(spin_stock, 1);

    sizer_rupture = new wxBoxSizer(wxVERTICAL);
    spin_rupture = new wxSpinCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxSize(130,30), 16284L, 0, 1000, rupture);
    sizer_rupture->Add(new wxStaticText(this, -1, "Rupture"), 1);
    sizer_rupture->Add(spin_rupture, 1);
    sizer_caracteristique = new wxBoxSizer(wxVERTICAL);

    const wxString caracteristique[] = {"Halal", "Cacher", "Recyclable", "Vegan", "Vegetarien"};
    check_caracteristique = new wxCheckListBox(this, -1, wxDefaultPosition, wxDefaultSize, 5, caracteristique);
    for(int i = 0; i < 5; i++){
        check_caracteristique->Check(i, caracteristique_presedente[i]);
    }
    
    sizer_caracteristique->Add(new wxStaticText(this, -1, "Caracteristique"), 0);
    sizer_caracteristique->Add(check_caracteristique, 1);

    text_descriptif  = new 	wxTextCtrl (this, -1, descriptif, wxDefaultPosition, wxSize(350, 400), wxTE_MULTILINE);
    sizer_descriptif = new wxBoxSizer(wxVERTICAL);
    sizer_descriptif->Add(new wxStaticText(this, -1, "descriptif"), 1);
    sizer_descriptif->Add(text_descriptif, 1);

    sizer_premier = new wxBoxSizer(wxVERTICAL);

    sizer_premier->Add(sizer_chemin, 1);
    sizer_premier->Add(sizer_prix, 1);
    sizer_premier->Add(sizer_prix_achat, 1);
    sizer_premier->Add(sizer_stock, 1);
    sizer_premier->Add(sizer_rupture, 1);
    sizer_premier->Add(sizer_caracteristique, 1);
    sizer_premier->Add(sizer_descriptif, 1);

    wxStdDialogButtonSizer* ButtonSizer = new wxStdDialogButtonSizer;
    sizer_premier->Add(ButtonSizer, 0, wxALIGN_RIGHT|wxALL, 5);
    wxButton* BtnOk = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition,
    wxDefaultSize, 0);
    BtnOk->SetDefault();
    ButtonSizer->AddButton(BtnOk);
    wxButton* BtnCancel = new wxButton(this, wxID_CANCEL, _("&Cancel"),
    wxDefaultPosition, wxDefaultSize, 0);
    ButtonSizer->AddButton(BtnCancel);
    ButtonSizer->Realize();
    
    //sizer_premier->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL), 0, wxEXPAND | wxALL, 5);


    this->SetSizer(sizer_premier);
    button_image->Bind(wxEVT_BUTTON, &InfoArticle::EventCheminImage, this);
    //BtnCancel->Bind(wxEVT_BUTTON, &InfoArticle::DeleteInfo, this);
}
void InfoArticle::DeleteInfo(wxCommandEvent& event){
    cout << "le suside et une solutions" << endl;
}

wxString InfoArticle::GetDescriptif(){
    return text_descriptif->GetValue();
}

vector<bool> InfoArticle::GetCaracteristique(){
    vector<bool> list_caracterisitque; 
    list_caracterisitque.push_back(check_caracteristique->IsChecked(0));
    list_caracterisitque.push_back(check_caracteristique->IsChecked(1));
    list_caracterisitque.push_back(check_caracteristique->IsChecked(2));
    list_caracterisitque.push_back(check_caracteristique->IsChecked(3));
    list_caracterisitque.push_back(check_caracteristique->IsChecked(4));

    return list_caracterisitque;
}

int InfoArticle::GetRupture(){
    return spin_rupture->GetValue();
}

int InfoArticle::GetStock(){
    return spin_stock->GetValue();
}


double InfoArticle::GetPrix(){
    return spin_prix->GetValue();
}
double InfoArticle::GetPrixAchat(){
    return spin_prix_achat->GetValue();
}
wxString InfoArticle::GetChemin(){

    wxFileInputStream input_stream(text_chemin->GetLabel());
    if (text_chemin->GetLabel() == "" || !input_stream.IsOk()){
        return "/home/simongroc/Bureau/LogicielMIBDE/icon/absent.jpeg";
    }
    else{
        
        return text_chemin->GetLabel();
    }
        
}

void InfoArticle::EventCheminImage(wxCommandEvent& event){
    text_chemin->SetLabel(CheminsDeFicher());
}

wxString InfoArticle::CheminsDeFicher() {
    wxFileDialog openFileDialog(this, _("Open PNG file"), "", "", "PNG files (*.png)|*.png", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
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