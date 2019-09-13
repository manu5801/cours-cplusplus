#include<iostream>
using namespace std;

#include "tableau.hpp"



float somme(const Tableau& t) {
	float s = 0;
	for (size_t i=0; i<t.size();++i) {
		s += t[i];
	}
	return s;
}
	 

// compilation: c++ -o tableau tableau.hpp main.cpp
int main() {
	
	cout << "\n======== CREATION et INITIALISATION de T1\n";
	/*Tableau T1(10);
	for (size_t i=0; i<10; i++) {
		T1[i]=10;
	};*/
	Tableau T1 = { 1.0,2.0,3.0,4.0,5.0 };
	
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

	cout << "\n======== OPERATION Tableau T3 =  T1 + T2\n";
	Tableau T3;
	T3 = T1 + T2;
	cout << "OPERATION T3 =  T1 + T2  --> T1= " << T1 << '\n';
	cout << "                         --> T2= " << T2 << '\n';
	cout << "                         --> T3= " << T3 << '\n';
	
	// Une manière moins jolie mais moins couteuse de faire une addition
	cout << "\n======== OPERATION Tableau T4=T1; T4 += T2\n";
	Tableau T4(T1);
	T4 += T2;
	cout << "OPERATION Tableau T4=T1;T4+=T2 --> T1= " << T1 << '\n';
	cout << "                               --> T2= " << T2 << '\n';
	cout << "                               --> T3= " << T3 << '\n';
	
	// Un beau calcul compliqué
	cout << "\n======== OPERATION Tableau T5 = (T1 + T2) + (T3 + T4)\n";
	Tableau T5 = (T1 + T2) + (T3 + T4);
	
	// Un autre calcul compliqué
	cout << "\n======== OPERATION T6 += (T2 + T4)\n";
	Tableau T6(5);
	T6 += (T2 + T4);
	
	cout << "======== CALCUL DE LA SOMME ========" << endl;
	float s = somme(T2+T3);
	cout << "Somme de T2 + T3 = " << s << endl;
	cout << "C'EST FINI !\n";
	return 0;
}

