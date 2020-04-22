CXX = g++
CXXFLAGS = -std=c++11 -march=native -O2 -fopenmp -L/cs/academic/phd3/gaudelet/libs/boost_1_61_0/stage/lib

all: run_hypercounter

string.o: string.h string.cpp

hypergraph.o: hypergraph.h hypergraph.cpp string.o
	$(CXX) $(CXXFLAGS) -c hypergraph.cpp string.o

hyperkernel.o: hypercounter.h hypercounter.cpp string.o
	$(CXX) $(CXXFLAGS) -c hyperkernel.cpp string.o

run_hypercounter: run_hypercounter.cpp hypercounter.o hypergraph.o string.o
	$(CXX) $(CXXFLAGS) $(LIBS) run_hypercounter.cpp hypercounter.o hypergraph.o string.o -o $@


clean:
	rm -rf run_hypercounter *.o *.*~ *~ core *.dSYM

