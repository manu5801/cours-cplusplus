#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

/***************
*
*  COMPILATION = c++ -std=c++11 unique_ptr.cpp -o unique_ptr
*  EXECUTION   = ulimit -v 200000
*                ./unique_ptr
*
*  RISQUE DE PLANTAGE DE LA MACHINE !
*
*****************************************/

/**********
* Cette classe contient DEUX ZONES MEMOIRE
*
* Le constructeur alloue la mémoire
* Le destructeur la libère
* Donc tout va bien
*
* Vraiment ? Pas si sur....
*
****************/

class Tab2 {
private:
	unique_ptr<int> base1;
	unique_ptr<int> base2;
	size_t s1;
	size_t s2;

public:
	/***
	* s1 et s2 = taille du premier et du second tableau
	*
	* En cas d'erreur d'allocation, new renvoie une exception de type bad_alloc
	*
	****************/
	Tab2(size_t s1, size_t s2): s1(s1), s2(s2) 
	{
		base1 = unique_ptr<int>(new int[s1]);
		base2 = unique_ptr<int>(new int[s2]);
	};
};

int main() {

/* Fuite de mémoire:
       N'oubliez pas de taper: ulimit -v 200000
       Observez la fuite à l'aide de top dans une autre fenêtre
       Vérifiez que la troisième ligne provoque une fuite, mais pas les deux autres
*/

   for (;;) {
	try {
	    // Tab2 t = {1000,1000};	     // ca marche
	    Tab2 t = {10000000000,1000};  // Pas de fuite: pourquoi ?
 	    // Tab2 t = {1000,10000000000};     // Pas de fuite: pourquoi ?
    	} catch(const exception &e) {
    	    cerr << e.what() << '\n';
    	};
   };

};

