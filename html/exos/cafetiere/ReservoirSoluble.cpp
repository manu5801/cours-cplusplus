
#include "ReservoirSoluble.hpp"


// Remplir le réservoir d'eau
doses_t ReservoirSoluble::remplir(doses_t r, string& msg) {

    // On AJOUTE r doses à notre réservoir d'eau si possible
    // Si r == 0, on le remplit complètement
    if (r == 0)
    {
        r = CAPA_SOLUBLE - remplissage;
    }
    if (remplissage >= CAPA_SOLUBLE) return 0;
    
    if (r + remplissage > CAPA_SOLUBLE) {
        r = CAPA_SOLUBLE - remplissage;
    }  
    msg = "RESERVOIR CAFE SOLUBLE Ajout de " + to_string(r) + " doses de café - pfououououououf";
    usleep(SLEEP_REMPL_SOLUBLE);

    remplissage += r;
    return r;
}

// Prélever p doses de café soluble
doses_t ReservoirSoluble::prelever(doses_t p, string& msg) {

    if ( p > remplissage )
    {
        p = remplissage;
    }

    remplissage -= p;
    msg = "RESERVOIR CAFE SOLUBLE Prélèvement de " + to_string(p) + " doses de café -";
    for (doses_t i=0; i<p; ++i)
    {
        msg += " pfouf!";
    }
    usleep( p * SLEEP_PRELE_SOLUBLE );
    return p;
}
