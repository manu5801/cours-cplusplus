#ifndef __TABLEAU__
#define __TABLEAU__

#include <iostream>
#include <initializer_list>

using namespace std;

// Un objet-fonction general, a un parametre
template <typename T=float> class Functor1p {
public:
    virtual T operator()(T) const = 0;
};

template <typename T=float, size_t S=100> class Tableau {
public:

	// Le constructeur principal 
	Tableau();
	
	// Initialiser un tableau à partir d'une liste d'initialisation
	Tableau (const initializer_list<T>& l);

	// renvoie la taille du Tableau
	size_t size() const { return S;};
	
	// renvoie un element du Tableau sans deborder
	T & operator[](size_t i);
	
	// meme chose - version const
	T operator[](size_t i) const;
	
	// operateurs +=
	// Le parametre est un autre Tableau
	Tableau & operator+=(const Tableau & t);
	
	// Le parametre est un float
	Tableau & operator+=(T x);
	
	// Operateur d'impression, on le déclare souvent comme ami
	// Ici ce n'est pas la peine, car on utilise l'opérateur[]
	// friend ostream & operator<<(ostream&, const Tableau&);
 
	// La famille de fonctions transform: on leur passe un objet-fonction Functor1p
	void transform(const Functor1p<T> & );

private:
	T A[S];
	
	// Bonne pratique: Le signe __ rappelle qu'il s'agit de methodes privees
	void __copie (T src, T dest[]);
	void __copie (T src[], T dest[]);
};

// Une fonction qui n'est pas une methode
// Le prototype ci-dessous fonctionne, mais entraine l'appel de 2 constructuers + 2 destructeurs inutiles !
// Tableau operator+(Tableau t1, Tableau t2);
template < typename T, size_t S> Tableau<T> operator+(const Tableau<T,S>& t1, const Tableau<T,S>& t2);

// Operateur d'impression, déclaré ici
template < typename T, size_t S> ostream & operator<<(ostream&, const Tableau<T,S>&);


// -------------> CE QUI SUIT ETAIT JUSQUE LA DANS LE .cpp <------------------

/****
 * Constructeur principal
 * 
 * Pas de paramètre ni d'allocation mémoire, juste initialiser le tableau
 * 
 ********************/
template <typename T, size_t S> Tableau<T,S>::Tableau() {
	cerr << "constructeur - init\n";
	__copie(0.0,A);
}

/****
 * Constructeur à l'aide d'une liste d'initialisation
 * Tableau t = { 1,2,3 }
 * 
 * ATTENTION à ne pas déborder si la liste est trop longue !
 * 
 ********************/

template<typename T,size_t S> Tableau<T,S>::Tableau(const std::initializer_list<T>& l) {
     cerr << "constructeur liste init = -> init\n";
     size_t i = 0;
     //for (auto j=l.begin();j!=l.end();++j) {
	 //	 A[i++] = *j;
	 //}
	 for (auto x : l) {
		 A[i++] = x;
		 if (i>=S) break;
	 }
}

/****
 * PAS de Constructeur de copie
 * Le constructeur de copie du système est suffisant
 * 
 *********************/
/****
 * PAS d'Opérateur d'affectation
 * L'opérateur d'affectation du système fait très bien les choses
 * 
 *********************/
/****
 * PAS DE Constructeur de déplacement
 * car cette classe NE GERE PAS DE RESSOURCES !!! (pas de malloc)
 * 
 *********************/
/****
 * PAS d'Opérateur d'affectation/déplacement
 * car cette classe NE GERE PAS DE RESSOURCES !!! (pas de malloc)
 * cf. ici: https://stackoverflow.com/questions/7885479/move-constructors-and-static-arrays
 * 
 *********************/
/****
 * PAS de Destructeur
 * 
 *********************/

// renvoie un element du tableau sans deborder
// pas la peine de tester i < 0, size_t est un type unsigned
// (decommentez ce qui suit vous verrez si cela compile)
template<typename T, size_t S> T & Tableau<T,S>::operator[](size_t i) {
	//if (i<0) {
	//  cerr << "ATTENTION Debordement de tableau - je renvoie tableau[0]\n";
	//  return *A;
	//} else
	if (i>=S) {
		cerr << "ATTENTION Debordement de Tableau - je renvoie Tableau[S-1]\n";
		return A[S-1];
	} else {
		return A[i];
	};
}

// meme chose - version const
template<typename T,size_t S> T Tableau<T,S>::operator[](size_t i) const {
	if (i>=S) {
		cerr << "ATTENTION Debordement de Tableau - je renvoie Tableau[S-1]\n";
		return A[S-1];
	} else {
		return A[i];
	};
}

// operateurs +=
// Le parametre est t, un autre Tableau
template<typename T,size_t S> Tableau<T,S> & Tableau<T,S>::operator+=(const Tableau<T,S> & t) {
	cerr << "operateur+=(const Tableau &) -> += sur une zone mémoire" << '\n';
	for (size_t i=0; i < S; i++) {
		A[i] += t[i];
	};
	return *this;
}

// Le parametre est x, un T
template<typename T, size_t S> Tableau<T,S> & Tableau<T,S>::operator+=(T x) {
	cerr << "operateur+=(T) -> += sur une zone mémoire" << '\n';
	for (size_t i=0; i < S; i++) {
		A[i] += x;
	};
	return *this;
}

/***********************************
 * copie l'entier src dans la zone memoire pointee par dest
 * 
 * src = L'entier à copier partout
 * dest= La zone memoire de destination
 * 
 ****************/
template<typename T,size_t S> void Tableau<T,S>::__copie (T src, T dest[])
{
	for ( size_t i=0; i<S; i++) {
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
template<typename T,size_t S> void Tableau<T,S>::__copie (T src[], T dest[]) {
	for (size_t i=0; i<S; i++) {
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
template<typename T,size_t S> Tableau<T,S> operator+(const Tableau<T,S>& t1, const Tableau<T,S>& t2) {
	cerr << "operateur+" << '\n';
	Tableau<T,S> s = t1;
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
template<typename T, size_t S> ostream & operator<<(ostream& os, const Tableau<T,S>& t) {
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
template<typename T, size_t S> void Tableau<T,S>::transform(const Functor1p<T>& f ) {
	for (unsigned int i=0; i< S; i++) 
		A[i]=f(A[i]);
}


#endif
