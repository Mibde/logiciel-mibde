#include <pqxx/pqxx>
#include "SnackAddSup.hpp"

using namespace std;
using namespace pqxx;

connection C("dbname = mibde user = postgres password = mibde \
hostaddr = 127.0.0.1 port = 5432");

void ChercheArticleBD(wxPanel* PanelParend, string NomArticle){
    
    try {
      if (C.is_open()) {
         


      } else {
         cout << "Can't open database" << endl;
         return;
      }
      work demande{C};
         string sql = "SELECT NOM_SNACK FROM SNACK WHERE NOM_SNACK = " + NomArticle;
         
        //for(auto[nom_snack, prix, benefice, description, quantite, en_vente, a_acheter, typea, chemin_vers_limage] : demande.query<string, float, float, string, int, int, int, string, string>(sql));
        
      C.disconnect();
    } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
   }
}