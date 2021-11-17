#pragma once

#include <string>

#include "Cafetiere.hpp"

class Bouilloire: public Cafetiere {

    public:
        doses_t remplirEau(doses_t) override;

    protected:
        ReservoirEau eau;

        pourcent_t getEtatEau()  const override { return eau.getEtat(); };

        void chaufferEau(string& msg) const;
};

