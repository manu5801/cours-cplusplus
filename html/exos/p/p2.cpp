#include <iostream>
using namespace std;

main() {
   int A=10;
   int &b = A;
   int *c = &A;

   cout << "b        = " << b << "\nadr de b = " << &b << "\n";
   cout << "c        = " << c << "\nadr de c = " << &c << "\nval de c = " << *c << "\n";
}

