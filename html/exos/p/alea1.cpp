#include <iostream>
#include <cstdlib>
using namespace std;

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

/* Programme principal */
int main(int argc, char* argv[]) {

    /* Teste les erreurs de maniere exhaustive (j'espere...) */
    if (argc==1)
    {
        cerr << "ERREUR - Vous n'avez pas donne la taille du tableau !!!\n";
        return 1;
    }
    if (argc > 2)
    {
        cerr << "ERREUR - Les parametres suivants ne servent a rien:\n";
        for (int i=2; i<argc; i++)
        {
            cerr << argv[i] << '\n';
        }
        return 2;
    }
    
    int taille = atoi(argv[1]);
    if (taille <=0)
    {
        cerr << "ERREUR - La taille doit etre un nombre positif (et pas " << taille << ")\n";
        return 3;
    }

    // On utilise malloc
    int* tableau = (int*) malloc(taille * sizeof(int));
    if (tableau == NULL)
    {
        cerr << "ERREUR - Allocation memoire impossible\n";
        return 4;
    }

    // Initialise le generateur aleatoire        
    srand(time(NULL));

	// Initialise le tableau de maniere aleatoire
	// On choisit une case au hasard et on met 1 dedans
	// On le fait tourner TAILLE/2 fois, tout ne sera donc pas initialise
	for(int i=0;i<taille/2;++i) {
		cella(tableau,taille) = 1;
	}
    
    // imprime le resultat
    imp(tableau,taille);
    cout << endl;
    
    free(tableau);
    
    return 0;
}

