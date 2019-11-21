#ifndef __TABLEAU__
#define __TABLEAU__

#include <iostream>
#include <initializer_list>
using namespace std;

/*
 * CECI N'EST PAS UN EXERCICE A TROUS !!!!
 * 
 * --> Vous devez modifier le code pour qu'il accepte de compiler
 * 
 */

// Un objet-fonction general, a un parametre
class Functor1p {
public:
    virtual float operator()(float) const = 0;
};

class Tableau {
public:

	// Le constructeur principal - on passe la dimension du tableau en parametre
	explicit Tableau(size_t n=0);
	
	// Initialiser un tableau à partir d'une liste d'initialisation
	Tableau (const initializer_list<float>& l);

	// Le trio infernal
	Tableau (const Tableau &);
	Tableau & operator=(const Tableau &);
	~Tableau();

	// Les deux derniers membres pour faire le quintette infernal
	Tableau (Tableau &&) noexcept;
	Tableau & operator=(Tableau &&) noexcept;

	// renvoie la taille du Tableau
	size_t size() const { return sz;};
	
	// renvoie un element du Tableau sans deborder
	float & operator[](size_t i);
	
	// meme chose - version const
	float operator[](size_t i) const;
	
	// operateurs +=
	// Le parametre est un autre Tableau
	Tableau & operator+=(const Tableau & t);
	
	// Le parametre est un float
	Tableau & operator+=(float x);
	
	// Operateur d'impression, on le déclare souvent comme ami
	// Ici ce n'est pas la peine, car on utilise l'opérateur[]
	// friend ostream & operator<<(ostream&, const Tableau&);
 
	// La famille de fonctions transform: on leur passe un objet-fonction Functor1p
	void transform(const Functor1p& );

private:
	size_t sz;
	float *A;
	
	// Bonne pratique: Le signe __ rappelle qu'il s'agit de methodes privees
	void __copie (float src, float dest[], size_t s);
	void __copie (float src[], float dest[], size_t s);
};

// Une fonction qui n'est pas une methode
// Le prototype ci-dessous fonctionne, mais entraine l'appel de 2 constructuers + 2 destructeurs inutiles !
// Tableau operator+(Tableau t1, Tableau t2);
Tableau operator+(const Tableau& t1, const Tableau& t2);

// Operateur d'impression, déclaré ici
ostream & operator<<(ostream&, const Tableau&);

// -------------> CE QUI SUIT ETAIT JUSQUE LA DANS LE .cpp <------------------

/****
 * Constructeur principal
 * 
 * param: n La taille du tableau en nombre de cellules
 * 
 ********************/
template <typename T> Tableau<T>::Tableau(size_t n): sz(n) {
	cerr << "constructeur sz = " << n << " -> malloc + init\n";
	if (n==0) {
		A = nullptr;
	}
	else {	
		A = (T *) malloc(sz*sizeof(T));
		__copie(0.0,A,sz);
	}
}

/****
 * Constructeur à l'aide d'une liste d'initialisation
 * Tableau t = { 1,2,3 }
 * 
 * param: n La taille du tableau en nombre de cellules
 * 
 ********************/

template<typename T> Tableau<T>::Tableau(const std::initializer_list<T>& l) {
     cerr << "constructeur liste init = -> malloc + init\n";
     sz = l.size();
     size_t i = 0;
     A = (T *) malloc(sz*sizeof(T));
     //for (auto j=l.begin();j!=l.end();++j) {
	 //	 A[i++] = *j;
	 //}
	 for (auto x : l) {
		 A[i++] = x;
	 }
}

/****
 * Constructeur de copie
 * on fait l'alloc de memoire puis on copie les deux zones mémoire
 * 
 * param: t Le tableau à copier
 * 
 *********************/
template<typename T> Tableau<T>::Tableau (const Tableau & t): sz(t.sz) {
	cerr << "constructeur de copie -> malloc + copie" << '\n';
	A = (T *) malloc(sz*sizeof(T));
	__copie(t.A,A,sz);
}

/****
 * Opérateur d'affectation
 * Si les tailles sont identiques, on se contente de copier les zones de mémoire
 * Sinon:
 *    On rend la mémoire au système
 *    On refait l'alloc de mémoire 
 *    On copie les deux zones mémoire
 * 
 * param: t Le tableau à copier
 * return *this
 * 
 *********************/
template<typename T> Tableau<T> & Tableau<T>::operator=(const Tableau<T> &t) {
	cerr << "operateur =" << " -> free + malloc + copie\n";
	if (this==&t)    // Pour gerer les cas A=A
		return *this;

	if (sz != t.sz) {
		// TODO - Utiliser realloc
		free(A);
		sz = t.sz;
		if (sz != 0) A = (T *) malloc(sz*sizeof(T));
	};
	__copie(t.A,A,sz);
	return *this;
}

