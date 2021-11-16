

//#include <iostream>
//#include <unistd.h>
#include <string>
using namespace std;

#include "constypes.hpp"


/*****************
 * Cette classe implémente un réservoir d'eau, elle dérive de Reservoir
 *
 * UNITES = DOSES NECESSAIRES POUR PREPARER UN EXPRESSO
 *
 ***********************************************************************/

#include "Reservoir.hpp"


class ReservoirPoudre: public Reservoir {
    private:
        doses_t remplissage;    // Etat de remplissage du réservoir

    protected:
        doses_t getRemplissage() const override { return remplissage; };
        doses_t getCapacite()    const override { return CAPA_EAU; };
         
    public:
        doses_t remplir(doses_t, string&) override;
        doses_t prelever(doses_t, string&) override;
};
