#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//ptr int seuil=5;
//ptr bool grandNombre( int x) { return x > seuil; };

int main()
{
    vector<int> v= {1,2,3,4,5,6,7,8,9};

    class grandNombre_t {
        private:
           int seuil;
        public:
           grandNombre_t(int s): seuil(s) {};
           bool operator() (int x) { return x > seuil; }
    };

    int seuil = 5;
    grandNombre_t grandNombre(seuil);

    if (all_of(v.begin(),v.end(),grandNombre))
    {
        cout << "Tous les nombres sont supérieurs à " << seuil << endl;
    }
    else
    {
        cout << "Tous les nombres ne sont PAS supérieurs à " << seuil << endl;
    }
}

