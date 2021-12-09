#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

/****************************************************************************************************
 *
 * Ce programme - jouet vise à montrer l'utilisation:
 *                    - du clonage polymorphique des objets à sémantique d'entité
 *                    - des smart pointer de type shared et de la fonction make_shared
 *                    - de la compilation conditionnelle utilisant les constexpr plutôt que #define
 *
 *****************************************************************************************************/


const int POINTEURS=0;
const int SHARED_1V=1;
const int SHARED_3V=2;
const int MAIN=SHARED_1V;

// Une classe de abstraite de base
class Base {
    private:
        string nom;
        
    public:
        explicit Base(const string& n): nom(n) {};

        // Renvoie le nom
        string getNom() { return nom; };

        // Change le nom
        void addNom (const string& n) { nom += " "; nom += n; };

        // Renvoie une indication du type
        virtual string id() const = 0;

        // La fonction virtuelle pure permettant d'implémenter le clonage polymorphique
        virtual Base * clone() = 0;
    
        // Pour imprimer
        string to_string() const {
            return "Bonjour - Ici la classe " + id() + " Mon nom est: " + nom;
        }
};


class Deriv1: public Base {
    public:
        explicit Deriv1(const string &n): Base(n) {};
        
        string id() const override {
            return "Deriv1";
        }
        
        Deriv1 * clone() override {
            return new Deriv1(*this);
        }
};

class Deriv2: public Base {
    public:
        explicit Deriv2(const string &n): Base(n) {};
        string id() const override {
            return "Deriv2";
        }
        
        Deriv2 * clone() override {
            return new Deriv2(*this);
        }
};


