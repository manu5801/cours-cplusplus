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


	...
	
	
	
	return 0;
}
