#include <iostream>
#include <algorithm> // pour find
#include <vector>
#include <list>

using namespace std;

int main ()
{

	// Avec un tableau initialisé a la liste 10,20,30,40,50
	int tableau[] = ...;
	size_t taille = sizeof(tableau)/sizeof(int);
	int *p;
	
	cout << "Taille de tableau: " << taille << endl;
		
	// Recherchez l'élément 30 dans tab
	p = ...;	
	if (p == (tableau + taille))
		cout << "Element non trouvé !\n";
	else
		cout << "Element trouvé : " << ... << endl;
	
	
	// Avec un vector vec initialisé a la liste 10, 20, 30
	vector<int> ...;
	vector<int>::iterator itV;
	
	// Recherchez l'élément 20 dans vec
	itV = ...;
	if (itV == ... )
		cout << "Element non trouvé !\n";
	else
		cout << "Element trouvé : " << ... << " at position : " << ... <<endl;
		
		
	
	// Avec une liste myList initialisee à la liste 5,19,34,3,33
	list<int> ...;
	list<int>::iterator itL;
	
	// Recherchez l'élément 34 dans la liste
	itL = ...
	if (itL == myList.end())
		cout << "Element non trouvé !\n";
	else {
		const int pos = distance(...,... ) + 1; // position de 34 dans la liste
		cout << "Element trouvé : " << *itL << " at position : " << pos <<endl;
	}
		
		
			
	return 0;
}
