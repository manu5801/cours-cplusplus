#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

#include "tableau7.hpp"

typedef Tableau<int> Tint;

#ifdef OBJETS
// tableaux contient deux OBJETS de type tableau
// Pas de fuite de mémoire, bien que la construction du second tableau génère une exception
class tableaux {
    private:
        Tint T1;
        Tint T2;
    
    public:
        tableaux(int s1, int s2): T1(s1),T2(s2) {
            cerr << "constructeur de tableaux\n";
        };
        ~tableaux() {
            cerr << "destructeur de tableaux\n";
        };
};
#endif

#ifdef PTR
// tableaux contient deux pointeurs vers des tableaux - Pb si la construction du second objet déclenche une instruction
// Pour observer, n'oubliez pas de faire AVANT L'EXECUTION: ulimit -v 200000
// Ouvrez un top dans une autre fenêtre
// Lancez le programme et observez la mémoire virtuelle: elle monte jusqu'à 200Mo, puis ça plafonne

class tableaux {
    private:
        Tint* T1;
        Tint* T2;
    
    public:
        tableaux(int s1,int s2) {
            cerr << "constructeur de tableaux\n";
        	T1 = new Tint(s1);
        	T2 = new Tint(s2);
        };
        ~tableaux() {
            cerr << "destructeur de tableaux\n";
        	delete (T1); T1=NULL;
        	delete (T2); T2=NULL;
        };
};
#endif

#ifdef AUTO_PTR
// dans tableaux, on a remplacé les pointeurs par des auto_ptr. On n'a plus de fuite de mémoire !!! 
class tableaux {
    private:
        auto_ptr<Tableau<int> > T1; 
        auto_ptr<Tableau<int> > T2;
    
    public:
        tableaux(int s1, int s2):T1(new Tint(s1)),T2(new Tint(s2)) {
            cerr << "constructeur de tableaux\n";
        };
        // Pas besoin de détruire T1/T2, c'est l'auto_ptr qui s'en charge
        ~tableaux() {
            cerr << "destructeur de tableaux\n";
        };
};
#endif


main() {

/* Fuite de mémoire:
       N'oubliez pas de taper: ulimit -v 200000
       Observez la fuite à l'aide de top dans une autre fenêtre
       ça fuit dans le cas PTR, les autres se comportent correctement
*/
   for (;;) {
	try {
 	    tableaux f(1000,4000000000);
    	} catch(const exception &e) {
    	    cerr << e.what() << '\n';
    	};
   };

};

