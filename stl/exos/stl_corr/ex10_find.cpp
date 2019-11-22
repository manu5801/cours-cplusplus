#include <iostream>
#include <algorithm> // pour find
#include <vector>
#include <list>

using namespace std;

int main ()
{

	// Avec un tableau
	int tableau[] = { 10, 20, 30, 40, 50 };
	size_t taille = sizeof(tableau)/sizeof(int);
	int *p;
	
	cout << "Taille de tableau: " << taille << endl;
		
	// Recherchez l'élément 30 dans tab
	p = find(tableau, tableau + taille, 30);	
	if (p == (tableau + taille))
		cout << "Element non trouvé !\n";
	else
		cout << "Element trouvé : " << *p << endl;
	
	
	// Avec un vector
	vector<int> vec { 10, 20, 30 };
	vector<int>::iterator itV;
	
	// Recherchez l'élément 20 dans vec
	itV = find(vec.begin(), vec.end(), 20);
	if (itV == vec.end())
		cout << "Element non trouvé !\n";
	else
		cout << "Element trouvé : " << *itV << " at position : " << itV-vec.begin() + 1 <<endl;
		
		
	
	// Avec un vector
	list<int> myList{ 5, 19, 34, 3, 33 };
	list<int>::iterator itL;
	
	// Recherchez l'élément 34 dans l
	itL = find(myList.begin(), myList.end(), 34);
	if (itL == myList.end())
		cout << "Element non trouvé !\n";
	else {
		const int pos = distance( myList.begin(), itL ) + 1;
		cout << "Element trouvé : " << *itL << " at position : " << pos <<endl;
	}
		
		
			
	return 0;
}
