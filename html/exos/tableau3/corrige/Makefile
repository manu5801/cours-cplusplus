
DEBUG=-g
CXX=g++
#CXX=clang++

CXXFLAGS=$(DEBUG) -Wall -pedantic -std=c++11 -Wno-deprecated-declarations
LDFLAGS=$(DEBUG)

SRCFILES=tableau.cpp ecret.cpp homo.cpp main.cpp
EXE=tableau3


all: $(EXE)

$(EXE): $(SRCFILES) tableau.hpp ecret.hpp homo.hpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRCFILES) -o $(EXE)
	
clean:
	rm -f $(EXE) *.o
