#include <fstream>
#include <iostream>
#include <memory>
using namespace std;


unique_ptr<int> renvoie_ptr() { unique_ptr<int> p(new int(100)); return p; }

int main() {

	//unique_ptr<int> ptr0 = new int(2);		// Ne compile pas: pourquoi ?
	unique_ptr<int> ptr1(new int(10));
	cout << "*ptr1 = " << *ptr1 << endl;
	*ptr1 = 5;
	cout << "*ptr1 = " << *ptr1 << endl;
	//ptr1++;						// Ne compile pas: pourquoi ?

	unique_ptr<int> ptr2(new int);
	//ptr2 = ptr1;					// Ne compile pas: pourquoi .

	//unique_ptr<int> ptr3(ptr2);			// Ne compile pas: pourquoi ?

	unique_ptr<int> ptr3 = renvoie_ptr();		// Compile: pourquoi ?
}


