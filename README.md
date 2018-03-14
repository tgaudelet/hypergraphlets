# hypergraphlets
Hypergraphlet counter

Example:

./run_hypercounter  -g  "path_to_file/hyperedge.list"  -o  "path_to_output/name_of_output"  -t  "Number of threads, default 1"  -b  "Number of groups of genes to launch across the threads, default 50"

The hyperedge list should follow the format:
      - tab separated
      - each row starts with the hyperedge index (between 0 and m-1, where m is the total number of hyperedges) and contain the list of vertices it contains
      - vertices should be indexed from 0 to n-1, n being the total number of vertices
      
The counter outputs a .svml format count with the following format:
      - each row correspond to the count for a vertex
      - the first number (and last) correspond to the vertex index
      - the count for each orbit is of the shape orbit:count
      
The code uses OpenMP for parallelisation, the number of threads to use can be set using the flag -t.

The vertex sets is partitioned in a number of blocks (set by the flag -b) each block being processed by a single thread. The partition is randomised to avoid having consecutive vertex in the same block (this is to avoid having the densely connected vertices in the same block)
