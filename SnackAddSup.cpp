#include <pqxx/pqxx>
#include "SnackAddSup.hpp"




string wxStringToString(const wxString& wxStr) {
    return string(wxStr.ToStdString());
}

extern connection C("dbname = mibde user = postgres password = mibde \
hostaddr = 127.0.0.1 port = 5432");

wxString descriptionCommande(wxString date_et_heur)
{
    string s = "La commande continent :\n";
    try {

        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT * "
                     "FROM contenu_vente WHERE date_et_heure = $1";

        // Exécution de la requête avec les paramètres
        result res = txn.exec_params(sql, wxStringToString(date_et_heur));

        // Parcours des résultats et construction de la liste de snacks
        for (auto row : res) {
            
            s += row["nom_snack"].as<string>() + "X" ;
            s += row["occurrence"].as<string>() + "\n";

        }

        sql = "SELECT * FROM vendu_par WHERE date_et_heure = $1";

        res = txn.exec_params(sql, wxStringToString(date_et_heur));

        s += "\nEt vendu par :\n";


        for (auto row : res) {
            s += row["nom"].as<string>() + " " ;
            s += row["prenom"].as<string>() + "\n";
        }
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la descriptions du snack : '%s'", e.what());
    }
    return wxString(s);
}

vector<string> listCommandeJour(string date){
        vector<string> historique = {};

    try {

        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT * "
                     "FROM historique_vente WHERE date_trunc('day', date_et_heure) = $1" ;

        // Exécution de la requête avec les paramètres

        result res = txn.exec_params(sql, date);

        // Parcours des résultats et construction de la liste de snacks
   
        for (auto row : res) {
            string s;
            s = row["date_et_heure"].as<string>();
            historique.push_back(s);
        }
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la récupération des snacks : '%s'", e.what());
    }

    return historique;
}
vector<string> listCommandeJourSnack(string date, string snack){
        vector<string> historique = {};

    try {

        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT * "
                     "FROM contenu_vente WHERE date_trunc('day', date_et_heure) = $1 AND nom_snack = $2" ;

        // Exécution de la requête avec les paramètres

        result res = txn.exec_params(sql, date, snack);

        // Parcours des résultats et construction de la liste de snacks
   
        for (auto row : res) {
            string s;
            s = row["date_et_heure"].as<string>();
            historique.push_back(s);
        }
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la récupération des snacks : '%s'", e.what());
    }

    return historique;
}
vector<string> listCommandeJourPersone(string date, string persone){
        vector<string> historique = {};

    try {
        stringstream ss(persone);
        string nom;
        getline(ss, nom, ' ');
        string prenom;
        getline(ss, prenom, ' ');
        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT * "
                     "FROM vendu_par WHERE date_trunc('day', date_et_heure) = $1 AND nom = $2 AND prenom = $3" ;

        // Exécution de la requête avec les paramètres

        result res = txn.exec_params(sql, date, nom, prenom);

        // Parcours des résultats et construction de la liste de snacks
   
        for (auto row : res) {
            string s;
            s = row["date_et_heure"].as<string>();
            historique.push_back(s);
        }
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la récupération des snacks : '%s'", e.what());
    }

    return historique;
}
vector<string> listCommandeJourSnackPersone(string date,string snack, string persone){
        vector<string> historique = {};

    try {
        stringstream ss(persone);
        string nom;
        getline(ss, nom, ' ');
        string prenom;
        getline(ss, prenom, ' ');
        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT date_et_heure "
                     "FROM vendu_par WHERE date_trunc('day', date_et_heure) = $1 AND nom = $2 AND prenom = $3 INTERSECT SELECT date_et_heure FROM contenu_vente WHERE date_trunc('day', date_et_heure) = $1 AND nom_snack = $4" ;

        // Exécution de la requête avec les paramètres

        result res = txn.exec_params(sql, date, nom, prenom, snack);

        // Parcours des résultats et construction de la liste de snacks
   
        for (auto row : res) {
            string s;
            s = row["date_et_heure"].as<string>();
            historique.push_back(s);
        }
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la récupération des snacks : '%s'", e.what());
    }

    return historique;
}
void updateSnackPrice(const string& nomSnack, double nouveauPrix) {
    try {

        work txn(C);

        string query = "UPDATE SNACK SET PRIX = $2 WHERE NOM_SNACK = $1";
        txn.exec_params(query, nomSnack, nouveauPrix);

        txn.commit();

    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la mise à jour du prix du snack : " << e.what() << endl;
    }
}

