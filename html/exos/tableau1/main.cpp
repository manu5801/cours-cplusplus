#include<iostream>
using namespace std;

#include "tableau.hpp"

// compilation: c++ -o tableau tableau.hpp main.cpp
int main() {
	
	Tableau T1(10);
	for (size_t i=0; i<10; i++) {
		T1[i]=10;
	};
	
	cout << "\n======== OPERATION Tableau T2 = T1\n";
	Tableau T2 = T1;
	cout << "OPERATION Tableau T2 = T1    T1= " << T1 << '\n';
	cout << "                             T2= " << T2 << '\n';
	
	cout << "\n======== OPERATION T1 += T2\n";
	T1 += T2;
	cout << "OPERATION T1 += T2       --> T1= " << T1 << '\n';
	cout << "                         --> T2= " << T2 << '\n';
	
	cout << "\n======== OPERATION T1 += 45\n";
	T1 += 45;
	cout << "OPERATION T1 += 45       --> T1= " << T1 << '\n';

	cout << "\n======== OPERATION T3 =  T1 + T2\n";
	Tableau T3 = T1 + T2;
	cout << "OPERATION T3 =  T1 + T2  --> T1= " << T1 << '\n';
	cout << "                         --> T2= " << T2 << '\n';
	cout << "                         --> T3= " << T3 << '\n';

	T1 + T2;
	
	// Une manière moins jolie mais moins couteuse de faire une addition
	cout << "\n======== OPERATION Tableau T4=T1; T4 += T2\n";
	Tableau T4(T1);
	T4 += T2;
	cout << "OPERATION Tableau T4=T1;T4+=T2 --> T1= " << T1 << '\n';
	cout << "                               --> T2= " << T2 << '\n';
	cout << "                               --> T3= " << T3 << '\n';

	cout << "SWAP\n";
	swap(T1,T2);
	
	cout << "C'EST FINI !\n";
	return 0;
}

