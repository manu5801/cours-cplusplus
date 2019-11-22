
#ifndef __ECRET__
#define __ECRET__

#include "tableau.hpp"

// Un objet-fonction qui ecrete le tableau, derive de ofct_1p
template<class T=float> class ecret: public Functor1p<T>  {
public:
	ecret(T s) : seuil(s) {};
	T operator()(T) const;
private:
	T seuil;
};

template<class T> T ecret<T>::operator()(T x) const {return (x > seuil) ? seuil : x;}

#endif
