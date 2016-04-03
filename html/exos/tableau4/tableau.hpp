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

template <typename T=float> class Tableau {
public:

	// Le constructeur principal - on passe la dimension du tableau en parametre
	explicit Tableau(size_t );

	// Le trio infernal
	Tableau (const Tableau & );
	Tableau & operator=(const Tableau &);
	~Tableau();

	// renvoie la taille du Tableau
	size_t size() const { return sz;};
	
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
	const size_t sz;
	T *A;
	
	// Le signe __ rappelle qu'il s'agit de methodes privees
	void __copie (T src, T dest[], size_t s);
	void __copie (T src[], T dest[], size_t s);
};

// Une fonction qui n'est pas une methode
template < typename T> Tableau<T> operator+(const Tableau<T>& t1, const Tableau<T>& t2);

// Le constructeur principal - on passe la dimension du tableau en parametre
template <typename T> Tableau<T>::Tableau(size_t n): sz(n) {
	cerr << "constructeur sz = " << n << '\n';
	A = (T *) malloc(sz*sizeof(T));
	__copie(0.0,A,sz);
};

// CE QUI SUIT ETAIT JUSQUE LA DANS LE .cpp

// Le constructeur de copie - on fait l'alloc de memoire puis on copie
template <typename T> Tableau<T>::Tableau (const Tableau<T> & t): sz(t.sz) {
	cerr << "constructeur de copie" << '\n';
	A = (T *) malloc(sz*sizeof(T));
	__copie(t.A,A,sz);
};

// L'operateur = PAS D'ALLOCATION DE MEMOIRE, c'est deja fait !!!
template <typename T> Tableau<T> & Tableau<T>::operator=(const Tableau<T> &t) {
	cerr << "operateur =" << '\n';
	if (this==&t)    // Pour gerer les cas A=A
		return *this;
	
	if (sz != t.sz) {
		cerr << "Ne peut pas egaliser deux tableaux de tailles differentes" << '\n';
		exit(1);
	};
	__copie(t.A,A,sz);
	return *this;
};

// Le destructeur: rendre la memoire au systeme
template <typename T> Tableau<T>::~Tableau() { 
	cerr << "destructeur (sz = " << sz << ")\n";
	free(A);
};

// renvoie un element du tableau sans deborder
// pas la peine de tester i < 0, size_t est un type unsigned
// (decommentez ce qui suit vous verrez si cela compile)
template <typename T> T & Tableau<T>::operator[](size_t i) {
	//if (i<0) {
	//  cerr << "ATTENTION Debordement de tableau - je renvoie tableau[0]\n";
	//  return *A;
	//} else
	if (i>=sz) {
		cerr << "ATTENTION Debordement de Tableau - je renvoie Tableau[sz-1]\n";
		return A[sz-1];
		// return *(A+sz-1);  // Une autre manière d'écrire la même chose
	} else {
		return A[i];
		//return *(A+i);
	};
};

// meme chose - version const
template <typename T> T Tableau<T>::operator[](size_t i) const {
	if (i>=sz) {
		cerr << "ATTENTION Debordement de Tableau - je renvoie Tableau[sz-1]\n";
		return A[sz-1];
	} else {
		return A[i];
	};
};

// operateurs +=
// Le parametre est un autre Tableau
template <typename T> Tableau<T> & Tableau<T>::operator+=(const Tableau<T> & t) {
	if (sz != t.sz) {
		cerr << "Ne peut pas ajouter deux Tableaux de tailles differentes" << '\n'; 
		exit(1);
	} else {
		for (size_t i=0; i < sz; i++) {
			A[i] += t[i];
		};
	};
	return *this;
};

// Le parametre est un T
template <typename T> Tableau<T> & Tableau<T>::operator+=(T x) {
	for (size_t i=0; i < sz; i++) {
		A[i] += x;
	};
	return *this;
};

// imprime le Tableau sur la sortie standard
template <typename T> void Tableau<T>::print () const  {
	for (size_t i=0; i < sz; i++) {
		cout << A[i] << " ";
	};
	cout << '\n';
}

// copie l'entier src dans la zone memoire pointee par dest
template <typename T> void Tableau<T>::__copie (T src, T dest[], size_t s)
{
	for ( size_t i=0; i<s; i++) {
		dest[i] = src;
	}
}
template <typename T> void Tableau<T>::__copie (T src[], T dest[], size_t s) {
	for (size_t i=0; i<s; i++) {
		dest[i] = src[i];
	};
}

// Deux autres manières d'écrire le même code: difficilement lisible, mais on voit ça souvent
/*
void Tableau::copie (float src, float *dest, size_t s) {
	for (size_t i=0; i<s; i++) {
		*(dest++) = src;
	};
};
void Tableau::copie (float *src, float *dest, size_t s) {
	for (size_t i=0; i<s; i++) {
		*(dest++) = *(src++);
	};
}
*/

// La famille de fonction transform: on lui passe un objet-fonction derive de Functor1p
template <typename T> void Tableau<T>::transform(const Functor1p<T>& f ) {
	for (int i=0; i< sz; i++) 
		A[i]=f(A[i]);
};

template <typename T> Tableau<T> operator+(const Tableau<T>& t1, const Tableau<T>& t2) {
	Tableau<T> s(t1.size());
	if (t1.size() != t2.size()) {
		cerr << "Ne peut pas ajouter deux Tableaux de tailles differentes" << '\n'; 
		exit(1);
	} else {
		s = t1;
		s += t2;
	};
	return s;
};


#endif