int main() {

    /*******************************************************************
     * Dans ce code, monVecteur est un vecteur de pointeurs vers Base
     *
     * On a l'impression que ça marche, mais l'utilisation à travers valgrind montre qu'il n'en est rien:
     *
     * Usage = c++ -std=C++17 clonage.cpp
     *         ./a.out
     *         valgrind ./a.out
     *
     *******************************************************************/

    if constexpr(MAIN==POINTEURS) {

        // On initialise monVecteur
        vector<Base *> monVecteur;
        monVecteur.push_back(new Deriv1("toto"));
        monVecteur.push_back(new Deriv1("titi"));
        monVecteur.push_back(new Deriv2("toto"));
        monVecteur.push_back(new Deriv2("titi"));

        // On imprime monVecteur
        for (auto d: monVecteur) {
            cout << d->to_string() << "\n";
        }
        cout << "=============================\n";

        // On ajoute à la fin des clones des 4 premiers éléments
        monVecteur.push_back(monVecteur[0]->clone());
        monVecteur.push_back(monVecteur[1]->clone());
        monVecteur.push_back(monVecteur[2]->clone());
        monVecteur.push_back(monVecteur[3]->clone());

        // On imprime à nouveau
        for (auto d: monVecteur) {
            cout << d->to_string() << "\n";
        }
        cout << "=============================\n";

        // On ajoute à la fin des copies des 4 premiers éléments
        monVecteur.push_back(monVecteur[0]);
        monVecteur.push_back(monVecteur[1]);
        monVecteur.push_back(monVecteur[2]);
        monVecteur.push_back(monVecteur[3]);

        // On imprime à nouveau
        for (auto d: monVecteur) {
            cout << d->to_string() << "\n";
        }
        cout << "=============================\n";

        // On change les noms des éléments
        int i = 0;
        for (auto d: monVecteur) {
            d->addNom(to_string(i++));
        }
        
        // On imprime une dernière fois
        for (auto d: monVecteur) {
            cout << d->to_string() << "\n";
        }
        cout << "=============================\n";

        // On détruit tout !
        monVecteur.clear();        
    }
    
    /*******************************************************************
     * Dans ce code, monVecteur est un vecteur de shared_ptr vers Base
     *
     * On voit que ça marche, l'utilisation à travers valgrind montre qu'il n'y a pas de fuites:
     *
     * Usage = c++ -std=C++17 clonage.cpp
     *         ./a.out
     *         valgrind ./a.out
     *
     *******************************************************************/

    if constexpr(MAIN==SHARED_1V) {

        // On initialise monVecteur
        vector<shared_ptr<Base>> monVecteur;
        monVecteur.push_back(make_shared<Deriv1>("toto"));
        monVecteur.push_back(make_shared<Deriv1>("titi"));
        monVecteur.push_back(make_shared<Deriv2>("toto"));
        monVecteur.push_back(make_shared<Deriv2>("titi"));

        // On imprime monVecteur
        cout << "\nmonVecteur avec for (auto d: monVecteur)\n";
        for (auto d: monVecteur) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }

        cout << "\nmonVecteur avec for (auto& d: monVecteur)\n";
        for (auto& d: monVecteur) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }
        cout << "=============================\n";

        // On ajoute à la fin des clones des 4 premiers éléments
        monVecteur.push_back(shared_ptr<Base>(monVecteur[0].get()->clone()));
        monVecteur.push_back(shared_ptr<Base>(monVecteur[1].get()->clone()));
        monVecteur.push_back(shared_ptr<Base>(monVecteur[2].get()->clone()));
        monVecteur.push_back(shared_ptr<Base>(monVecteur[3].get()->clone()));

        // On imprime à nouveau
        for (auto& d: monVecteur) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }
        cout << "=============================\n";

        // On ajoute à la fin des copies des 4 premiers éléments
        monVecteur.push_back(monVecteur[0]);
        monVecteur.push_back(monVecteur[1]);
        monVecteur.push_back(monVecteur[2]);
        monVecteur.push_back(monVecteur[3]);

        // On imprime à nouveau
        for (auto& d: monVecteur) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }
        cout << "=============================\n";

        // On change les noms des éléments
        int i = 0;
        for (auto& d: monVecteur) {
            d->addNom(to_string(i++));
        }
        
        // On imprime une dernière fois
        for (auto& d: monVecteur) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }
        cout << "=============================\n";

        // On détruit tout !
        monVecteur.clear();
        
    }

    /*******************************************************************
     * Dans ce code, on utilise trois vecteurs:
     *
     *          - monVecteurSrc est un vecteur de shared_ptr Base
     *          - monVecteurCopie est la copie de monVecteurSrc
     *          - monVecteurClone contient les clones des objets de monVecteurSrc
     *
     * On voit que ça marche, l'utilisation à travers valgrind montre qu'il n'y a pas de fuites:
     *
     * Usage = c++ -std=C++17 clonage.cpp
     *         ./a.out
     *         valgrind ./a.out
     *
     *******************************************************************/


    if constexpr(MAIN==SHARED_3V) {
        
        vector<shared_ptr<Base>> monVecteurSrc;
        vector<shared_ptr<Base>> monVecteurCopie;
        vector<shared_ptr<Base>> monVecteurClone;

        // initialisation de monVecteurSrc avec des objets polymorphiques
        monVecteurSrc.push_back(make_shared<Deriv1>("toto"));
        monVecteurSrc.push_back(make_shared<Deriv1>("titi"));
        monVecteurSrc.push_back(make_shared<Deriv2>("toto"));
        monVecteurSrc.push_back(make_shared<Deriv2>("titi"));

        // On les affiche
        cout << "Et voici monVecteurSrc \n";
        for (auto& d: monVecteurSrc) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }
        cout << "=============================\n";

        // Copie de monVecteurSrc
        // Les éléments sont des shared_ptr, donc ça se passe bien !
        // ATTENTION - On a recopié tous les éléments, c'est-à-dire les POINTEURS !

        monVecteurCopie = monVecteurSrc;

        // Clonage de monVecteurSrc
        // On introduit l'un après l'autre un clone polymorphique de chaque élément de monVecteurSrc
        for (auto& d: monVecteurSrc) {
            monVecteurClone.push_back(shared_ptr<Base>(d.get()->clone()));
        }

        // On change les noms des objets de monVecteurCopie
        for (auto& d: monVecteurCopie) {
            d->addNom("COPIE DE VECTEUR");
        }

        // On change les noms des objets de monVecteurClone
        for (auto& d: monVecteurClone) {
            d->addNom("ELEMENT CLONE");
        }
        
        // On imprime tout ça
        cout << "On a copié monVecteurSrc dans monVecteurCopie \n";
        cout << "On a cloné chaque élément de monVecteurSrc et on les a déposés dans monVecteurClone\n";
        cout << "Où en sommes-nous à présent ?\n";
        cout << "\n";
        cout << "monVecteurSrc\n";
        for (auto& d: monVecteurSrc) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }
        cout << "-----------------------------\n";
        cout << "monVecteurCopie\n";
        for (auto& d: monVecteurCopie) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }
        cout << "-----------------------------\n";
        cout << "monVecteurClone\n";
        for (auto& d: monVecteurClone) {
            cout << d->to_string() << " count=" << d.use_count() << "\n";
        }
        cout << "-----------------------------\n";
    }
}
