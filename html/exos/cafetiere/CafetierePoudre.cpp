
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

#include "CafetierePoudre.hpp"


void CafetierePoudre::faireLeCafe(doses_t e, doses_t c) {
    string msg;
    e = eau.prelever(e, msg);
    cerr << getIds() << msg << "\n";
    c = cafe.prelever(c, msg);
    cerr << getIds() << msg << "\n";
    passerCafe(msg);
    cerr << getIds() << msg << "\n";
    cerr << getIds() << "CAFETIERE CAFE POUDRE  Votre café est prêt\n";
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