/****
 * Constructeur de déplacement
 * on se contente de modifier les pointeurs !
 * 
 * param: t Le tableau à copier
 * 
 *********************/
template<typename T>Tableau<T>::Tableau (Tableau<T> && t) noexcept : sz(t.sz) {
	cerr << "constructeur de déplacement -> o" << '\n';
	A = t.A;
	sz= t.sz;
	t.A = nullptr;
	t.sz= 0;
}

/****
 * Opérateur d'affectation/déplacement
 * On libère la mémoire puis on bouge les pointeurs
 *
 * param: t Le tableau à copier
 * return *this
 * 
 *********************/
template<typename T> Tableau<T> & Tableau<T>::operator=(Tableau<T> && t) noexcept {
	cerr << "operateur= déplacement -> free + o" << '\n';
	if (this!=&t)    // Pour gerer les cas A=A
	{
		free(A);
		A = t.A;
		sz= t.sz;
		t.A = nullptr;
		t.sz= 0;
	}
	return *this;
}

/****
 * Destructeur
 * Rendre la mémoire au système
 * 
 *********************/
template<typename T> Tableau<T>::~Tableau() { 
	cerr << "destructeur (sz = " << sz << ") -> free\n";
	if ( A != nullptr) 
	{
		free(A);
		A = nullptr;
	}
}

// renvoie un element du tableau sans deborder
// pas la peine de tester i < 0, size_t est un type unsigned
// (decommentez ce qui suit vous verrez si cela compile)
template<typename T> T & Tableau<T>::operator[](size_t i) {
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
}

// meme chose - version const
template<typename T> T Tableau<T>::operator[](size_t i) const {
	if (i>=sz) {
		cerr << "ATTENTION Debordement de Tableau - je renvoie Tableau[sz-1]\n";
		return A[sz-1];
	} else {
		return A[i];
	};
}

// operateurs +=
// Le parametre est t, un autre Tableau
template<typename T> Tableau<T> & Tableau<T>::operator+=(const Tableau<T> & t) {
	cerr << "operateur+=(const Tableau &) -> += sur une zone mémoire" << '\n';
	if (sz != t.sz) {
		cerr << "Ne peut pas ajouter deux Tableaux de tailles differentes" << '\n'; 
		exit(1);
	} else {
		for (size_t i=0; i < sz; i++) {
			A[i] += t[i];
		};
	};
	return *this;
}

// Le parametre est x, un T
template<typename T> Tableau<T> & Tableau<T>::operator+=(T x) {
	cerr << "operateur+=(T) -> += sur une zone mémoire" << '\n';
	for (size_t i=0; i < sz; i++) {
		A[i] += x;
	};
	return *this;
}

/***********************************
 * copie l'entier src dans la zone memoire pointee par dest
 * 
 * src = L'entier à copier partout
 * dest= La zone memoire de destination
 * s   = La taille de la zone mémoire
 * 
 ****************/
template<typename T> void Tableau<T>::__copie (T src, T dest[], size_t s)
{
	for ( size_t i=0; i<s; i++) {
		dest[i] = src;
	}
}

/***********************************
 * copie une zone mémoire dans une autre
 * 
 * src = La zone mémoire source
 * dest= La zone mémoire destination
 * s   = La taille de la zone mémoire
 * 
 ****************/
template<typename T> void Tableau<T>::__copie (T src[], T dest[], size_t s) {
	for (size_t i=0; i<s; i++) {
		dest[i] = src[i];
	};
}

/***************************
 * Opérateur +
 * 
 * params: t1, t2
 * return: Un tableau retourné par valeur
 * 
 *********************/
template<typename T> Tableau<T> operator+(const Tableau<T>& t1, const Tableau<T>& t2) {
	cerr << "operateur+" << '\n';
	if (t1.size() != t2.size()) {
		cerr << "Ne peut pas ajouter deux Tableaux de tailles differentes" << '\n'; 
		exit(1);
	}
	Tableau<T> s = t1;
	s += t2;
	return s;
}

/*************************
 * Opérateur d'impression
 * 
 * params: os = Le flux de sortie
 *         t  = Le tableau à imprimer
 * 
 * return: Le flux de sortie
 * 
 ******/
template<typename T> ostream & operator<<(ostream& os, const Tableau<T>& t) {
	if (t.size() == 0 ) {
		os << "{}";
		return os;
	}
	
	size_t i_dernier = t.size() - 1;
	os << '{';
	for (size_t i=0; i<i_dernier; ++i) {
		os << t[i] << ',';
	}
	os << t[i_dernier] << '}';
	return os;
}

// Il n'y a plus qu'une seule fonction transform, on lui passe un Functor1p
template<typename T> void Tableau<T>::transform(const Functor1p<T>& f ) {
	for (unsigned int i=0; i< sz; i++) 
		A[i]=f(A[i]);
}


#endif
