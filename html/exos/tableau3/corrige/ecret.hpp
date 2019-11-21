
#ifndef __ECRET__
#define __ECRET__

#include "tableau.hpp"

// Un objet-fonction qui ecrete le tableau, derive de ofct_1p
class ecret: public Functor1p  {
public:
	ecret(float s) : seuil(s) {};
	float operator()(float) const;
private:
	float seuil;
};

#endif
