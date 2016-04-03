#include <iostream>
using namespace std;

#include "tableau.hpp"
#include "traitements.hpp"

// compilation: c++ -o tableau tableau.hpp traitements.hpp main.cpp

int main() {
Tableau T1(10);
for (size_t i=0; i<10; i++) {
	T1[i]=i*10;
};

// On fait d'abord une homothetie, puis un ecretage
homo f(10.5);
ecret g(225);

T1.print();
T1.transform(f);
T1.print();

T1.transform(g);
T1.print();
};

  
