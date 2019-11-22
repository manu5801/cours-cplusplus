#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> file;
	
	// Ajout de 1,4 et 2
	file.push(1);
	file.push(4);
	file.push(2);
	
	// Taille de la file
	cout << "Taille de la file : " << file.size() << endl;
	
	// Affichage de l'element le plus ancien et Depiler 
	while (!file.empty())
	{
		cout << file.front() << endl;
		file.pop();
	}
	// Taille de la file
	cout << "Taille de la file : " << file.size() << endl;
	return 0;
}
