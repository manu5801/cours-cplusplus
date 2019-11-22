#include <iostream>
#include <list>

using namespace std;

void showlist(list <char> l) 
{ 
    list<char> :: iterator it; 
    for (it = l.begin(); it != l.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 

int main()
{
	char c[10] = {'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j'};
	list<char> c1, c2;
	list<char>::iterator itc;
	
	// Creation de la liste c1
	for (int i=0; i<10; i++)
		c1.push_back(c[i]);
	
	// Affichage de c1
	showlist(c1);
		
	// Construction d'une nouvelle liste c2=c1
	c2 = c1;
	
	// Suppression d'un bloc la premiere moitie de l2
	itc = c2.begin();
	for (int i=0; i<c2.size()/2;i++)
		itc++;
		
	c2.erase(c2.begin(),itc);
	
	// Affichage de c2
	showlist(c2);
	
	return 0;
}
