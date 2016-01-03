/******************************************************************************
 * hinv.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, hypergraph_invers,
 *          and hypergraph_save APIs
 ******************************************************************************/
#include "hypergraph_file.h"
#include "hypergraph_inverse.h"

int main(int argc, char **argv)
{
    int  nhedges = 0, nvtxs = 0;
    int *eptr = NULL, *eind = NULL;
    int *inv_eptr = NULL, *inv_eind = NULL;
    if (argc == 1)
    {
        hypergraph_load(stdin, &nhedges, &nvtxs, &eptr, &eind);
    }
    else if (argc == 2)
    {
        hypergraph_load(argv[1], &nhedges, &nvtxs, &eptr, &eind);
    }
    // inverse the hypergraph
    hypergraph_invers(nhedges, nvtxs, eptr, eind, &inv_eptr, &inv_eind);
    hypergraph_save(stdout, nvtxs, nhedges, inv_eptr, inv_eind);
    delete[] inv_eptr;
    delete[] inv_eind;
    delete[] eptr;
    delete[] eind;
    return 0;
}

