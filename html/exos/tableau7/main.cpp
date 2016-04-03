#include <iostream>
#include <stdexcept>
using namespace std;

#include "tableau.hpp"
#include "traitements.hpp"

// compilation: c++ -o tableau tableau.hpp traitements.hpp main.cpp

int main() {
	try
	{
		Tableau<> T1(10);
		for (size_t i=0; i<10; i++) {
			T1[i]=i*10;
		};
		
		Tableau<> T2(5);
		T2 = T1;
	}
	
	// ATTENTION  - Resultat different si on passe l'exception par valeur ou par reference
	//catch ( exception e )
	catch ( exception& e )
	{
		cerr << "ERREUR " << e.what() << '\n';
	}
};

  
