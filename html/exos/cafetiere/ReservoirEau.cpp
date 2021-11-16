
#include "ReservoirEau.hpp"


// Remplir le réservoir d'eau
doses_t ReservoirEau::remplir(doses_t r, string& msg) {

    // On AJOUTE r doses à notre réservoir d'eau si possible
    // Si r == 0, on le remplit complètement
    if (r == 0)
    {
        r = CAPA_EAU - remplissage;
    }
    if (remplissage >= CAPA_EAU) return 0;
    
    if (r + remplissage > CAPA_EAU) {
        r = CAPA_EAU - remplissage;
    }  
    msg = "RESERVOIR EAU          Ajout de " + to_string(r) + " volumes d'eau - pshiiiiiiiiiiiit";
    usleep(SLEEP_REMPL_EAU);

    remplissage += r;
    return r;
}

// Prélever p doses d'eau chaude
doses_t ReservoirEau::prelever(doses_t p, string& msg) {

    if ( p > remplissage )
    {
        p = remplissage;
    }

    remplissage -= p;
    msg = "RESERVOIR EAU          Prélèvement de " + to_string(p) + " volumes d'eau -";
    for (doses_t i=0; i<p; ++i)
    {
        msg += " pshit!";
    }
    usleep( p * SLEEP_PRELE_EAU );
    return p;
}
