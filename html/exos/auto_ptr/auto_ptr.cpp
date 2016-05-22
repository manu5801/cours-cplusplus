#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

#include "tableau7.hpp"

typedef Tableau<int> Tint;

// tableauO contient deux OBJETS de type tableau
// Pas de fuite de mémoire, bien que la construction du second tableau génère une exception
class tableauO {
    private:
        Tint T1;
        Tint T2;
    
    public:
        tableauO(int s1, int s2): T1(s1),T2(s2) {
            cerr << "constructeur de tableauO\n";
        };
        ~tableauO() {
            cerr << "destructeur de tableauO\n";
        };
};

// tableauF contient deux pointeurs vers des tableaux - Pb si la construction du second objet déclenche une instruction
// Pour observer, n'oubliez pas de faire AVANT L'EXECUTION: ulimit -v 200000
// Ouvrez un top dans une autre fenêtre
// Lancez le programme et observez la mémoire virtuelle: elle monte jusqu'à 200Mo, puis ça plafonne

class tableauF {
    private:
        Tint* T1;
        Tint* T2;
    
    public:
        tableauF(int s1,int s2) {
            cerr << "constructeur de tableauF\n";
        	T1 = new Tint(s1);
        	T2 = new Tint(s2);
        };
        ~tableauF() {
            cerr << "destructeur de tableauF\n";
        	delete (T1);
        	T1=NULL;
        	delete (T2);
        	T2=NULL;
        };
};

// dans tableauA, on a remplacé les pointeurs par des auto_ptr. On n'a plus de fuite de mémoire !!! 

class tableauA {
    private:
        auto_ptr<Tableau<int> > T1;     // ATTENTION auto_ptr<tableau<int>> T1; ne marchera pas, le compilo va se prendre les pieds dans le tapis
        auto_ptr<Tableau<int> > T2;
    
    public:
        tableauA(int s1, int s2):T1(new Tint(s1)),T2(new Tint(s2)) {
            cerr << "constructeur de tableauA\n";
        };
        // Pas besoin de détruire T1/T2, c'est l'auto_ptr qui s'en charge
        ~tableauA() {
            cerr << "destructeur de tableauA\n";
        };
};

// Choisissez ci-dessous le type de tableau que vous souhaitez essayer
//typedef tableauO tableauZ;
//typedef tableauF tableauZ;
typedef tableauA tableauZ;

// choisissez ci-dessous le type d'essai que vous voulez réaliser
#define FUITE
//#define RESPONSABILITE
//#define CONST

main() {

/* Fuite de mémoire:
       N'oubliez pas de taper: ulimit -v 200000
       Observez la fuite à l'aide de top dans une autre fenêtre
       ça fuit dans le cas de tableauF, tableauO et tableauA se comportent correctement
*/
#ifdef FUITE
    for (;;) {
    	try {
    	    tableauZ f(1000,4000000000);
    	} catch(const exception &e) {
    	    cerr << e.what() << '\n';
    	};
    };
#endif

/* Responsabilité:
       Supprimez la macro FUITE, sinon ce code ne sera jamais exécuté
       L'opérateur= ne marche pas dans le cas de tableauO (pas la même dimension)
       L'opérateur= marche dans le cas de tableauF, mais ensuite ça plante (ben oui !)
       Le programme MARCHE BIEN dans le cas de tableauA, car l'opérateur= corresopnd à un passage de responsabilité des pointeurs
*/

#ifdef RESPONSABILITE
    cerr << "naissance de B1 10 10\n";
    tableauZ B1(10,10);
    {
        cerr << "naissance de A1 1000 1000\n";
        tableauZ A1(1000,1000);
        
        cerr << "B1=A1\n";
        B1=A1;
        
        cerr << "Fin de A1\n";
    }
    cerr << "Fin de B1 et du programme\n";
#endif

/* dans une égalité, le membre de droite ne peut être constant
       Le code suivant refuse de compiler dans le cas tableauA
*/

#ifdef CONST
    const tableauZ A1(10,10);
    tableauZ B1(10,10);
    B1 = A1;
#endif

};

