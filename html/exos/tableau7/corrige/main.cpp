#include <iostream>
#include <stdexcept>
using namespace std;

#include "tableau.hpp"

// compilation: c++ -o tableau tableau.hpp traitements.hpp main.cpp

// Si on alloue les tableaux ici, on pourra encore les utiliser après l'exception !
Tableau<> T1(10);
Tableau<> T2(5);
int main() {
	try
	{
		//Tableau<> T1(10);
		//Tableau<> T2(5);

		// On joue avec les tableaux !
		// T1 = {1,2,3,4};
		for (size_t i=0; i<10; i++) {
			T1[i]=i*10;
		};
		cout << "T1=" << T1 << endl;
		
		//T1  = T2;	// runtime error si on commente cette ligne !
		T1 += T2;
		cout << "T1=" << T1 << endl;
	}
	
	// ATTENTION  - Resultat different si on passe l'exception par valeur ou par reference
	//catch ( exception e )
	catch ( exception& e )
	{
		cerr << "ERREUR " << e.what() << '\n';
	}
	
	cout << "T1=" << T1 << endl;
	
	return 0;
}
