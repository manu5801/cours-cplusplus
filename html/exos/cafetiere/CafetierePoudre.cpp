
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

#include "Color.hpp"
#include "CafetierePoudre.hpp"


void CafetierePoudre::faireLeCafe(doses_t e, doses_t c) {
    string msg;
    doses_t e1(0), c1(0);

    e1 = eau.prelever(e, msg);
    cerr << getIds() << msg << "\n";

    // Si on a prélevé assez d'eau, on continue
    bool ok = true;
    if (e1 == e) {
        chaufferEau(msg);
        cerr << getIds() << msg << "\n";
        c1 = cafe.prelever(c, msg);
        cerr << getIds() << msg << "\n";
        if (c1 != c) {
            ok = false;
        }
    }
    else
    {
        ok = false;
    }
    if (ok)
    {
        passerCafe(msg);
        cerr << getIds() << msg << "\n";
        cerr << setColor(Color::green) << setColor(Color::bold) << setColor(Color::green) << getIds() << "CAFETIERE CAFE POUDRE  Votre café est prêt" << setColor(Color::normal) << "\n";
    }
    else
    {
        cerr << setColor(Color::red) << setColor(Color::bold) << getIds() << "CAFETIERE CAFE POUDRE PROBLEME - Pas de café pour l'instant, désolé" << setColor(Color::normal) << "\n";
    }
}


void CafetierePoudre::passerCafe(string & msg) const{
    msg = "CAFETIERE CAFE POUDRE  le café passe - pfuit";
    usleep(SLEEP_TASSE_POUDRE);
}

doses_t CafetierePoudre::remplirCafe(doses_t c) {
    string msg;
    c = cafe.remplir(c, msg);
    cerr << getIds() << msg << "\n";
    return c;
}
