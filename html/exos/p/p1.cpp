
#include <iostream>
using namespace std;

#define DIMENSION 10

void remplitA(int A[],size_t s) {
	for (int i=0; i<s;i++) {
		A[i] = i;
	};
};

void impA(int A[],size_t s) {
	for (int i=0; i<s; i++) {
        cout << "A[" << i << "] = " << A[i] << "\n";
	};
	cout <<  "\n";
}

main() {
	int A[DIMENSION];
	remplitA(A,DIMENSION);
	impA(A,DIMENSION);
	
	int &b = A[5];
	b++;  
	impA(A,DIMENSION);
	
	int * c= A+7;
	(*c)++;
	*c++, (*c)++;
	impA(A,DIMENSION);
	
	cout << "b = " << b << " adr de b = " << &b << "\n";
	cout << "c = " << c << " adr de c = " << &c << " val de *c = " << *c << "\n";
}

