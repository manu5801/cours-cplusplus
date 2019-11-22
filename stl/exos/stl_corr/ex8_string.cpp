#include <string>
#include <iostream>

using namespace std; 
 
 
int main() {

	// Initialisation de s1 + Affichage
	string s1("coucou, dit le coucou au long cou.");
  	cout << s1 << endl;
 
 	// Recherche du mot 'le' dans s1
	string le("le");
	string::size_type pos = s1.find(le);
	cout << "L'occurence '" << le << "' trouve a la position " << pos << endl;
 
  	// Recherche des occurences 'cou' dans s1
	string cou("cou");
	pos = 0;
	pos = s1.find(cou, pos);
	while (pos != string::npos) {
		cout << "L'occurence '" << cou << "' trouve a la position " << pos << endl;
		++pos;
		pos = s1.find(cou, pos);
	}
 
  	// Remplacement des occurences 'cou' par 'do'
  	string match("cou");
  	string replace("do");
  	pos = 0;
  	pos = s1.find(match, pos);
  	while (pos != string::npos) {
    	s1.replace(pos, match.size(), replace);
    	++pos;
    	pos = s1.find(match, pos);
  	}
  	
  	// Affichage de s1
  	cout << "s1 = " << s1 << endl;
   

  return 0;
}
