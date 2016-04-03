#include <execinfo.h>
#include <cxxabi.h>
#include <cstdlib>
#include "rtstack.hpp"
using namespace std;

rtstack::rtstack(const string& __arg): runtime_error(__arg + '\n' + __getStack()) {};

/*
    __getStack
    Fonction: Utilise les appels backtrace, backtrace_symbols et abi::__cxa_demangle pour recuperer
              la pile d'appels et la formatter sous une forme a peu pres lisible
    Acces   : private
    Arg     : aucun
    Retour  : string, contient la pile d'appel
*/
    
string rtstack::__getStack() const throw()
{
	// 100 = profondeur max de la pile qui sera affichee (arbitraire)
	// On recupere la pile d'appels et les symboles associes
	// ATTENTION Utiliser le switch -rdynamic sinon on n'a pas les symboles
	
	void *traces[100];
	size_t size    = backtrace (traces, 100);
	char** symbols = backtrace_symbols (traces, size);
	
	string stacktrace;
	for (size_t i = 0; i < size; i++)
	{
		stacktrace += symbols[i];

		// On a typiquemenet des chaines de cette sorte: ./a.out(_Z1ev+0x180) [0x401704]
		// On recherche les caracteres ( et + 
		string fct_name;
		char *begin=NULL, *end=NULL;

		for (char *j=symbols[i]; *j; ++j) 
		{
			if (*j=='(')
				begin = j;
			else if (*j=='+')
				end = j;
		}

		// si ( et + ont ete trouves
		if (begin && end)
		{
			*begin++ = 0;
			*end     = 0;
			
			// on a trouve le nom "mangled", on va maintenant le demangler
			int status;
			char *ret = abi::__cxa_demangle(begin,NULL,NULL,&status);
			
			// Si ret != 0, on a demangle qq chose
			if (ret)
			{
				fct_name = ret;
				free(ret);
				ret = NULL;
			}

			// demangling failed, just pretend it's a C function with no args
			else
			{
				fct_name = begin;
				fct_name += "()";
			}
			stacktrace += ' ';
			stacktrace += fct_name;
		}
		stacktrace += '\n';
        }
	free (symbols);
	return stacktrace;
}


