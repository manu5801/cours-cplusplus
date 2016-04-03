#include <string>
#include <iostream>
#include <map>
using namespace std;


typedef map<string,int> mapsi ;
typedef mapsi::iterator mapsi_it;

map<string,int> compteur;

main () {


   while(true) {
     string mot;
     cin >> mot;
     if (cin.eof()) break;
     compteur[mot]++;
   };


   compteur.erase(" "); 
   for (mapsi_it i = compteur.begin(); i != compteur.end(); ++i) {
       if (i->second < 5) continue;
       if (i->first.find_first_of("azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN")!=string::npos) {
          cout.width(30);
          cout.setf(ios::left);
          cout << i->first << i->second << '\n';
       }
   }

}
;

