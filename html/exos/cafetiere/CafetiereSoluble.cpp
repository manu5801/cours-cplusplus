
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

#include "CafetiereSoluble.hpp"


void CafetiereSoluble::faireLeCafe(doses_t e, doses_t c) {
    string msg;
    e = eau.prelever(e, msg);
    cerr << msg << "\n";
    c = cafe.prelever(c, msg);
    cerr << getIds() << msg << "\n";
    cerr << getIds() << "CAFETIERE CAFE SOLUBLE Touillage - plop\n";
    cerr << getIds() << "CAFETIERE CAFE SOLUBLE Votre café est prêt\n";
}

doses_t CafetiereSoluble::remplirCafe(doses_t c) {
    string msg;
    c = cafe.remplir(c, msg);
    cerr << getIds() << msg << "\n";
    return c;
}
