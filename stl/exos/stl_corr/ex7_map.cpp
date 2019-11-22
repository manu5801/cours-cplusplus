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
	nbJoursMois["janvier"] = 31;
	nbJoursMois["février"] = 28;
	nbJoursMois["mars"] = 31;
	nbJoursMois["avril"] = 30;
	// ...
	
	// Taille de la map
	cout << "La map contient " << nbJoursMois.size() << " elements : \n";
	
	// Affichage de la map 
	for(map<string,unsigned int>::iterator it=nbJoursMois.begin(); it!=nbJoursMois.end(); ++it)
	{
		cout << it->first << " -> \t" << it->second << endl;
	}
	
	// Nombre de jour du mois de janvier
	cout << "Nombre de jours du mois de janvier : " << nbJoursMois.find("janvier")->second <<"\n";
	
	// Affichage du mois de janvier
	cout << "Janvier : \n" ;
	for(int i=1; i <= nbJoursMois["janvier"]; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}
