
#ifndef __TRAITEMENTS__
#define __TRAITEMENTS__

#include "tableau.hpp"

// Un objet-fonction qui fait une homothetie, derive de Functor1p
class homo: public Functor1p {
public:
	homo(float f) : facteur(f) {};
	float operator()(float) const;
private:
	float facteur;
};

// Un objet-fonction qui ecrete le tableau, derive de ofct_1p
class ecret: public Functor1p  {
public:
	ecret(float s) : seuil(s) {};
	float operator()(float) const;
private:
	float seuil;
};

#endif
