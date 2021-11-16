
#include "Cafetiere.hpp"
#include "Bouilloire.hpp"
#include "ReservoirSoluble.hpp"







class CafetiereSoluble: public Bouilloire {
    public:
        void faireLeCafe(doses_t eau, doses_t cafe) override;
        doses_t remplirCafe(doses_t) override;

    protected:
        pourcent_t getEtatCafe() const override { return cafe.getEtat(); };

    private:
        ReservoirSoluble cafe;
};

