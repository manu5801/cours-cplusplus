
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


/**********
 * Imprime le tableau passé en paramètres
 * 
 * params:
 *    msg Message à imprimer
 *    A   Adresse de base d'un tableau alloué
 *    s   Nombre de cellules dans le tableau
 * 
 **********/
void imprimeTableau(string msg, int A[],size_t s) {
	if (s==0)
	{
		cout << "Oups le tableau est vide" << endl;
	}
	else if (s==1)
	{
		cout << setw(20) << msg << " {" << A[0] << "}" << endl;
	}
	else
	{
		cout << setw(30) << msg << " {";
		for (int i=0; i<s-1; i++) 
		{
	        cout << A[i] << ",";
		}
		cout << A[s-1] << "}" << endl;
	};
}

#define DIMENSION 10

// Décommentez ces trois lignes l'une après l'autre
// au fur et à mesure que vous progresserez dans l'exercice

#define NIVEAU1
#define NIVEAU2
#define NIVEAU3

main() {
	// *********************************************************************************
	// On joue avec les tableaux "à la C"
	// Allouer un tableau de int de dimension 10, le remplir et l'imprimer
	int A[DIMENSION]={ 10,20,30,40,50,60,70,80,90};
	imprimeTableau("Tableau initial",A,DIMENSION);
	cout << endl;
	
	// Que se passe-t-il si on déborde par la droite ou par la gauche ?
	// NB - Pour plus de sécurité, on n'essaie qu'en lecture !
	cout << "A[-1] = " << A[-1] << endl;
	cout << "A[10] = " << A[DIMENSION] << endl;
	cout << endl;
	
#ifdef NIVEAU1
	// *********************************************************************************
	// On joue avec les références
	// Déclarer une référence vers l'élément 4 du tableau, et une autre vers l'élément 6
	int &ref4 = A[4];
	int &ref6 = A[6];
	
	// Incrémenter les deux références et imprimer le tableau
	ref4++,ref6++;
	imprimeTableau("References incrementees",A,DIMENSION);
	
	// A-ton le même comportement avec le code suivant ? Pourquoi ?
	int ref8 = A[8];
	ref8++;
	imprimeTableau("Val incrementee",A,DIMENSION);
	cout << endl;

	// Itérer à travers un tableau à la C mais à la mode du C++11
	int B[3] = {0};
	for ( auto& x : B ) {
		x = 6;
	}
	imprimeTableau("Tableau B = ",B,3);
	cout << endl;

#endif
#ifdef NIVEAU2
	// *********************************************************************************
	// On joue avec les pointeurs
	// Déclarer un pointeur vers l'élément 1
	int* ptr2 = A + 1;
	
	// Incrémenter le pointeur
	ptr2++;
	imprimeTableau("Pointeur incremente",A,DIMENSION);
	
	// Incrémenter la valeur pointée 
	(*ptr2)++;
	imprimeTableau("Valeur pointee incrementee",A,DIMENSION);
	cout << endl;

	// Déclarer un second pointeur (ptr4) qui pointera sur rien
	int* ptr4 = nullptr;
	
	// Le faire pointer deux entiers plus loin que ptr1
	ptr4 = ptr2 + 2;
	
	// A combien de distance ptr2 et ptr4 sont-ils ? (en octet, pas en entiers)
	// Attention il faut convertir en char* !
	// En déduire la taille d'un entier
	int distance = (char *)ptr4 - (char*)ptr2;
	int taille   = distance / (ptr4 - ptr2);
	cout << "Taille d'un int d'apres mon calcul = " << taille << " ... et d'apres sizeof = " << sizeof(int) << endl;
	cout << endl;
#endif
#ifdef NIVEAU3
	// On mélange les genres
	// Imprimer l'adresse de ref4, ref6, ptr2, ptr4
	// Imprimer les valeurs correspondantes
	int width = 16;
	cout << "ADRESSES: " << " ref4=" << setw(width) << & ref4 << " ref6=" << setw(width) << & ref6 << " ptr2=" << setw(width) <<  ptr2  << " ptr4=" << setw(width) <<  ptr4  << endl;
	cout << "VALEURS:  " << " ref4=" << setw(width) <<  ref4  << " ref6=" << setw(width) <<  ref6  << " ptr2=" << setw(width) << * ptr2 << " ptr4=" << setw(width) << * ptr4 << endl;	
	cout << endl;
	
	// On joue avec les const !
	// Quelques déclarations bien senties:
	const int* cv_ptr2 = ptr2;
	int* const cp_ptr2 = ptr2;
	const int* const cvp_ptr2 = ptr2;
	
	// Commentez ce qui d'après vous ne compilera pas. 
	// Un point de moins par erreur de compilation !
	cv_ptr2++;
	*cv_ptr2++;
//	(*cv_ptr2)++;
	
//	cp_ptr2++;
//	*cp_ptr2++;
	(*cp_ptr2)++;

//	cvp_ptr2++;
//	*cvp_ptr2++;
//	(*cvp_ptr2)++;
#endif
}
