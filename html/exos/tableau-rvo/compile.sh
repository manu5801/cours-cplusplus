# Désactiver optimisation RVO
c++ -o tableau-lent -fno-elide-constructors *.cpp

# Normal
c++ -o tableau-rapide  *.cpp