void updateSnackStrock(const string& nomSnack, int newStock) {
    try {

        work txn(C);

        string query = "UPDATE SNACK SET  quantite  = $2 WHERE NOM_SNACK = $1";
        txn.exec_params(query, nomSnack, newStock);

        txn.commit();


    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la mise à jour du prix du snack : " << e.what() << endl;
    }
}

void updateTypeA(const string& nomSnack, const string& newTypeA) {
    try {

        // Préparer la requête SQL pour mettre à jour le typeA du snack donné
        string query = "UPDATE SNACK SET TYPEA = $1 WHERE NOM_SNACK = $2";
        work W(C);
        W.exec_params(query, newTypeA, nomSnack);
        W.commit();

        cout << "Le typeA du snack a été mis à jour avec succès !" << endl;
    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la mise à jour du typeA : " << e.what() << endl;
    }
}


bool verifyTypeA(const string& nomSnack, const string& typeA) {
    try {
        // Établir une connexion à la base de données



        // Préparer la requête SQL pour vérifier le typeA du snack donné
        string query = "SELECT COUNT(*) FROM SNACK WHERE NOM_SNACK = $1 AND TYPEA = $2";
        nontransaction N(C);
        result R(N.exec_params(query, nomSnack, typeA));

        // Obtenir le résultat de la requête
        int count = R[0][0].as<int>();

        // Vérifier si le typeA correspond
        return count > 0;
    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la vérification du typeA : " << e.what() << endl;
        return false;
    }
}

void replaceSnack(const string& nomSnack){
    try {
        work txn(C);

        // Construction de la requête SQL de mise à jour
        string sql = "UPDATE SNACK SET en_vente = 1 "
                       "WHERE NOM_SNACK = $1";
        result res = txn.exec_params(sql, nomSnack);

        txn.commit();
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la remise du snack : '%s' ", e.what());
    }
}

void deleteSnack(const string& nomSnack){
    try {
        work txn(C);

        // Construction de la requête SQL de mise à jour
        string sql = "UPDATE SNACK SET en_vente = -1 "
                       "WHERE NOM_SNACK = $1";
        result res = txn.exec_params(sql, nomSnack);

        txn.commit();
        cout << nomSnack << "passe a -1" << endl;
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la supresiont du snack : '%s' ", e.what());
    }
}

void updateSnack(const string& nomSnack, float prix, float prixAchat, const string& description,
                 int quantite, int rupture, const string& cheminVersImage) {
    try {
        work txn(C);

        // Construction de la requête SQL de mise à jour
        string sql = "UPDATE SNACK SET PRIX = $2, PRIX_ACHAT = $3, DESCRIPTION = $4, QUANTITE = $5, "
                       "RUPTURE = $6, CHEMIN_VERS_LIMAGE = $7 "
                       "WHERE NOM_SNACK = $1";
        result res = txn.exec_params(sql, nomSnack, to_string(prix), to_string(prixAchat), description, to_string(quantite),
                                     to_string(rupture), cheminVersImage);

        txn.commit();
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la mise à jour des paramètres du snack : '%s' ", e.what());
    }
}


void deleteSnackPeutContenir(const string& nomSnack) {
    try {

        work txn(C);

        // Construction de la requête SQL pour supprimer les enregistrements
        string sql = "DELETE FROM PEUT_CONTENIR WHERE NOM_SNACK = $1";

        // Exécution de la requête
        result res = txn.exec_params(sql, nomSnack);
        txn.commit();
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la suppression des enregistrements de la table peut_contenir : '%s' ", e.what());
    }
}
// Fonction pour récupérer un snack à partir de son nom
unique_ptr<Snack> exiteSnack(const string& nomSnack) {
    try {

        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT * FROM SNACK WHERE NOM_SNACK = $1 and en_vente = -1";

        // Exécution de la requête
        result res = txn.exec_params(sql, nomSnack);

        // Vérification si le résultat est vide
        if (res.empty()) {
            cerr << "Aucun snack trouvé avec le nom : " << nomSnack << endl;
            return nullptr;
        }

        // Création d'un objet Snack
        auto snack = make_unique<Snack>();
        for (auto row : res) {
            snack->nomSnack = row["NOM_SNACK"].as<string>();
            snack->prix = row["PRIX"].as<float>();
            snack->prixAchat = row["PRIX_ACHAT"].as<float>();
            snack->description = row["DESCRIPTION"].as<string>();
            snack->quantite = row["QUANTITE"].as<int>();
            snack->enVente = row["EN_VENTE"].as<int>();
            snack->rupture = row["RUPTURE"].as<int>();
            snack->typeA = row["TYPEA"].as<string>();
            snack->cheminVersImage = row["CHEMIN_VERS_LIMAGE"].as<string>();
        }
        return snack;
    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la récupération du snack : " << e.what() << endl;
        return nullptr;
    }
}

