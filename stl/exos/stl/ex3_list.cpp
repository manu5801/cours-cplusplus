#include <iostream>
#include <list>

using namespace std;

void showlist(list <...> l) 
{ 
    list<char> :: iterator it; 
    for (it = ... ; it != ...; ++it) 
        cout << '\t' << ...; 
    cout << '\n'; 
} 

int main()
{
	char c[10] = {'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j'};
	list<char> c1, c2;
	list<char>::iterator itc;
	
	// Creation de la liste c1 a partir de c
	for (int i=0; i<10; i++)
		c1.push_back(c[i]);
	
	// Affichage de c1
	showvec(c1);
		
	// Affecter c1 à c2
	...
	
	// Faire pointer l'iterateur itc sur l'element central de la liste
	itc = c2.begin();
	for (int i=0; i< .../2; i++)
		...
		
	// Suppression d'un bloc de la premiere moitie de l2	
	c2.erase(...);
	
	// Affichage de c2
	showvec(c2);
	
	return 0;
}
