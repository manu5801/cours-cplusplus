#include <iostream> 
#include <iterator> 
#include <vector> 


using namespace std;
 

void showvec(vector <float> v) 
{ 
    vector <float> :: iterator it; 
    for (it = v.begin(); it != ...; ++it) 
        cout << '\t' << ...; 
    cout << '\n'; 
} 
 
 
 
int main() 
{ 
	vector<float> v1,v2;
	
	// Creation de v1 avec des valeurs régulierements reparties entre 0.0 et 10.0
	for( int i=0; i<10;i++)
		v1....(0.1*i);
	
	// Affichage de v1
	showvec(...);
	
	// Copie de v1 dans v2
	v2= ...;
	
	// Sauvegarde de la taille de v2 !! avec pop_back() la taille change
	int s=...
	
	// Suppression element par element de la deuxieme moitie de v2
	for (int i=0; i<s/2; i++)
		...	
	
	// Affichage de v2
	showvec(v2);
	
	return 0;
}
