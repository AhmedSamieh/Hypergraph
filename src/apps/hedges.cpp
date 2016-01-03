/******************************************************************************
 * hedges.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, hypergraph_edges,
 *          and hypergraph_save APIs
 ******************************************************************************/
#include "hypergraph_file.h"
#include "hypergraph_edges.h"

int main(int argc, char **argv)
{
    int  nhedges = 0, nvtxs = 0;
    int *eptr = NULL, *eind = NULL;
    int *edges_eptr = NULL, *edges_eind = NULL;
    if (argc == 1)
    {
        hypergraph_load(stdin, &nhedges, &nvtxs, &eptr, &eind);
    }
    else if (argc == 2)
    {
        hypergraph_load(argv[1], &nhedges, &nvtxs, &eptr, &eind);
    }
    // get edge_edges graph from edge_vertices hypergraph
    hypergraph_edges(nhedges, nvtxs, eptr, eind, &edges_eptr, &edges_eind);
#ifdef METIS
    hypergraph_save(stdout, nhedges, edges_eptr[nhedges] / 2, edges_eptr, edges_eind);
#else
    hypergraph_save(stdout, nhedges, nhedges, edges_eptr, edges_eind);
#endif
    delete[] edges_eptr;
    delete[] edges_eind;
    delete[] eptr;
    delete[] eind;
    return 0;
}

