#include <stdio.h>
#include <iostream>
using namespace std;

class IntegerPtr;

/* 
   Integer est une classe qui enveloppe un int, elle garde aussi le compte du nombre
   d'objets de type IntegerPtr qui pointent sur elle 
   Le constructeur est privé: seuls les IntegerPtr, qui sont amis d'Integer, 
   ont le droit d'utiliser cet objet
*/
   
class Integer {
public:
    friend class IntegerPtr;

private:
    Integer(int x) : i(x),count(0) {};

    int i;
    unsigned int count;
};

/* IntegerPtr est une classe qui encapsule un pointeur sur Integer.
   C'est le seul moyen d'utiliser Integer */
   
class IntegerPtr {
public:

    /* Le constructeur incrémente le comptage, il est initialisé à partir d'un int */
    IntegerPtr(int i) : ptr(new Integer(i)){ 
        if (ptr!=NULL) 
            ptr->count++;
    }
    
    /* Le destructeur décrémente le comptage, et supprime l'objet si celui-ci vaut 0 */
    ~IntegerPtr() {
        if (ptr !=NULL && --ptr->count==0)
            delete ptr;
    }
    
    /* Le constructeur de copie incrémente lui aussi le comptage */
    IntegerPtr(const IntegerPtr& ip): ptr(ip.ptr) {
        if (ptr != NULL)
            ptr->count++;
    }
    
    /* L'operateur = doit etre redefini, il decremente l'ancien comptage, re-incremente le nouveau */
    IntegerPtr& operator=(const IntegerPtr& ip) {
        if (this == &ip) return *this;  // Attention !!! self-assignment
        if (ptr != NULL && --ptr->count==0)
            delete ptr;
        if (ip.ptr != NULL)
            ++ip.ptr->count;
        ptr = ip.ptr;
        return *this;
    }
    
    /* On doit redefinir l'operateur * pour pouvoir utiliser Integer */
    int& operator*() { return ptr->i; };
    const int& operator*() const {return ptr->i; }; 
           
private:
    Integer* ptr;
};
       
int main()
{
    IntegerPtr i = 4;
    IntegerPtr j = 4;
    IntegerPtr k = *i + *j;
    cout << *k << '\n';
    IntegerPtr l = k;   
}
