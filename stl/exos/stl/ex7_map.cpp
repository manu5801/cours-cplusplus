#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string,unsigned int> nbJoursMois;
	
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
	...
	
	// Nombre de jour du mois de janvier
	...
	
	// Affichage du mois de janvier
	...
	
	return 0;
}
