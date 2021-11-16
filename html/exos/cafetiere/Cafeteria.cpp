#include <iostream>
#include <vector>
#include <memory>

using namespace std;



#include "CafetiereSoluble.hpp"
#include "CafetierePoudre.hpp"

using MachineACafe_t   = shared_ptr<Cafetiere>;

using MachineSoluble_t = shared_ptr<CafetiereSoluble>;
using MachinePoudre_t  = shared_ptr<CafetierePoudre>;

using Cafeteria_t = vector<MachineACafe_t>;

void Usage() {
    cerr << "Cafeteria PPPPSS EDFJ\n";
    cerr << "Premier argument = Les machines\n";
    cerr << "-------------------------------\n";
    cerr << "P -> Machine à café Poudre\n";
    cerr << "S -> Machine à café soluble\n";
    cerr << "\n";
    cerr << "Second argument = Les cafés\n";
    cerr << "---------------------------\n";
    cerr << "E -> Expresso\n";
    cerr << "D -> Double\n";
    cerr << "F -> Fort\n";
    cerr << "J -> Jus de chaussette\n";
}

enum class MachineACafe_enum { CafetierePoudre, CafetiereSoluble };

// Fonctions déclarées ici, définies plus bas
MachineACafe_t cafetiereFactory( MachineACafe_enum);
Cafeteria_t construitCafeteria(const string & s);



int main(int argc, char** argv) {
    if (argc != 3) {
        Usage();
        exit(1);
    }

    Cafeteria_t cafeteria = construitCafeteria(argv[1]);

    // Remplissage initial des machines
    for (auto c : cafeteria) {
        c->remplirEau(30);
        c->remplirCafe(30);
        cerr<< "====================\n";
    }

    string cafes = argv[2];
    auto i = cafeteria.begin();
    
    for (auto c : cafes) {
        switch(c) {
            case 'E': (*i)->faireLeCafe(1,1); break;
            case 'D': (*i)->faireLeCafe(2,2); break;
            case 'F': (*i)->faireLeCafe(1,2); break;
            case 'J': (*i)->faireLeCafe(2,1); break;
            default: Usage(); exit(1);
        }
        ++i;
        if (i==cafeteria.end()) i = cafeteria.begin();
        cerr<< "++++++++++++++++++++\n";

    }

    // Etat final des machines
    for (auto& c : cafeteria) {
        cerr << c->getIds() << c->getEtat() << "\n";
    }
}


/*
 * Construction de la cafeteria à partir d'une string
 *
 */
 Cafeteria_t construitCafeteria(const string & s)
 {
     Cafeteria_t cafeteria;
     cafeteria.reserve(s.size());
     
     for (auto c : s) {
        switch (c) {
            case 'P':
                cafeteria.push_back(cafetiereFactory(MachineACafe_enum::CafetierePoudre));
                break;
            case 'S':
                cafeteria.push_back(cafetiereFactory(MachineACafe_enum::CafetiereSoluble));
                break;
            default:
                cerr << "ERREUR - Type de machine inconnu !";
                Usage();
                exit(1);
         }
     }
     return cafeteria;
 }

/*
 * Une usine à cafetières
 * cf. https://iq.opengenus.org/factory-pattern-cpp/
 */

MachineACafe_t cafetiereFactory( MachineACafe_enum type) {
    if (type == MachineACafe_enum::CafetierePoudre)
    {
        return make_shared<CafetierePoudre>();
    }
    else 
    {
        return make_shared<CafetiereSoluble>();
    }
    //else
    //    return nullptr;
}
