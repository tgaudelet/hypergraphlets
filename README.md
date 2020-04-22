# Hypergraphlets counter
Implementation of hypergraphlet counter used in 

>Gaudelet, T., Malod-Dognin, N. and Pržulj, N., 2018. Higher-order molecular organization as a source of biological function. Bioinformatics, 34(17), pp.i944-i953.

It is now updated to output both the hypergraphlets and the simplets counts. Simplets were introduced in 

>Malod-Dognin, N. and Pržulj, N., 2019. Functional geometry of protein interactomes. Bioinformatics, 35(19), pp.3727-3734.

Both hypergraphlets and simplets give features to characterize the wiring patterns around nodes in hypergraphs (or simplicial complexes). The simplets are a restriction of hypergraphlets and give a smaller signature. We refer the reader to both papers above for more information.

The implementation requires BOOST library (https://www.boost.org/) and a compiler supporting C++11. 

**Before compiling add the absolute path to the BOOST lib/ folder on your system to the Makefile**
Compile by opening a terminal, navigating to the hypergraphlets folder, and entering the command `make`.


To run the counter simply enter the command
```
./run_hypercounter  -g  "path_to_file/hyperedge.list"  -o  "path_to_output/name_of_output"  -t  "Number of threads, default 1"  -b  "Number of groups of genes to launch across the threads, default 50"
```
The hyperedge list should follow the format:
      - tab separated
      - each row starts with the hyperedge index (between 0 and m-1, where m is the total number of hyperedges) and contain the list of vertices it contains
      - vertices should be indexed from 0 to n-1, n being the total number of vertices
      
The counter outputs two .svml files containing the hypergraphlets and simplets counts with the following format:
      - each row correspond to the count for a vertex
      - the first number (and last) correspond to the vertex index
      - the count for each orbit is of the shape orbit:count
      
The code uses OpenMP for parallelisation, the number of threads to use can be set using the flag -t.

The vertex sets is partitioned in a number of blocks (set by the flag -b) each block being processed by a single thread. The partition is randomised to avoid having consecutive vertex in the same block (this is to avoid having the densely connected vertices in the same block)
