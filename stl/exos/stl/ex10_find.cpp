#include <iostream>
#include <algorithm> // pour find
#include <vector>
#include <list>

using namespace std;

int main ()
{

	// Avec un tableau
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
	
	
	// Avec un vector
	vector<int> ...;
	vector<int>::iterator itV;
	
	// Recherchez l'élément 20 dans vec
	itV = ...;
	if (itV == vec.end())
		cout << "Element non trouvé !\n";
	else
		cout << "Element trouvé : " << *itV << " at position : " << ... <<endl;
		
		
	
	// Avec un vector
	list<int> ...;
	list<int>::iterator itL;
	
	// Recherchez l'élément 34 dans l
	itL = ...
	if (itL == myList.end())
		cout << "Element non trouvé !\n";
	else {
		const int pos = ...
		cout << "Element trouvé : " << *itL << " at position : " << pos <<endl;
	}
		
		
			
	return 0;
}
