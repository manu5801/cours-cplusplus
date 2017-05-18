#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;






/* Quelques conteneurs */
list<float> L,M;
vector<float> V,W;

/* Des iterateurs de liste */
list<float>::iterator i,j;

/* Des iterateurs de vecteurs */
vector<float>::iterator k,l;

/* Un prédicat: renvoie true si positif */
bool pos(float x) { return x>=0?true:false;}


/* Une fonction génératrice: Pour remplir le conteneur 
   avec des entiers entre -500 et 500 */
float gen() { return (1000.0 *  rand()) / RAND_MAX - 500; }



struct aff_t {           // function object type:
  void operator() (float i) {std::cout << ' ' << i;}
} aff;

/* Affichage du contenu d'un conteneur */
template< typename T> void affichage(const T& l) {
	for_each(l.begin(),l.end(),aff);
	cout << endl;
}


int main()
{
	srand(time(NULL));

	int taille = 10;

	/* Mettre dans la liste 10 fois le meme nombre */
	float random = gen();
	L.insert(L.begin(),taille,random);
	affichage(L);

	/* On peut aussi le faire pour le vecteur */
	// V.insert(V.begin(),taille,random);

	/* Mettre dans le vecteur des nombres aléatoires */
	V.resize(10,0);
	generate(V.begin(),V.end(),gen);

	/* On pourrait aussi le faire pour la liste */
	//L.resize(10,0);
	//generate(L.begin(),L.end(),gen);
	//affichage(L);

	affichage(V);

	/* Combien y a-t-il de nombres > 0 ? */
	int npos = count_if(V.begin(),V.end(),pos); 
	cout << "Il y a " << npos << " nombres > 0\n";

	/* Mettre dans la liste des nombres aléatoires */
	generate(L.begin(),L.end(),gen);
	affichage(L);

	/* Trier les deux conteneurs */
//	sort(L.begin(),L.end());
	L.sort();
	sort(V.begin(),V.end());

	affichage(V);
	affichage(L);

	

	/* Merger les deux conteneurs dans une liste */
	M.resize(L.size()+V.size());
	merge(L.begin(),L.end(),V.begin(),V.end(),M.begin());
	cout << "Et voici M ";
	affichage(M);

	/* ... et dans un vecteur */
	W.resize(L.size()+V.size());
	merge(L.begin(),L.end(),V.begin(),V.end(),W.begin());
	cout << "Et voici W ";
	affichage(W);
}

