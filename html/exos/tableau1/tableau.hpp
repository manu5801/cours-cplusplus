#ifndef __TABLEAU__
#define __TABLEAU__

#include <iostream>
using namespace std;

class Tableau {
public:

	// Le constructeur principal - on passe la dimension du tableau en parametre
	explicit Tableau(size_t n);

	// Le trio infernal
	Tableau (const Tableau & t);
	Tableau & operator=(const Tableau &t);
	~Tableau();

	// move
	Tableau(Tableau&& t): A(t.A),sz(t.sz) {t.sz = 0; t.A =NULL; cerr << "constr move\n";};
	Tableau & operator=(Tableau &t) {A=t.A;sz=t.sz,A=NULL;sz=0; cerr << "operateur= move\n"; };

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
	// Ici ce n'est pas la peine, car on utiliser l'opérateur[]
	// friend ostream & operator<<(ostream&, const Tableau&);
 
private:
	size_t sz;
	float *A;
	
	// Le signe __ rappelle qu'il s'agit de methodes privees
	void __copie (float src, float dest[], size_t s);
	void __copie (float src[], float dest[], size_t s);
};

// Une fonction qui n'est pas une methode
// Le prototype ci-dessous fonctionne, mais entraine l'appel de 2 constructuers + 2 destructeurs inutiles !
// Tableau operator+(Tableau t1, Tableau t2);
Tableau  operator+(const Tableau& t1, const Tableau& t2);

// Operateur d'impression, déclaré ici
ostream & operator<<(ostream&, const Tableau&);

void swap(Tableau& t1, Tableau& t2);
#endif
