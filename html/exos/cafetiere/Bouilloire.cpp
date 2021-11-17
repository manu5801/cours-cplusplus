
#include <iostream>
using namespace std;

#include "Bouilloire.hpp"


void Bouilloire::chaufferEau(string& msg) const{
    msg = "BOUILLOIRE - CHAUFFAGE DE L'EAU";
}

doses_t Bouilloire::remplirEau(doses_t r) {
    string msg;
    r = eau.remplir(r, msg);
    cerr << getIds() << msg << "\n";
    return r;
}

