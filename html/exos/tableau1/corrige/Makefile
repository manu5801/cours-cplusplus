
DEBUG=-g
CXX=g++
#CXX=clang++

CXXFLAGS=$(DEBUG) -Wall -pedantic -std=c++11 -Wno-deprecated-declarations
LDFLAGS=$(DEBUG)

SRCFILES=tableau.cpp main.cpp
EXE=tableau1


all: $(EXE)

$(EXE): $(SRCFILES) tableau.hpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRCFILES) -o $(EXE)
	
clean:
	rm -f $(EXE) *.o
