
#include <string>
#include <iostream>
using namespace std;

#include "Cafetiere.hpp"


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

