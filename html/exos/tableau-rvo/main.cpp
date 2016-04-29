#include<iostream>
using namespace std;

#include "tableau.hpp"

// compilation: c++ -o tableau tableau.hpp main.cpp
int main() {

	size_t taille = 10;	
	Tableau T1(taille),T2(taille);
	
	cout << "\n======== OPERATION T3 =  T1 + T2\n";
	Tableau T3 = T1 + T2;

	cout << "C'EST FINI !\n";
	return 0;
}

