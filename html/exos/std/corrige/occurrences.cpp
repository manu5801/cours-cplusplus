#include <string>
#include <iostream>
#include <map>
using namespace std;

/*****
*
* Ce programme compte les occurrences des differents mots apparaissant dans un texte
*
* Il fonctionne en deux temps:
*    - On lit l'entree standard et on met chaque mot dans une map
*    - On imprime le contenu de la map
*
* RAPPEL = Une map est un tableau d'éléments de type pair
*          Une pair est une structure contenant deux champs: first, second
*          Dans une map first contient la cle et second contient la valeur
*
*********/

map<string,int> compteur;

int main () {


   while(true) {
     string mot;
     cin >> mot;
     if (cin.eof()) break;
     compteur[mot]++;
   };


   compteur.erase(" "); 
   for (auto i : compteur) {
       if (i.second < 5) continue;
       if (i.first.find_first_of("azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN")!=string::npos) {
          cout.width(30);
          cout.setf(ios::left);
          cout << i.first << i.second << '\n';
       }
   }
   return 0;
}
;

