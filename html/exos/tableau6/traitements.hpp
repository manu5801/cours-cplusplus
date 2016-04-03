
#ifndef __TRAITEMENTS__
#define __TRAITEMENTS__

#include "tableau.hpp"

// Un objet-fonction qui fait une homothetie, derive de Functor1p
template <typename T=float> class homo: public Functor1p<T> {
public:
	homo(T f) : facteur(f) {};
	T operator()(T) const;
private:
	T facteur;
};

// Un objet-fonction qui ecrete le tableau, derive de ofct_1p
template <typename T=float> class ecret: public Functor1p<T>  {
public:
	ecret(T s) : seuil(s) {};
	T operator()(T) const;
private:
	T seuil;
};

// CE QUI SUIT ETAIT JUSQUE LA DANS LE .cpp
template <typename T> T homo<T>::operator()(T x) const {return facteur*x;};
template <typename T> T ecret<T>::operator()(T x) const {return (x > seuil) ? seuil : x;};

#endif
