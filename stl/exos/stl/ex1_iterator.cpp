#include <iostream> 
#include <iterator> 
#include <vector> 


using namespace std;
 
int main() 
{ 
    // Creation du vecteur v1 = {1,2,3,4,5}
   vector<int> v1 = { 1, 2, 3, 4, 5 };
    
    // Affichage element par élement de v1
    vector<int>::... i1;
    // Lecture des donnes de v1 avec un iterator 
    for (i1 = v1.begin(); i1 != v1....; ++i1) { 
        // Accessing elements using iterator 
        cout << ... << " "; 
    } 
    cout << endl;
    
    // Affichage en sens inverse
  	for (vector<int>::... i2 = v1....; i2 != v1.rend(); ++i2) { 
        // Accessing elements using iterator 
        cout << ... << " "; 
	}     
    cout << endl;
    

    
    // Recherche de la valeur val dans v1
	int val=4;
    vector<int>::iterator ...
    
    first = ...
    last = v1.end();
 
    while (first!=last && *first != ...)  
        ++first; 
     
     
    if (first != v1.end())
    { 
        std::cout << "Element " << val <<" trouve a la position : " ; 
        std:: cout << ... << "\n" ; 
    } 
    else
        std::cout << "Element non trouve.\n\n";    

   
    
    
    
    return 0; 
} 

