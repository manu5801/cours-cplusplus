#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void showvec(vector <int> v) 
{ 
    vector <int> :: iterator it; 
    for (it = v.begin(); it != v.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 

     
int main() 
{
	// Initialisation du vector
	vector<int> ...
	
	// Tri du vector v	
	...
	
	// Affichage de v
	showvec(v);
		 
	// Tri décroissant de v
	...
		    
	// Affichage de v
	showvec(v);
	
}
