#include <cstdlib>
#include "tableau.hpp"

// Le constructeur principal - on passe la dimension du tableau en parametre
Tableau::Tableau(size_t n): sz(n) {
	cerr << "constructeur sz = " << n << '\n';
	A = (float *) malloc(sz*sizeof(float));
	__copie(0.0,A,sz);
};

// Le constructeur de copie - on fait l'alloc de memoire puis on copie
Tableau::Tableau (const Tableau & t): sz(t.sz) {
	cerr << "constructeur de copie" << '\n';
	A = (float *) malloc(sz*sizeof(float));
	__copie(t.A,A,sz);
};

// L'operateur = PAS D'ALLOCATION DE MEMOIRE, c'est deja fait !!!
Tableau & Tableau::operator=(const Tableau &t) {
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
Tableau::~Tableau() { 
	cerr << "destructeur (sz = " << sz << ")\n";
	free(A);
};

// renvoie un element du tableau sans deborder
// pas la peine de tester i < 0, size_t est un type unsigned
// (decommentez ce qui suit vous verrez si cela compile)
float & Tableau::operator[](size_t i) {
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
float Tableau::operator[](size_t i) const {
	if (i>=sz) {
		cerr << "ATTENTION Debordement de Tableau - je renvoie Tableau[sz-1]\n";
		return A[sz-1];
	} else {
		return A[i];
	};
};

// operateurs +=
// Le parametre est un autre Tableau
Tableau & Tableau::operator+=(const Tableau & t) {
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

// Le parametre est un entier
Tableau & Tableau::operator+=(float x) {
	for (size_t i=0; i < sz; i++) {
		A[i] += x;
	};
	return *this;
};

// imprime le Tableau sur la sortie standard
void Tableau::print () const  {
	for (size_t i=0; i < sz; i++) {
		cout << A[i] << " ";
	};
	cout << '\n';
}

// copie l'entier src dans la zone memoire pointee par dest
void Tableau::__copie (float src, float dest[], size_t s)
{
	for ( size_t i=0; i<s; i++) {
		dest[i] = src;
	}
}
void Tableau::__copie (float src[], float dest[], size_t s) {
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

// La famille de fonctions transform: on leur passe un objet-fonction
// On est obligé de définir autant de fonctions transform qu'il y a de transformations (d'objets-fonctions) définies
void Tableau::transform(const homo& f ) {
	for (int i=0; i< sz; i++) 
		A[i]=f(A[i]);
};
void Tableau::transform(const ecret& f ) {
	for (int i=0; i< sz; i++) 
		A[i]=f(A[i]);
};

Tableau operator+(const Tableau& t1, const Tableau& t2) {
	Tableau s(t1.size());
	if (t1.size() != t2.size()) {
		cerr << "Ne peut pas ajouter deux Tableaux de tailles differentes" << '\n'; 
		exit(1);
	} else {
		s = t1;
		s += t2;
	};
	return s;
};

