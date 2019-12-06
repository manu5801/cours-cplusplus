#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T> void showvec( vector<...> v ) 
{ 
    ... vector<T> :: iterator it; 
    for (it = v.begin(); it != v.end(); ++it) 
        cout << *it << " "; 
    cout << '\n'; 
}

int main( )
{
	std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	showvec(vec);

	// supprime un élément unique
	vec.erase(...);
	showvec(vec);

	// supprime une gamme d’éléments
	vec.erase(...,...);
	showvec(vec);

	// supprime tous les éléments
	...;
	//vec.erase(vec.begin(), vec.end());
	showvec(vec);
	
	// vector [0,10] :
	return 0;
	
}
