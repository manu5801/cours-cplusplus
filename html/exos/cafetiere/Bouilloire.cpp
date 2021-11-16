

#include "Bouilloire.hpp"



void Bouilloire::chaufferEau() const{
    string msg = "coucou";
}

doses_t Bouilloire::remplirEau(doses_t r) {
    string msg;
    r = eau.remplir(r, msg);
    cerr << msg << "\n";
    return r;
}

