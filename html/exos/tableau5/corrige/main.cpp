#include <iostream>
using namespace std;

#include "tableau.hpp"
#include "homo.hpp"
#include "ecret.hpp"

// compilation: c++ -o tableau tableau.hpp main.cpp

int main() {
Tableau<> T1;
for (size_t i=0; i<10; i++) {
	T1[i]=i*10;
};

// On fait d'abord une homothetie, puis un ecretage
homo<> f(10.5);
ecret<> g(225);

cout << T1 << endl;
T1.transform(f);
cout << T1 << endl;

T1.transform(g);
cout << T1 << endl;


return 0;

}
