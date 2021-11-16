
#pragma once

#include <string>
using namespace std;

#include "constypes.hpp"
#include "ReservoirEau.hpp"

using cafid_t = int;

class Cafetiere {
    public:
        Cafetiere(): id(++id_nb){};

        cafid_t getId() const { return id; };

        string getIds() const;
        
        virtual void faireLeCafe(doses_t eau, doses_t cafe) = 0;
        string getEtat();
        virtual doses_t remplirEau(doses_t) = 0;
        virtual doses_t remplirCafe(doses_t) = 0;

    protected:
        virtual pourcent_t getEtatEau()  const = 0;
        virtual pourcent_t getEtatCafe() const = 0;

    private:
        static cafid_t id_nb;
        cafid_t id;
};
