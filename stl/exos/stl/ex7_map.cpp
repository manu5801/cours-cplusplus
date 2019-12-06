#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<...,...> nbJoursMois;
	
	// Construction de la table associative: 
	//  clé->mois et valeur-> nombre de jours
	nbJoursMois["janvier"] = ...;
	nbJoursMois["février"] = ...;
	nbJoursMois["mars"] = ...;
	nbJoursMois["avril"] = ...;
	// ...
	
	// Taille de la map
	...
	
	// Affichage de la map 
	for(auto it=nbJoursMois.begin(); it!=...; ++it)
	{
		cout << ... << " -> \t" << ... << endl;
	}
	
	// Nombre de jour du mois de janvier
	cout << "Nombre de jours du mois de janvier : " << ... <<"\n";
	
	// Affichage du mois de janvier
	cout << "Janvier : \n" ;
	for(int i=1; i <= nbJoursMois["janvier"]; i++)
	{
		cout << ... << " ";
	}
	cout << endl;
	
	return 0;
}