bool chercheSnack(const string& nomSnack){
    try {

        nontransaction txn(C);

        
        string sql = "SELECT * FROM SNACK WHERE nom_snack = $1";
        result res = txn.exec_params(sql, nomSnack);
        if(res.empty())
            return false;
        return true;

    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la recherche de snack : '%s' ", e.what());
        return true;
    }
}


void addAttributesToSnack(const string& nomSnack, const vector<bool>& attributes) {
    try {

        work txn(C);

        // Vérification de la taille de la liste d'attributs
        if (attributes.size() != 5) {
            cerr << "La liste d'attributs doit contenir exactement 5 éléments." << endl;
            return;
        }

        // Construction de la requête SQL
        string sql = "INSERT INTO PEUT_CONTENIR (CATEGORIE, NOM_SNACK) VALUES ";

        if (attributes[0])
            sql += "('halal', $1), ";
        if (attributes[1])
            sql += "('casher', $1), ";
        if (attributes[2])
            sql += "('vegan', $1), ";
        if (attributes[3])
            sql += "('vegetarien', $1), ";
        if (attributes[4])
            sql += "('recyclabe', $1), ";
        
        // Suppression de la virgule finale
        sql = sql.substr(0, sql.length() - 2);
        // Exécution de la requête
        result res = txn.exec_params(sql, nomSnack);
        txn.commit();

    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de l'ajout des attributs pour le snack : '%s' ", e.what());
    }
}


vector<bool> checkArticleComposition(const string& articleType) {
    vector<bool> composition;

    try {

        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT "
                     "CASE WHEN EXISTS(SELECT * FROM PEUT_CONTENIR WHERE CATEGORIE = 'halal' AND NOM_SNACK = $1) THEN true ELSE false END AS is_halal, "
                     "CASE WHEN EXISTS(SELECT * FROM PEUT_CONTENIR WHERE CATEGORIE = 'casher' AND NOM_SNACK = $1) THEN true ELSE false END AS is_casher, "
                     "CASE WHEN EXISTS(SELECT * FROM PEUT_CONTENIR WHERE CATEGORIE = 'vegan' AND NOM_SNACK = $1) THEN true ELSE false END AS is_vegan, "
                     "CASE WHEN EXISTS(SELECT * FROM PEUT_CONTENIR WHERE CATEGORIE = 'vegetarien' AND NOM_SNACK = $1) THEN true ELSE false END AS is_vegetarien, "
                     "CASE WHEN EXISTS(SELECT * FROM PEUT_CONTENIR WHERE CATEGORIE = 'recyclabe' AND NOM_SNACK = $1) THEN true ELSE false END AS is_recyclable";

        // Exécution de la requête avec le paramètre
        result res = txn.exec_params(sql, articleType);

        // Récupération des résultats
        if (res.size() > 0) {
            auto row = res.front();
            composition.push_back(row["is_halal"].as<bool>());
            composition.push_back(row["is_casher"].as<bool>());
            composition.push_back(row["is_vegan"].as<bool>());
            composition.push_back(row["is_vegetarien"].as<bool>());
            composition.push_back(row["is_recyclable"].as<bool>());
        }
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la vérification de la composition de l'article : '%s' ", e.what());
    }

    return composition;
}

vector<Snack> getSnacks(string categorie) {
    vector<Snack> snacks;

    try {

        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT NOM_SNACK, PRIX, PRIX_ACHAT, DESCRIPTION, QUANTITE, EN_VENTE, RUPTURE, TYPEA, CHEMIN_VERS_LIMAGE "
                     "FROM SNACK WHERE TYPEA = $1 AND EN_VENTE = $2";

        // Exécution de la requête avec les paramètres
        result res = txn.exec_params(sql, categorie, 1);

        // Parcours des résultats et construction de la liste de snacks
        for (auto row : res) {
            Snack snack;
            snack.nomSnack = row["NOM_SNACK"].as<string>();
            snack.prix = row["PRIX"].as<float>();
            snack.prixAchat = row["PRIX_ACHAT"].as<float>();
            snack.description = row["DESCRIPTION"].as<string>();
            snack.quantite = row["QUANTITE"].as<int>();
            snack.enVente = row["EN_VENTE"].as<int>();
            snack.rupture = row["RUPTURE"].as<int>();
            snack.typeA = row["TYPEA"].as<string>();
            snack.cheminVersImage = row["CHEMIN_VERS_LIMAGE"].as<string>();
            snacks.push_back(snack);
        }
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la récupération des snacks : '%s'", e.what());
    }

    return snacks;
}

