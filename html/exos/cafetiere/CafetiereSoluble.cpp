
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

#include "CafetiereSoluble.hpp"


void CafetiereSoluble::faireLeCafe(doses_t e, doses_t c) {
    string msg;
    doses_t e1 = eau.prelever(e, msg);
    cerr << getIds() << msg << "\n";

    // Si on a prélevé assez d'eau, on la chauffe
    if (e1 == e) {
        chaufferEau(msg);
        cerr << getIds() << msg << "\n";
    }
    doses_t c1 = cafe.prelever(c, msg);
    cerr << getIds() << msg << "\n";
    if (e1!=e || c1!=c) {
        cerr << getIds() << "CAFETIERE CAFE SOLUBLE PROBLEME - Pas de café aujourd'hui, désolé\n";
    }
    else
    {
        cerr << getIds() << "CAFETIERE CAFE SOLUBLE Touillage - plop\n";
        cerr << getIds() << "CAFETIERE CAFE SOLUBLE Votre café est prêt\n";
    }
}

doses_t CafetiereSoluble::remplirCafe(doses_t c) {
    string msg;
    c = cafe.remplir(c, msg);
    cerr << getIds() << msg << "\n";
    return c;
}
