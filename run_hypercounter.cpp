#include "hypergraph.h"
#include "hypercounter.h"
#include <iostream>
#include "time.h"
#include <vector>
#include <map>
#include "string.h"
#include <omp.h>

void print_help()
{
    cout << "Usage: run_hypercounter -g HG_file -o OUT_FILE\n";
    cout << "Options:\n\n";

    cout << "-g: specify the path to the file containing the hypergraph\n";
    cout << "-o: specify the path to the output folder\n";
    cout << "-t: specify number of thread\n";
    cout << "-b: specify number of batches\n";
}

int main(int argc, char* argv[])
{
    string hg_path;
    string output_folder;
    int nb_threads=1;
    int nb_batches=50;
    // Parse command line arguments.
    for (int i=1; i<argc && (argv[i])[0] == '-'; i++)
    {
        switch ((argv[i])[1])
        {
            case 'h': print_help(); exit(0);
            case 'g': i++; hg_path=argv[i]; break;
            case 'o': i++; output_folder=argv[i]; break;
            case 't': i++; nb_threads=to_i(argv[i]); break;
            case 'b': i++; nb_batches=to_i(argv[i]); break;
        }
    }

    if (0 == output_folder.size())
    {
        cerr << "ERROR: Output folder not specified." << endl;  print_help();  exit(1);
    }

    double t = omp_get_wtime();
    hypergraph h;
    h.read_hypergraph_file(hg_path);
    cout << "Hypernetwork created" << endl;
    hypercounter hc(h);
    hc.global_counter(nb_threads,nb_batches);
    hc.output_hdvs_to_file(output_folder+"hdvs");
    hc.output_sdvs_to_file(output_folder+"sdvs");

    cout << "Count completed in " << (float)omp_get_wtime() - t<< " seconds.\n";

    exit(0);
}
