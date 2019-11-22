#include <iostream> 
#include <iterator> 
#include <vector> 


using namespace std;
 

void showvec(vector <float> v) 
{ 
    vector <float> :: iterator it; 
    for (it = v.begin(); it != v.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
 
 
 
int main() 
{ 
	vector<float> v1,v2;
	
	// Creation de v1 avec des valeurs régulierements reparties entre 0.0 et 10.0
	for( int i=0; i<10;i++)
		v1.push_back(0.1*i);
	
	// Affichage de v1
	showvec(v1);
	
	// Copie de v1 dans v2
	v2 = v1;
	
	// Sauvegarde de la taille de v2 !! avec pop_back() la taille change
	int s=v2.size();
	
	// Suppression element par element de la deuxieme moitie de v2
	for (int i=0; i<s/2; i++)
		v2.pop_back();
		
	// Affichage de v2
	showvec(v2);	
	
	return 0;
}
