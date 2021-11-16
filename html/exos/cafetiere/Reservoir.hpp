#pragma once

#include <string>
using namespace std;

#include "constypes.hpp"



class Reservoir {
    
    protected:
        virtual doses_t getRemplissage() const = 0;  // Renvoie la quantité de produit restant
        virtual doses_t getCapacite() const = 0;     // Renvoie la capacité du réservoir
        

    public:
        pourcent_t getEtat() const;    // Renvoie le %age de produit restant
        virtual doses_t prelever(doses_t, string&) = 0; // Sort une ou plusieurs doses (si possible)
        virtual doses_t remplir(doses_t, string&) = 0;  // Remplit le réservoir
};
