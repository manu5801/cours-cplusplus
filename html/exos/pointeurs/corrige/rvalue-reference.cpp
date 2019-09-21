#include <iostream>
using namespace std;

/* 
 * Ce programme ne compile pas. Pour le compiler et le faire fonctionner, il faut
 * modifier la fonction increment... ou peut-être ajouter une nouvelle fonction ?
 * 
 */

int increment1 (int&& n) { n++; return n; }
int increment (int& n) { n++; return n; }

int main()
{
	int i = 5; 
	cout << "5 + 1 = " << increment(i) << endl;
	cout << "4 + 1 = " << increment1(4) << endl;
	cout << "6 + 2 = " << increment1(increment(i)) << endl;
	cout << "i     = " << i << endl;
}

