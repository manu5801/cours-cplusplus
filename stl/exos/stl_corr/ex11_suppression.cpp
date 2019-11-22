#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T> void showvec( vector<T> v ) 
{ 
    typename vector<T> :: iterator it; 
    for (it = v.begin(); it != v.end(); ++it) 
        cout << *it << " "; 
    cout << '\n'; 
}

int main( )
{
	std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	showvec(vec);

	// vector [10,10] : 0 1 2 3 4 5 6 7 8 9
	// supprime un élément unique
	vec.erase(vec.begin());
	showvec(vec);
	
	// vector [9,10] : 1 2 3 4 5 6 7 8 9
	// supprime une gamme d’éléments
	vec.erase(vec.begin()+2, vec.begin()+5);
	showvec(vec);
	
	// vector [6,10] : 1 2 6 7 8 9
	// supprime tous les éléments
	vec.clear();
	//vec.erase(vec.begin(), vec.end());
	showvec(vec);
	
	// vector [0,10] :
	return 0;
}
