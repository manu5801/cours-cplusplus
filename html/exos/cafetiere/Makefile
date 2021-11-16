
all: Cafeteria

.PHONY: clear


#CXX=singularity run /usr/local/containers/gcc.sif g++
CXX=clang++
CXXFLAGS=-g 

OBJ=Reservoir.o ReservoirEau.o ReservoirSoluble.o ReservoirPoudre.o Cafetiere.o CafetiereSoluble.o CafetierePoudre.o Bouilloire.o
EXE=Cafeteria

Cafeteria: Cafeteria.cpp $(OBJ)
	 $(CXX) -g -std=c++17 $^ -o $@

#Reservoir.o: Reservoir.cpp

#ReservoirEau.o: ReservoirEau.cpp

all: $(OBJ)

.PHONY=clean

clean:
	rm -f *.o Cafeteria
