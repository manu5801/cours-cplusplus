#include <string>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

/* Objet:
	1/ Enveloppe un int
	2/ Il a un constructeur, un constructeur de copie, un operator= et un destructeur.
	   ATTENTION Pour que ça marche avec array il faut un constructeur par défaut (sans paramètre) !
           La méthode fill de array utilisera l'opérator=
*/
class Objet {
public:
   Objet(int x=0): value(x) { cerr << "Hello World I am an Objet " << x << '\n';} ;
   Objet(const Objet& o): value(o.getVal()) {cerr << "Hello World I am a clone " << o.getVal() << '\n'; };
   Objet& operator=(const Objet& o) { cerr << "Aïe J'étais " << value << " Je suis écrasé par " << o.value << '\n'; value = o.value; };
   ~Objet(){cerr << "Bye bye world " << value << '\n';};
   int getVal() const { return value;};

private:
   int value;
};

/*
 * Sortie: si on ne définit pas ça, pas possible d'écrire cout << o !
 */
ostream& operator<<(ostream& os, const Objet& o) {
    os << "Val=" << o.getVal() << '\n';
}

int main() {
	cerr << "On joue avec un array d'Objets\n";
	array<Objet,10> A;
	A.fill(Objet(1000));
	cout << A[5] << '\n';
	A[5] = 6;
	cout << A[5] << '\n';

	cerr << "On joue avec un vecteur d'Objets\n";
	vector<Objet> V;
	V.reserve(10);
	cout << V[5] << '\n';
	V[5] = 6;
	cout << V[5] << '\n';

	cerr << "On joue avec un vecteur d'Objets initialisé à partir d'une liste d'initialisation. Il y aura conversions\n";
	vector<Objet>v1={1,2,3,4,5,6,7,8,9,10};
	cout << v1[5] << '\n';
	v1[5] = 6000;
	cout << v1[5] << '\n';
}
