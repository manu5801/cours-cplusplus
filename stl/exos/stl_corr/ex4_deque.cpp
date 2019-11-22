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
	dq.push_back(10); 
    	dq.push_front(20); 
    	dq.push_back(30); 
    	dq.push_front(15); 
    	
    	// Affichage de dq
    	cout << "The deque dq is : "; 
    	showdq(dq); 
  
  	// Taille, element en deuxime position, element en tete du deque et 
  	// a la fin
	cout << "\ndq.size() : " << dq.size(); 
	cout << "\ndq.at(2) : " << dq.at(2); 
	cout << "\ndq.front() : " << dq.front(); 
	cout << "\ndq.back() : " << dq.back();
	
	// Suppression de l'element en tete + affichage 
	cout << "\ndq.pop_front() : "; 
	dq.pop_front(); 
	showdq(dq); 
  
  	// Suppression de l'element a la fin + affichage;
	cout << "\ndq.pop_back() : "; 
	dq.pop_back(); 
	showdq(dq); 
    	
	
	return 0;
}

