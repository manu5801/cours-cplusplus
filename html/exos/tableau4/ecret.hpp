
#ifndef __ECRET__
#define __ECRET__

#include "tableau.hpp"

// EXERCICE A BUG !

// Un objet-fonction qui ecrete le tableau, derive de ofct_1p
template<class T=float> class ecret: public Functor1p<T>  {
public:
	ecret(T s) : seuil(s) {};
	T operator()(T) const;
private:
	T seuil;
};

float ecret::operator()(float x) const {return (x > seuil) ? seuil : x;}

#endif
