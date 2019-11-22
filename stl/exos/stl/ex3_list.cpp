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
	
	// Creation de la liste c1
	...
	
	// Affichage de c1
	...
		
	// Construction d'une nouvelle liste c2=c1
	...
	
	// L'iterateur itc pointe sur l'element central de la liste
	itc = c2.begin();
	for (int i=0; i<c2.size()/2;i++)
		...
		
	// Suppression d'un bloc de la premiere moitie de l2	
	...
	
	// Affichage de c2
	...
	
	return 0;
}
