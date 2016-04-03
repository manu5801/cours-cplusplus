#ifndef __TABLEAU__
#define __TABLEAU__

#include <iostream>
using namespace std;

// Un objet-fonction qui calcule une homothetie
// Le facteur d'homothétie est passé au constructeur de l'objet-fonction
class homo {
public:
    homo(float f) : facteur(f) {};
    float operator()(float x) const {return facteur*x;};
private:
    float facteur;
};

// Un objet-fonction qui ecrete le tableau
// Le seuil est passé au constructeur de l'objet-fonction
class ecret {
public:
    ecret(float s) : seuil(s) {};
    float operator()(float x) const {return (x > seuil) ? seuil : x;};
private:
    float seuil;
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
	
	// La famille de fonctions transform: on leur passe un objet-fonction
	// On est obligé de définir autant de fonctions transform qu'il y a de transformations (d'objets-fonctions) définies
	void transform(const homo& );
	void transform(const ecret &);

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
