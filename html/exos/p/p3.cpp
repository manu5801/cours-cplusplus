
#include <iostream>
using namespace std;

#define DIMENSION 10

void remplitA(int A[],size_t s) {
	for (int i=0; i<s;i++) {
		A[i] = i;
	};
}

main() {
	int A[DIMENSION];
	remplitA(A,DIMENSION);
	
	const int * a        = A+5;
	int * const b        = A+5;
	const int * const c = A+5;
	int * d              = A+5;

	//  *a = 10;                        // Erreur !!!
	cout << "*a = " << *a << endl;
	remplitA(A,DIMENSION);
	cout << "*a = " << *a << endl;
	a++;
	cout << "*a = " << *a << endl;

	cout << "*b = " << *b << endl;
	//  b++;				// Erreur !!
	*b=100;
	cout << "*b = " << *b << endl;

	cout << "*c = " << *c << endl;
	remplitA(A,DIMENSION);
	//  *c = 0;			// Erreur !!
	//  c++;				// Erreur !!
	cout << "*c = " << *c << endl;

	cout << "*d = " << *d << endl;
	remplitA(A,DIMENSION);
	*d = 0;
	d++;	   
	cout << "*d = " << *d << endl;

}

