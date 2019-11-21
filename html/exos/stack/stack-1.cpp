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
 * c++ -std=c++11 stack-1.cpp -o stack-1
 * 
 **********/
class Stack { 
	
public:
	Stack(size_t n) : size(n), top(0) {
		if (debug) {
			cout << "Ici constructeur - size = " << size << endl;
		}
		base = (int *) malloc(size*sizeof(int));
		if (base == nullptr) {
			exit(1);
		}
		for (int i=0; i<size; i++) {
			base[i] = 0;
		}
	};
	~Stack() { 
		free(base);
		base = nullptr;
		if (debug) {
		    cout << "Ici destructeur -  size = " << size << endl;
		}
	};
	void push (int);
	int pop();
	size_t getLength() const {return top;};
	static void setDebug() { ... };
	static void clrDebug() { ... };
	
private:
	size_t size;	// La taille max de la pile
	int *base;		// L'adresse de base de la pile
	size_t top;		// Le nombre d'éléments dans la pile
	static bool debug;
};

bool ... = false;

void Stack::push (int i) {
	if (top < size) {
		base[top++] = i;
	} else {
		exit(1);
	}
}

int Stack::pop() {
	if (top>0) {
		return base[--top];
	} else {
		exit(1);
	}
}


int main() {

	Stack::setDebug();
		
	Stack s(10);
	cout << "pile s creee" << endl;
	
	{
		Stack s1(20);
		cout << "pile s1 creee" << endl;
	}
	cout << "pile s1 detruite" << endl;

	cout << "pile s bientot detruite" << endl;
	cout << "FINI !!!" << endl;	
}
