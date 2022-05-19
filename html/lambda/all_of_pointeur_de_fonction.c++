#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int seuil=5;
bool grandNombre( int x) { return x > seuil; };

int main()
{
    vector<int> v= {1,2,3,4,5,6,7,8,9};
    if (all_of(v.begin(),v.end(),grandNombre))
    {
        cout << "Tous les nombres sont supérieurs à " << seuil << endl;
    }
    else
    {
        cout << "Tous les nombres ne sont PAS supérieurs à " << seuil << endl;
    }
}

