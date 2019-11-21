
#ifndef __HOMO__
#define __HOMO__

#include "tableau.hpp"

// Un objet-fonction qui fait une homothetie, derive de Functor1p
class homo: public Functor1p {
public:
	homo(float f) : facteur(f) {};
	float operator()(float) const;
private:
	float facteur;
};

#endif
