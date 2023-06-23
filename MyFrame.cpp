#include "MyFrame.hpp"



MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    
    //mode d'axer
    mood_utilisateur = true;

    //Menu de l'aplications
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_MOOD_ADMIN, "&Mode Admine\tCtrl-A", "Passer laplications en mode Administrateur.");
    menuFile->Append(ID_MOOD_UTILISATEUR, "&Mode Utilisateur\tCtrl-U", "Passer laplications en mode Utilisateur.");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "&Quitter\tCtrl-Q", "Quitte l'aplication.");
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    
    // Création du panel d'affichage
    panelAffichage = new wxPanel(this, -1);
    //les box
    sizer_init = new wxBoxSizer(wxVERTICAL);
    sizer_categorie = new wxBoxSizer(wxHORIZONTAL);
    sizer_comende = new wxBoxSizer(wxHORIZONTAL);
    //les static box
    //les commande des client
    membres = new Membre(panelAffichage);
    commande = new Commande(panelAffichage, membres);
    //les categorie darticle proposer
    static_boison = new Categorie(panelAffichage, "boisson", commande);
    static_snack = new Categorie(panelAffichage, "snack", commande);
    static_nouie = new Categorie(panelAffichage, "nouille", commande);
    static_diver = new Categorie(panelAffichage, "autre", commande);

    //la line
    wxStaticLine* ligneHoriz = new wxStaticLine(panelAffichage, -1);
    // ajour:
    //les aurgnisatons des stoke
    sizer_init->Add(sizer_categorie, 10, wxALL | wxEXPAND, 0);

    sizer_categorie->Add(static_boison, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_snack, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_nouie, 1, wxALL | wxEXPAND, 5);
    sizer_categorie->Add(static_diver, 1, wxALL | wxEXPAND, 5);
    
    
    sizer_comende->Add(membres, 0, wxALL | wxEXPAND, 0);

    
    sizer_comende->Add(commande, 0, wxALL | wxEXPAND, 0);
    
    //separations
    sizer_init->Add(ligneHoriz, 0, wxALL | wxEXPAND, 0);

    // vendre a une persone
    sizer_init->Add(sizer_comende, 4, wxALL | wxEXPAND, 0);
    panelAffichage->SetSizer(sizer_init);
    this->Bind(wxEVT_MENU, [this](wxCommandEvent & evt)->void{ OnAdmin(); }, ID_MOOD_ADMIN);
    this->Bind(wxEVT_MENU, [this](wxCommandEvent & evt)->void{OnUtilisateur();}, ID_MOOD_UTILISATEUR);
    this->Bind(wxEVT_MENU, [this](wxCommandEvent & evt)->void{OnExit();}, wxID_EXIT);
    OnUtilisateur();
}


void MyFrame::OnExit()
{
    Close( true );
}

void MyFrame::OnAdmin()
{
    wxTextEntryDialog code_is(panelAffichage, wxT("Entre le code administrateur"), wxT("Administrateur"));

    wxString nom = "code";

    if (code_is.ShowModal() == wxID_OK && nom == code_is.GetValue())
    {
        DesactiveAdmin();
        static_boison->MoodAdmin();
        static_snack->MoodAdmin();
        static_nouie->MoodAdmin();
        static_diver->MoodAdmin();
        membres->MoodAdmin();
        commande->MoodAdmin();
    }
    code_is.Destroy();
}

void MyFrame::OnUtilisateur()
{
    DesactiveUtilisateur();
    static_boison->MoodUtilisateur();
    static_snack->MoodUtilisateur();
    static_nouie->MoodUtilisateur();
    static_diver->MoodUtilisateur();
    membres->MoodUtilisateur();
    commande->MoodUtilisateur();
}

void MyFrame::DesactiveUtilisateur(){
    wxMenuBar* menuBar = GetMenuBar();
    if (menuBar && menuBar->GetMenuCount() > 0)
    {
        wxMenu* menu1 = menuBar->GetMenu(0);
        if (menu1)
        {
            menu1->Enable(ID_MOOD_UTILISATEUR, false);
        }
        wxMenu* menu2 = menuBar->GetMenu(0);
        if (menu2)
        {
            menu2->Enable(ID_MOOD_ADMIN, true);
        }
    }
}
void MyFrame::DesactiveAdmin(){
    wxMenuBar* menuBar = GetMenuBar();
    if (menuBar && menuBar->GetMenuCount() > 0)
    {
        
        wxMenu* menu1 = menuBar->GetMenu(0);
        if (menu1)
        {
            menu1->Enable(ID_MOOD_UTILISATEUR, true);
        }
        wxMenu* menu2 = menuBar->GetMenu(0);
        if (menu2)
        {
            menu2->Enable(ID_MOOD_ADMIN, false);
        }
    }
}
