
#pragma once
#include <iostream>
#include <sstream>
using namespace std;

#include "constypes.hpp"
#include "ReservoirEau.hpp"


class Cafetiere {
    public:
        virtual void faireLeCafe(doses_t eau, doses_t cafe) = 0;
        string getEtat();
        virtual doses_t remplirEau(doses_t) = 0;
        virtual doses_t remplirCafe(doses_t) = 0;

    protected:
        virtual pourcent_t getEtatEau()  const = 0;
        virtual pourcent_t getEtatCafe() const = 0;
};
