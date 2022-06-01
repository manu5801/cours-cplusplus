#include <iostream>
#include <deque>
using namespace std;


void showdq(deque <int> g) 
{ 
    deque <int> :: iterator it; 
    for (it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 


int main() 
{
	deque<int> dq; 
	
	// Insertion de 10 a la fin, de 20 en tête, de 30 à la fin et de 15 en 
	// tête
	...
	...;
	...;
	...;
    	
    	// Affichage de dq
    	cout << "The deque dq is : "; 
    	...
  
  	// Taille, element en deuxime position, element en tete du deque et 
  	// a la fin
	cout << "\nTaille : " << ...; 
	cout << "\nElement en deuxieme position : " << ...; 
	cout << "\nElement en tete : " << ...; 
	cout << "\nElement a la fin : " << ...; 
	
	// Suppression de l'element en tete + affichage
	...
	showdq(dq);
  
	// Suppression de l'element a la fin + affichage; 
    	...
    	showdq(dq);
	
	return 0;

