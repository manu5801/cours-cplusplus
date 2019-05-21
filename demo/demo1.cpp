#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;




int main()
{
	cout << "Entrez un nom de fichier ";
	string nom_fich;
	cin >> nom_fich;
	string entree = nom_fich + ".txt";
	string sortie = nom_fich + ".out";
	
	ifstream in(entree.c_str());
	if (!in)
	{
		cerr << (string) "Peux pas ouvrir le fichier " << entree << "\n";
	};
	
	ofstream out(sortie.c_str());
	if (!out)
	{
		cerr << (string) "Peux pas ouvrir le fichier " << sortie << "\n";;
	};
	
	typedef vector<string> tableau;
	//typedef list<string> tableau;
	tableau V1;
	
	while(in)
	{
		string mot;
		in >> mot;
		if (mot.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") == string::npos)
		{			
			V1.push_back(mot);
		}
	};
	
	for (tableau::iterator i=V1.begin(); i!=V1.end(); i++)
	{
		out << *i << '\n';
	};

	cout << "Il y a " << V1.size() << " mots\n";
	sort(V1.begin(),V1.end());

	vector<string> V2(V1.size());
	unique_copy(V1.begin(),V1.end(),V2.begin());

	cout << "Il y a " << V2.size()-count(V2.begin(),V2.end(),"") << " mots differents\n";
	
};


