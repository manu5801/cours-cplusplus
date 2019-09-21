#include <string>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

/* 
   Objet est une classe qui:
	1/ Enveloppe un int
	2/ a un constructeur par défaut, un constructeur
	   Chacun de ces constructeurs écrit un message pour qu'on sache par où on passe

   Compilation: c++ -std=c++11 array.cpp -o array
   Utilisation: ./array montre tous les messages (il y en a beaucoup)
                ./array >/dev/null ne montre que les messages de "debug", pour voir ce qui se passe
                ./array 2>/dev/null ne montre pas les messages de "debug"

   CE QU"IL FAUT FAIRE:
            1- Compilez et executez le programme tel quel
            2- Comparez l'effet de la fonction-membre resize() et reserve() dans le cas du vector 
            3- Essayez de modifier le code pour reduire le nombre d'appels aux constructeur et constructeur de copie:
               -> Decommentez l'operator= et le constructeur de deplacement
               -> Il y a d'autres soucis (lors de l'impression par exemple)
            
*/
class Objet {
public:
   Objet(int x=0): value(x) { cerr << "Hello World I am an Objet " << x << '\n';} ;
   Objet(const Objet& o): value(o.getVal()) {cerr << "Hello World I am a clone " << o.getVal() << '\n'; };
   Objet(const Objet&& o): value(o.getVal()) {cerr << "Hello World I am a vampire " << o.getVal() << '\n'; };
   Objet& operator=(const Objet& o)  { cerr << "Hello World J'étais " << value << " Je suis écrasé par " << o.value << '\n'; value = o.value; return *this; };
   Objet& operator=(const Objet&& o) { cerr << "Hello World J'étais " << value << " J'ai volé une valeur " << o.value << '\n'; value = o.value; return *this; };
   ~Objet(){cerr << "Bye bye world " << value << '\n';};
   int getVal() const { return value;};


private:
   int value;
};

/****************
*
* Impression du contenu de Objet
*
**********************************/
ostream& operator<<(ostream& os, const Objet& o)
{
	os << o.getVal();
	return os;
}

template<typename T,size_t D> ostream& operator<<(ostream& os,const array<T,D>& conteneur)	
{
        os << "{";
        string v="";
        for (auto& item : conteneur)
        { 
                os << v << item;
                v = ',';
        }
        os << "}";
        return os;
}

template<typename T> ostream& operator<<(ostream& os,const vector<T>& conteneur)	
{
        os << "{";
        string v="";
        for (auto& item : conteneur)
        { 
                os << v << item;
                v = ',';
        }
        os << "}";
        return os;
}

int main() {
	cerr << "===== Initialisation de mon_array" << endl;
	array<Objet,(int) 2> mon_array;
	cerr << "===== Impression de mon_array" << endl;
	cout << "mon_array="<< mon_array<<endl;
	cerr << "===== Appel de la fonction fill" << endl;
	mon_array.fill(Objet(1000));
	cerr << "===== Impression de mon_array" << endl;
	cout << "mon_array="<< mon_array << endl;
	cerr << "===== mon_array[5] = 6000" << endl;
	mon_array[5] = 6000;
	cerr << "===== Impression de mon_array" << endl;
	cout << "mon_array="<< mon_array << endl<< endl;
	cerr << "===== Que se passe-t-il si on deborde avec [] ?" << endl;
	cout << "mon_array[2] = " << mon_array[mon_array.size()] << endl;
	cerr << "===== Que se passe-t-il si on deborde avec at() ?" << endl;
	try
	{
		cout << "mon_array.at(2) = " << mon_array.at(mon_array.size()) << endl;
	}
	catch (const out_of_range& e)
	{
		cout << e.what() << endl;
	}

	cerr << endl;
	cerr << "==== Initialisation de mon_vecteur" << endl;
	vector<Objet> mon_vecteur;
	mon_vecteur.reserve(10);
	//mon_vecteur.resize(10);
	cerr << "===== Impression de mon_vecteur" << endl;
	cout << "mon_vecteur= " << mon_vecteur << endl;
	cerr << "===== mon_vecteur[5] = 6000" << endl;
	mon_vecteur[5] = 6000;
	cerr << "===== Impression de mon_vecteur" << endl;
	cout << "mon_vecteur = " << mon_vecteur << endl;

	cerr << "==== On joue avec un vecteur d'Objets initialise a partir d'une liste d'initialisation. Il y aura des conversions" << endl;
	vector<Objet>v1({1,2,3,4,5,6,7,8,9,10});
	v1.reserve(20);
	cerr << "===== Impression de v1" << endl;
	cout << "v1 = " << v1 << endl;

	cerr << "===== On ajoute un element avec push_back" << endl;
	v1.push_back(Objet(100));

	cerr << "===== On ajoute un element avec emplace_back" << endl;
	v1.emplace_back(101);


	cerr << "===== THE END !" << endl;
	return 0;
}

