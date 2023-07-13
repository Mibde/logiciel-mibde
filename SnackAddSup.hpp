#ifndef ASNACKADDSUP_H_INCLUDED
#define ASNACKADDSUP_H_INCLUDED

#include <iostream>
#include <pqxx/pqxx> 
#include <string>
#include <wx/wx.h>
#include <vector>
#include <map>
#include <utility>
#include <Python.h>
#include "Article.hpp"
#include "Produit.hpp"
using namespace std;
using namespace pqxx;

struct Snack {
    string nomSnack;
    float prix;
    float prixAchat;
    string description;
    int quantite;
    int enVente;
    int rupture;
    string typeA;
    string cheminVersImage;
};

struct personne{
    string nom;
    string prenom;
};

string wxStringToString(const wxString& wxStr) ;

void createSnack(const string& nomSnack, float prix, float prixAchat, const string& description,
                 int quantite, int enVente, int rupture, const string& typeA, const string& cheminVersImage);
vector<Snack> getSnacks(string categorie);
vector<bool> checkArticleComposition(const string& articleType);
void addAttributesToSnack(const string& nomSnack, const vector<bool>& attributes);
unique_ptr<Snack> exiteSnack(const string& nomSnack);
void deleteSnackPeutContenir(const string& nomSnack);
void updateSnack(const string& nomSnack, float prix, float prixAchat, const string& description, int quantite, int rupture, const string& cheminVersImage);
void deleteSnack(const string& nomSnack);
void replaceSnack(const string& nomSnack);
bool chercheSnack(const string& nomSnack);

bool verifyTypeA(const string& nomSnack, const string& typeA) ;
void updateTypeA(const string& nomSnack, const string& newTypeA) ;
void updateSnackStrock(const string& nomSnack, int newStock);
void updateSnackPrice(const string& nomSnack, double nouveauPrix);

void enregistrerPersonne(const string& nom, const string& prenom);
void desactiverPersonne(const string& nom, const string& prenom);

bool estInactif(const string& nom, const string& prenom) ;
bool notExitePersonne(const string& nom, const string& prenom);
bool nomInactif(const string& nom, const string& prenom);
void ActiverPersonne(const string& nom, const string& prenom);
vector<personne> getPersonnes();

vector<string> listCommandeJour(string date);
vector<string> listCommandeJourSnack(string date, string snack);
vector<string> listCommandeJourPersone(string date, string persone);
vector<string> listCommandeJourSnackPersone(string date,string snack, string persone);

wxString descriptionCommande(wxString date_et_heur);


#endif