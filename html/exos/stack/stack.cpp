#include <iostream>
#include <cstdlib>
using namespace std;

/**********
 * La classe Stack permet d'implémenter des piles d'entiers
 * 
 * On passe un entier au constructuer, qui sera la taille de la pile
 * 
 * On ne peut faire que deux opérations: 
 *       push (mettre un entier sur la pile)
 *       pop  (retirer l'entier du haut de la pile)
 * 
 * En cas d'erreur (débordement de pile, erreur d'allocation, etc. 
 * on sort du programme: violent mais efficace !
 * 
 * c++ -std=c++11 stack.cpp -o stack
 * 
 **********/
class Stack { 
	
public:
	Stack(int n) : ... {
		base = ...;
		if (base == nullptr) {
			exit(1);
		}
		for (...) {
			base[i] = 0;
		}
	};
	~Stack() { ... };
	void push (int);
	int pop();
	size_t getLength() const {return top;};
	
private:
	size_t size;   // La taille max de la pile
	int *base;	   // L'adresse de base de la pile
	size_t top;	   // Le nombre d'éléments dans la pile
};

void Stack::push (int i) {
	if (top < size) {
		...
	} else {
		exit(1);
	}
}

int Stack::pop() {
	if (top>0) {
		return ...
	} else {
		exit(1);
	}
}


int main() {
	Stack s(10);
	srand(time(nullptr));
	
	// Essayez de mettre i<20 pour voir ce qui se passe
	for (size_t i=0;i<10;i++)
	{
		int z = rand() % 1000;
		s.push(z);
		cout << "je mets dans la pile le nombre " << z << " (taille de la pile " << s.getLength() << ")" << endl;
	}
	cout << endl;

	for (size_t i=0; i<10; i++) {
		cout << "je depile maintenant le nombre " << s.pop() << " (taille de la pile " << s.getLength() << ")" << endl;
	}
	cout << "La pile est vide" << endl;
}
