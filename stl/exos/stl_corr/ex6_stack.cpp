#include <iostream>
#include <stack>

using namespace std;

int main()
{	
	stack<int> pile;
	
	// Insertion de 4,2 et 1 dans la pile
	pile.push(4);
	pile.push(2);
	pile.push(1);
	
	// Taille de la pile
	cout << "Taille de la pile : " << pile.size() << endl;
	
	// Affichage et suppression des elements de la pile
	while (!pile.empty())
	{
		cout << pile.top() << endl;
		pile.pop();
	}
	
	// Taille de la pile
	cout << "Taille de la pile : " << pile.size() << endl;
	
	return 0;
}
