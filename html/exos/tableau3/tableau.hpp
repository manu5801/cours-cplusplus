#ifndef __TABLEAU__
#define __TABLEAU__

#include <iostream>
using namespace std;

// Un objet-fonction general, a un parametre
class Functor1p {
public:
    virtual float operator()(float) const = 0;
};

class Tableau {
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
	float & operator[](size_t i);
	
	// meme chose - version const
	float operator[](size_t i) const;
	
	// operateurs +=
	// Le parametre est un autre Tableau
	Tableau & operator+=(const Tableau & );
	
	// Le parametre est un float
	Tableau & operator+=(float );
	
	// imprime le Tableau sur la sortie standard
	void print () const;
	
	// La fonction transform: on leur passe un objet-fonction à 1 paramètre
	void transform(const Functor1p& );

private:
	const size_t sz;
	float *A;
	
	// Le signe __ rappelle qu'il s'agit de methodes privees
	void __copie (float src, float dest[], size_t s);
	void __copie (float src[], float dest[], size_t s);
};

// Une fonction qui n'est pas une methode
Tableau operator+(const Tableau& t1, const Tableau& t2);

#endif
