
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "Cafetiere.hpp"

cafid_t Cafetiere::id_nb = 0;

string Cafetiere::getEtat() {
    pourcent_t etat_eau = getEtatEau();
    string etat = "  ";
    
    if (etat_eau >= 100)
    {
        etat[0] = 'P';
    }
    else
    {
        etat[0] = '0' + etat_eau / 10;
    }

    pourcent_t etat_cafe = getEtatCafe();
    if (etat_cafe >= 100)
    {
        etat[1] = 'P';
    }
    else
    {
        etat[1] = '0' + etat_cafe / 10;
    }

    return etat;
}

string Cafetiere::getIds() const {
    ostringstream oss;
    oss.width(5);
    oss.fill('0');
    oss << id;

    string out = "M-";
    return out + oss.str() + ": ";
}

void Cafetiere::chaufferEau(string& msg) const{
    msg = "CAFETIERE              CHAUFFAGE DE L'EAU";
}

doses_t Cafetiere::remplirEau(doses_t r) {
    string msg;
    r = eau.remplir(r, msg);
    cerr << getIds() << msg << "\n";
    return r;
}
