
#include <string>
#include <iostream>
#include "rtstack.hpp"
using namespace std;

/*
    Programme d'essai pour demontrer l'usage de rtstack
    COMPILATION= g++ -rdynamic -o rtstack-main rtstack.cpp rtstack-main.cpp
*/


void a(int, char**);
void b(int);
int c();
void d();
void e();

int main(int argc, char ** argv)
{
    try
    {
        a(argc,argv);
    }
    catch (exception &exc)
    {
        cerr << exc.what();
        return 1;
    };
}

/* 
   a appelle b qui appelle c qui appelle d qui appelle e
   e lance une exception
   on devrait voir une belle pile d'appels
*/

void e()
{
    throw (rtstack(static_cast<string>("Exception fichier - ") + __FILE__ + ":" + to_string(__LINE__)));
}

void d() { e(); };
int c() { d(); return 0; };
void b(int x) { c(); };
void a(int argc, char** argv) { b(argc); };



