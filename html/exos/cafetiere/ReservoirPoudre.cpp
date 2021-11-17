
#include "ReservoirPoudre.hpp"


// Remplir le réservoir de café en poudre
doses_t ReservoirPoudre::remplir(doses_t r, string& msg) {

    // On AJOUTE r doses à notre réservoir de café si possible
    // Si r == 0, on le remplit complètement
    if (r == 0)
    {
        r = CAPA_POUDRE - remplissage;
    }
    if (remplissage >= CAPA_POUDRE) return 0;
    
    if (r + remplissage > CAPA_POUDRE) {
        r = CAPA_POUDRE - remplissage;
    }  
    msg = "RESERVOIR CAFE POUDRE  Ajout de " + to_string(r) + " doses de café - pfououououououf";
    usleep(SLEEP_REMPL_POUDRE);

    remplissage += r;
    return r;
}

// Prélever p doses de café en poudre
doses_t ReservoirPoudre::prelever(doses_t p, string& msg) {

    doses_t p1 = p;
    if ( p > remplissage )
    {
        p1 = remplissage;
    }

    msg = "RESERVOIR CAFE POUDRE  Prélèvement de " + to_string(p1) + " doses de café -";
    for (doses_t i=0; i<p1; ++i)
    {
        msg += " pfouf!";
    }
    if (p1 == remplissage) {
        msg += " ATTENTION RESERVOIR VIDE !";
    }
    remplissage -= p1;
    usleep( p1 * SLEEP_PRELE_POUDRE );
    return p1;
}