void createSnack(const string& nomSnack, float prix, float prixAchat, const string& description,
                 int quantite, int enVente, int rupture, const string& typeA, const string& cheminVersImage) {
    try {
        work txn(C);

        string sql = "INSERT INTO SNACK (NOM_SNACK, PRIX, PRIX_ACHAT, DESCRIPTION, QUANTITE, EN_VENTE, RUPTURE, TYPEA, CHEMIN_VERS_LIMAGE) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)";
        result res = txn.exec_params(sql, nomSnack, to_string(prix), to_string(prixAchat), description, to_string(quantite),
                                     to_string(enVente), to_string(rupture), typeA, cheminVersImage);
        // Exécution de la requête directe
        txn.commit();

    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la création du snack : '%s'", wxString(e.what()));
    }
}


void enregistrerPersonne(const string& nom, const string& prenom) {
    try {

        work txn(C);

        string sql = "INSERT INTO PERSONNE (NOM, PRENOM) VALUES ($1, $2)";
        result res = txn.exec_params(sql, nom, prenom);

        txn.commit();

        cout << "La personne a été enregistrée avec succès !" << endl;
    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de l'enregistrement de la personne : " << e.what() << endl;
    }
}

void desactiverPersonne(const string& nom, const string& prenom) {
    try {

        work txn(C);

        string sql = "UPDATE PERSONNE SET ACTIF = -1 WHERE NOM = $1 AND PRENOM = $2";
        result res = txn.exec_params(sql, nom, prenom);

        txn.commit();

        cout << "La personne a été désactivée avec succès !" << endl;
    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la désactivation de la personne : " << e.what() << endl;
    }
}

void ActiverPersonne(const string& nom, const string& prenom) {
    try {

        work txn(C);

        string sql = "UPDATE PERSONNE SET ACTIF = 1 WHERE NOM = $1 AND PRENOM = $2";
        result res = txn.exec_params(sql, nom, prenom);

        txn.commit();

        cout << "La personne a été désactivée avec succès !" << endl;
    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la désactivation de la personne : " << e.what() << endl;
    }
}

bool estInactif(const string& nom, const string& prenom) {
    try {
        nontransaction txn(C);

        string sql = "SELECT ACTIF FROM PERSONNE WHERE NOM = $1 AND PRENOM = $2";
        result res = txn.exec_params(sql, nom, prenom);

        if (res.empty()) {
            // La personne n'a pas été trouvée dans la base de données
            cout << "La personne n'existe pas dans la base de données." << endl;
            return false;
        }

        int actif = res[0][0].as<int>();

        return (actif == -1);
    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la vérification de l'état actif de la personne : " << e.what() << endl;
        return false;
    }
}

bool nomInactif(const string& nom, const string& prenom) {
    try {
        nontransaction txn(C);

        string sql = "SELECT ACTIF FROM PERSONNE WHERE NOM = $1 AND PRENOM = $2";
        result res = txn.exec_params(sql, nom, prenom);

        if (res.empty()) {
            // La personne n'a pas été trouvée dans la base de données
            cout << "La personne n'existe pas dans la base de données." << endl;
            return true;
        }

        int actif = res[0][0].as<int>();

        return (actif == -1);
    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la vérification de l'état actif de la personne : " << e.what() << endl;
        return false;
    }
}

bool notExitePersonne(const string& nom, const string& prenom) {
    try {
        nontransaction txn(C);

        string sql = "SELECT ACTIF FROM PERSONNE WHERE NOM = $1 AND PRENOM = $2";
        result res = txn.exec_params(sql, nom, prenom);

        return res.empty();

    } catch (const exception& e) {
        cerr << "Une erreur s'est produite lors de la vérification de l'état actif de la personne : " << e.what() << endl;
        return false;
    }
}


vector<personne> getPersonnes() {
    vector<personne> personnes;

    try {

        nontransaction txn(C);

        // Construction de la requête SQL
        string sql = "SELECT NOM, PRENOM FROM PERSONNE WHERE ACTIF = 1";

        // Exécution de la requête
        result res = txn.exec(sql);

        // Parcours des résultats et construction de la liste de snacks
        for (auto row : res) {
            personne p;
            p.nom = row["NOM"].as<string>();
            p.prenom = row["PRENOM"].as<string>();
            personnes.push_back(p);
        }
    } catch (const exception& e) {
        wxLogError("Une erreur s'est produite lors de la récupération des snacks : '%s'", e.what());
    }

    return personnes;
} 



