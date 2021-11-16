
#include "Reservoir.hpp"




pourcent_t Reservoir::getEtat() const {
    return 100 * getRemplissage() / getCapacite();
};
