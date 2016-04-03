#include <iostream>
#include <cstdlib>
using namespace std;


class stack { 
	
public:
	stack(int n) : size(n), top(0) {
		if (debflg) {
			cout << "Ici constructeur de stack size = " << size << "\n";
		};
		A = (int *) malloc(size*sizeof(int));
		for (int i=0; i<size; i++) A[i] = 0;
	};
	~stack() { 
		free(A);
		if (debflg) {
			cout << "Ici destructeur de stack (size = " << size << ")\n";
		};	
	};
	static void set_deb () { debflg=true;};
	static void clr_deb () { debflg=false;};
	void push (int);
	int pop();
	int length() const {return top;};
	
private:
	const int size;
	int *A;
	int top;
	static bool debflg;
	
};

void stack::push (int i) {
	if (top < size) {
		A[top++] = i;
	}
}

int stack::pop() {
	if (top) {
		return A[--top];
	} else {
		return 0;
	}
}

bool stack::debflg=false;

int main() {
	stack::set_deb();	// je veux voir ce qui se passe
	stack s(10);
	srand(time(NULL));
	
	for (int i=0;i<15;i++)
	{
		int z = rand() % 1000;
		s.push(z);
		cout << "je mets dans la pile le nombre " << z << " (taille de la pile " << s.length() << ")\n";
	}
	cout << "\n\n\n";
	for (int i=0; i<15; i++) {
		cout << "je depile maintenant le nombre " << s.pop() << " (taille de la pile " << s.length() << ")\n";
	}
}


