#ifndef __TABLEAU__
#define __TABLEAU__

#include <cstdlib>
#include <iostream>
using namespace std;

// Un objet-fonction general, a un parametre
template <typename T=float> class Functor1p {
public:
    virtual T operator()(T) const = 0;
};

template <typename T=float, size_t S=100> class Tableau {
public:

	// Le constructeur principal
	explicit Tableau();
	
	// Le trio infernal: ON N'EN N'A PAS BESOIN !!!

	// Le constructeur de conversion
	template <typename U> Tableau (const Tableau<U,S>&);

	// renvoie la taille du Tableau
	size_t size() const { return S;};
	
	// renvoie un element du Tableau sans deborder
	T & operator[](size_t i);
	
	// meme chose - version const
	T operator[](size_t i) const;
	
	// operateurs +=
	// Le parametre est un autre Tableau
	Tableau & operator+=(const Tableau & );
	
	// Le parametre est un T
	Tableau & operator+=(T );
	
	// imprime le Tableau sur la sortie standard
	void print () const;
	
	// La fonction transform: on leur passe un objet-fonction à 1 paramètre
	void transform(const Functor1p<T>& );
	

private:
	T A[S];
	
	// Le signe __ rappelle qu'il s'agit de methodes privees
	void __copie (T src, T dest[]);
	void __copie (T src[], T dest[]);
};

// Une fonction qui n'est pas une methode
template < typename T,size_t S> Tableau<T, S> operator+(const Tableau<T, S>& t1, const Tableau<T, S>& t2);

// Le constructeur principal - pas d'allocation memoire a faire !
template <typename T,size_t S> Tableau<T, S>::Tableau() {
	cerr << "constructeur sz = " <<  S << '\n';
	__copie(0.0,A);
};

// CE QUI SUIT ETAIT JUSQUE LA DANS LE .cpp

template <typename T,size_t S> template <typename U> Tableau<T,S>::Tableau (const Tableau<U,S>& t) {
	//__copie(t.A,A); // Ne compile pas car t.A est PRIVATE
	for (size_t i=0; i<S; ++i) {
		A[i] = t[i];
	}
}

// renvoie un element du tableau sans deborder
// pas la peine de tester i < 0, size_t est un type unsigned
// (decommentez ce qui suit vous verrez si cela compile)
template <typename T,size_t S> T & Tableau<T, S>::operator[](size_t i) {
	//if (i<0) {
	//  cerr << "ATTENTION Debordement de tableau - je renvoie tableau[0]\n";
	//  return *A;
	//} else
	if (i>= S) {
		cerr << "ATTENTION Debordement de Tableau - je renvoie Tableau[sz-1]\n";
		return A[S-1];
		// return *(A+sz-1);  // Une autre manière d'écrire la même chose
	} else {
		return A[i];
		//return *(A+i);
	};
};

// meme chose - version const
template <typename T, size_t S> T Tableau<T, S>::operator[](size_t i) const {
	if (i>= S) {
		cerr << "ATTENTION Debordement de Tableau - je renvoie Tableau[sz-1]\n";
		return A[S-1];
	} else {
		return A[i];
	};
};

// operateurs +=
// Le parametre est un autre Tableau
template <typename T,size_t S> Tableau<T, S> & Tableau<T, S>::operator+=(const Tableau<T, S> & t) {
	for (size_t i=0; i <  S; i++) {
		A[i] += t[i];
	};
	return *this;
};

// Le parametre est un T
template <typename T,size_t S> Tableau<T, S> & Tableau<T, S>::operator+=(T x) {
	for (size_t i=0; i <  S; i++) {
		A[i] += x;
	};
	return *this;
};

// imprime le Tableau sur la sortie standard
template <typename T,size_t S> void Tableau<T, S>::print () const  {
	for (size_t i=0; i < S; i++) {
		cout << A[i] << " ";
	};
	cout << '\n';
}

// copie l'entier src dans la zone memoire pointee par dest
template <typename T,size_t S> void Tableau<T, S>::__copie (T src, T dest[])
{
	for ( size_t i=0; i< S; i++) {
		dest[i] = src;
	}
}
template <typename T,size_t S> void Tableau<T, S>::__copie (T src[], T dest[]) {
	for (size_t i=0; i< S; i++) {
		dest[i] = src[i];
	};
}

// La famille de fonction transform: on lui passe un objet-fonction derive de Functor1p
template <typename T,size_t S> void Tableau<T, S>::transform(const Functor1p<T>& f ) {
	for (int i=0; i<  S; i++) 
		A[i]=f(A[i]);
};

template <typename T,size_t S> Tableau<T, S> operator+(const Tableau<T, S>& t1, const Tableau<T, S>& t2) {
	Tableau<T,S> s;
	s = t1;
	s += t2;
	return s;
};

#endif
