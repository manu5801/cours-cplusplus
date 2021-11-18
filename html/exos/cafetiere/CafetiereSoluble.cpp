
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

#include "Color.hpp"
#include "CafetiereSoluble.hpp"


void CafetiereSoluble::faireLeCafe(doses_t e, doses_t c) {
    string msg;
    doses_t e1(0), c1(0);

    e1 = eau.prelever(e, msg);
    cerr << getIds() << msg << "\n";

    // Si on a prélevé assez d'eau, on continue
    bool ok = true;
    if (e1 == e) {
        chaufferEau(msg);
        cerr << getIds() << msg << "\n";
        c1 = cafe.prelever(c, msg);
        cerr << getIds() << msg << "\n";
        if (c1 != c) {
            ok = false;
        }
    }
    else
    {
        ok = false;
    }
    if (ok)
    {
        cerr << getIds() << "CAFETIERE CAFE SOLUBLE Touillage - plop\n";
        cerr << setColor(Color::green) << getIds() << "CAFETIERE CAFE SOLUBLE  Votre café est prêt" << setColor(Color::normal) << "\n";
    }
    else
    {
        string colour = "\033[0;";
        colour += "31m";
        cerr << setColor(Color::red) << setColor(Color::bold) << getIds() << "CAFETIERE CAFE SOLUBLE PROBLEME - Pas de café pour l'instant, désolé" << setColor(Color::normal) << "\n";
    }
}

//void CafetiereSoluble::faireLeCafe(doses_t e, doses_t c) {
    //string msg;
    //doses_t e1 = eau.prelever(e, msg);
    //cerr << getIds() << msg << "\n";

    //// Si on a prélevé assez d'eau, on la chauffe
    //if (e1 == e) {
        //chaufferEau(msg);
        //cerr << getIds() << msg << "\n";
    //}
    //doses_t c1 = cafe.prelever(c, msg);
    //cerr << getIds() << msg << "\n";
    //if (e1!=e || c1!=c) {
        //cerr << getIds() << "CAFETIERE CAFE SOLUBLE PROBLEME - Pas de café aujourd'hui, désolé\n";
    //}
    //else
    //{
        //cerr << getIds() << "CAFETIERE CAFE SOLUBLE Touillage - plop\n";
        //cerr << getIds() << "CAFETIERE CAFE SOLUBLE Votre café est prêt\n";
    //}
//}

doses_t CafetiereSoluble::remplirCafe(doses_t c) {
    string msg;
    c = cafe.remplir(c, msg);
    cerr << getIds() << msg << "\n";
    return c;
}
