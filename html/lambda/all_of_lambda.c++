#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//ptr int seuil=5;
//ptr bool grandNombre( int x) { return x > seuil; };

int main()
{
    vector<int> v= {1,2,3,4,5,6,7,8,9};

    //obj class grandNombre_t {
    //obj     private:
    //obj        int seuil;
    //obj     public:
    //obj        grandNombre_t(int s): seuil(s) {};
    //obj       bool operator() (int x) { return x > seuil; }
    //obj };

    int seuil = 5;
    
//obj    grandNombre_t grandNombre(seuil);

//obj    if (all_of(v.begin(),v.end(),grandNombre))
    if (all_of(v.begin(), v.end(), [seuil] (int x) { return x > seuil; }))
    {
        cout << "Tous les nombres sont supérieurs à " << seuil << endl;
    }
    else
    {
        cout << "Tous les nombres ne sont PAS supérieurs à " << seuil << endl;
    }
}

