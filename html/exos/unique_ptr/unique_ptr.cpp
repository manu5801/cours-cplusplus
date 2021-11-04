#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;


int main() {

    // Construction d'un unique_ptr sur un entier
    unique_ptr<int> ptr1 = make_unique<int>(10);
    cout << "*ptr1 = " << *ptr1 << endl;

    // Construction d'un unique_ptr sur un tableau d'entiers
    unique_ptr<int[]> ptr2 = make_unique<int[]>(1000000000000);
    
    for ( int i=0; i<10; ++i) {
        ptr2[i] = i;
    }

    cout << "int[]\n";
    for ( int i=0; i<10; ++i) {
        cout << ptr2[i] << "\n";
    }

    ptr2.reset();               // ptr2 n'est plus responsable de rien !

    if (ptr2 == nullptr)
    {
        cout << "oups ! plus d'objet pointé\n";
    }
    else
    {
        for ( int i=0; i<10; ++i) { // Plantage !!!!
            cout << ptr2[i] << "\n";
        }
    }
    
    // Construction d'un unique_ptr sur un vector
    unique_ptr<vector<int>> ptr3 = make_unique<vector<int>>(vector<int>({0,1,2,3,4,5,6,7,8,9}));
    
    cout << "vector<int>\n";
    if (ptr3 == nullptr)
    {
        cout << "oups ! plus d'objet pointé\n";
    }
    else
    {
        for ( int i=0; i<10; ++i) { // Plantage !!!!
            cout << (*ptr3)[i] << "\n";
        }
    }
    
    ptr3.reset();

    if (ptr3 == nullptr)
    {
        cout << "oups ! plus d'objet pointé\n";
    }
    else
    {
        for ( int i=0; i<10; ++i) { // Plantage !!!!
            cout << (*ptr3)[i] << "\n";
        }
    }
}
