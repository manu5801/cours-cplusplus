#include <iostream>
using namespace std;

#include "tableau.hpp"
#include "traitements.hpp"

// compilation: c++ -o tableau tableau.hpp traitements.hpp main.cpp

int main() {
	Tableau<int,10> T0;
	for (size_t i=0; i<10; i++) {
		T0[i]=i*10;
	};
	
	Tableau<float,10> T1 (T0);
	
	// On fait d'abord une homothetie, puis un ecretage
	homo<> f(10.5);
	ecret<> g(225);
	
	T1.print();
	T1.transform(f);
	T1.print();
	
	T1.transform(g);
	T1.print();

	// Essai du constructeur de copie par défaut
	Tableau<int,10>T2 = T1;
	T2.print();

	Tableau<int,10>T3;
	T3.print();

	// Essai de operator= par défaut
	T3 = T1;
	T3.print();
};

