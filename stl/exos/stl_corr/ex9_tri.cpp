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
	vector<int> v { 1, 5, 2, 4, 3 };
	
	// Tri du vector v	
	sort(v.begin(), v.end());
	
	// Affichage de v
	showvec(v);
		 
	// Tri décroissant de v
	sort(v.begin(), v.end(), greater<int>());
		    
	// Affichage de v
	showvec(v);
	
}


