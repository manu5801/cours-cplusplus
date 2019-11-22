#include <iostream> 
#include <iterator> 
#include <vector> 


using namespace std;
 
int main() 
{ 
    vector<int> v1 = { 1, 2, 3, 4, 5 }; 
  
	vector<int>::iterator i1;
    // Lecture des donnes de v1 avec un iterator 
    for (i1 = v1.begin(); i1 != v1.end(); ++i1) { 
        // Accessing elements using iterator 
        cout << (*i1) << " "; 
    } 
    cout << endl;
    
    // Lecture des donnes par la fin de v1 avec un reverse_iterator  
    for (vector<int>::reverse_iterator i2 = v1.rbegin(); i2 != v1.rend(); ++i2) { 
        // Accessing elements using iterator 
        cout << (*i2) << " "; 
	}     
    cout << endl;   
    
    

    
    // Recherche d'une valeur
	int val=4;
    vector<int>::iterator first, last;
    
    first = v1.begin();
    last = v1.end();
 
    while (first!=last && *first != val)  
        ++first; 
     
     
    if (first != v1.end()) 
    { 
        std::cout << "Element " << val <<" trouve a la position : " ; 
        std:: cout << first - v1.begin() + 1 << "\n" ; 
    } 
    else
        std::cout << "Element non trouve.\n\n";    

   
    
    
    
    return 0; 
} 

