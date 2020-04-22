CXX = g++
CXXFLAGS = -std=c++11 -march=native -O2 -fopenmp -L *PATH_TO_BOOST_LIB_FOLDER*

all: run_hypercounter

string.o: source/string.h source/string.cpp

hypergraph.o: source/hypergraph.h source/hypergraph.cpp string.o
	$(CXX) $(CXXFLAGS) -c hypergraph.cpp string.o

hyperkernel.o: source/hypercounter.h source/hypercounter.cpp string.o
	$(CXX) $(CXXFLAGS) -c hyperkernel.cpp string.o

run_hypercounter: run_hypercounter.cpp hypercounter.o hypergraph.o string.o
	$(CXX) $(CXXFLAGS) $(LIBS) run_hypercounter.cpp hypercounter.o hypergraph.o string.o -o $@


clean:
	rm -rf run_hypercounter *.o *.*~ *~ core *.dSYM

