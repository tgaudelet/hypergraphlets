#ifndef HYPERGRAPH_H
#define HYPERGRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;
typedef vector<vector<int> > V2Vs_vector;

class hypergraph
{
    public:
        // Constructor & Destructor
        hypergraph();
        virtual ~hypergraph();

        // Setters & Getters
        void set_nb_edges(const int);
        void set_nb_nodes(const int);
        void set_hedges_list(const V2Vs_vector&);
        void read_hypergraph_file(const string&); // TO BE ADDED

        int get_nb_edges();
        int get_nb_nodes();
        V2Vs_vector get_hedges_list();

    private:
        V2Vs_vector hedges_list;
        int nb_edges;
        int nb_nodes;

};

#endif // HYPERGRAPH_H
