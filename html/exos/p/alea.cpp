#include <iostream>
#include <cstdlib>
using namespace std;

#define TAILLE 200

/* Fonction raz: Remet le tableau a zero
   Parametres: A      = tableau, 
               taille = taille du tableau
*/
void raz(int A[], int taille) {
   for(int i=0;i<taille;i++) {
      A[i]=0;
   }
}

/* Fonction imp: imprime le tableau complet
   Parametres: A      = tableau
               taille = taille du tableau
               
*/
void imp(int A[], int taille) {
    for (int i=0;i<taille;i++) {
        cout << A[i];
    };
    cout << "\n";
}

/* Fonction cella: renvoie une CELLule du tableau choisie Aleatoirement, sous forme de lvalue
   Parametres: A      = tableau
               taille = taille du tableau
   renvoie:    la case du tableau
*/

int& cella(int A[], int taille) {
   int z;
   z=rand() % taille;
   return A[z];
}

int main() {

	// Tableau declare de maniere statique
	int A[TAILLE];
    
	// Remet le tableau a zero
	raz(A,TAILLE);

	// Initialise le generateur aleatoire
	// Le resultat sera le meme si on lance le programme plusieurs fois par seconde
	srand(time(NULL));

	// Initialise le tableau de maniere aleatoire
	// On choisit une case au hasard et on met 1 dedans
	// On le fait tourner TAILLE/2 fois, tout ne sera donc pas initialise
	for(int i=0;i<TAILLE/2;++i) {
		cella(A,TAILLE) = 1;
	}

	// imprime le resultat
	imp(A,TAILLE);
	cout << endl;
	
	return 0;
}

