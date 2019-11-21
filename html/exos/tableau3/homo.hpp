
#ifndef __HOMO__
#define __HOMO__

#include "tableau.hpp"

// Un objet-fonction qui fait une homothetie, derive de Functor1p
class homo: ... {
public:
	homo(float f) : facteur(f) {};
    ...
private:
	float facteur;
};

#endif
