#ifndef HYPERCOUNTER_H
#define HYPERCOUNTER_H

#include "hypergraph.h"

typedef vector<set<int> > V2Vs_set;
typedef map<int,set<int> > V2Hs_map;
typedef map<int, V2Hs_map > VV2Hs_tensor;
typedef vector<vector<long long int> > Count;

class hypercounter
{
    public:
        // Constructors & Destructor
        hypercounter();
        hypercounter(const hypergraph&);
        virtual ~hypercounter();

        // Setters & Getters
        void initialise_counter(const hypergraph&); // Initialise counter with hypergraph

        V2Vs_set get_node_neighbours();
        V2Vs_set get_nodes_hedges();
        Count get_hypercount();

        // Counter
        int retrieve_hypergraphlets_orbit(int,int);
        int retrieve_simplets_orbit(int,int);
        void global_counter(const int, const int); // Outputs matrix of the counts of all nodes
        void counter(const int); // Outputs HDV for specified node

        // Write
        void output_hdvs_to_file(const string &path);
        void output_sdvs_to_file(const string &path); // Write count to a file given by "path"

    private:
        // Class Attributes
        V2Vs_set nodes_hedges;
        V2Vs_set node_neighbours; // (sparse) matrix giving the neighbour set for each vertex
        hypergraph h;
        Count hdvs; //hypergraphlets count
        Count sdvs; //simplets count

};

#endif // HYPERCOUNTER_H

