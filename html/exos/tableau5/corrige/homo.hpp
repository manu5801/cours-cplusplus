
#ifndef __HOMO__
#define __HOMO__

#include "tableau.hpp"

// Un objet-fonction qui fait une homothetie, derive de Functor1p
template<typename T=float> class homo: public Functor1p<T> {
public:
	homo(T f) : facteur(f) {};
	T operator()(T) const;
private:
	T facteur;
};

template <typename T> T homo<T>::operator()(T x) const {return facteur*x;}


#endif
