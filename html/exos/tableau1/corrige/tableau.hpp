#ifndef __TABLEAU__
#define __TABLEAU__

#include <iostream>
#include <initializer_list>
using namespace std;

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
Tableau operator+(const Tableau& t1, const Tableau& t2);

// Operateur d'impression, déclaré ici
ostream & operator<<(ostream&, const Tableau&);

#endif
