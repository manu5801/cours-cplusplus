#ifndef __RTSTACK_HPP__
#define __RTSTACK_HPP__ 1

/*
    rtstack derive de runtime_error, son constructeur interroge la pile d'appels pour ensuite la restituer
    par la fonction what()
    
    NOTES 1/ Ce code NE FONCTIONNE QU'AVEC GCC SOUS GNU/LINUX 
          2/ Il vous faudra linker avec le switch -rdynamic pour avoir les symboles
          
    Utilisation:
    
        #include "rtstack.hpp"
        #define STRINGIFY(x) #x
        #define TOSTRING(x) STRINGIFY(x)

        try
        {
             ...votre code...
             throw (rtstack((string)"ERREUR - Fichier " + __FILE__ + TOSTRING(__LINE__)));
        }
        catch (exception& e)
        {
             cerr << e.what();
             exit 1;
        }
        
    Sources: http://www.gnu.org/s/libc/manual/html_node/Backtraces.html
             http://tombarta.wordpress.com/2008/08/01/c-stack-traces-with-gcc
             
    emmanuel.courcelle@toulouse.inp-toulouse.fr
    
*/

#include <stdexcept>
#include <string>
using namespace std;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

class rtstack: public runtime_error {
public:
	explicit rtstack(const string & __arg);
private:
	string __getStack() const throw();
};

#endif

