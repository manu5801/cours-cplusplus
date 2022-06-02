#include <string>
#include <iostream>

using namespace std; 
 
 
int main() {

	// Initialisation s1 par la phrase "coucou, dit le coucou au long cou"
	string ...;
	// Affichage
  	cout << ... << endl;
 
 	// Recherche de l'occurence 'le' dans s1
	string le("le");
	string::size_type pos = ...;
	cout << "L'occurence '" << le << "' trouve a la position " << ... << endl;
 
  	// Recherche des occurences 'cou' dans s1
	string cou();
	pos = 0;
	pos = ...;
	while (pos != string::npos) {
		cout << "L'occurence '" << cou << "' trouve a la position " << ... << endl;
		++pos;
		pos = ...;
	}
 
  	// Remplacement des occurences 'cou' par 'do'
  	string match("cou");
  	string replace("do");
  	pos = 0;
  	pos = ...;
  	while (pos != string::npos) {
    		s1.replace(pos, ..., ...);
    		++pos;
    		pos = s1.find(match, pos);
  	}
  	
  	// Affichage de s1
  	cout << "s1 = " << s1 << endl;
   

  return 0;
}
