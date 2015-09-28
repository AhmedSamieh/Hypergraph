/******************************************************************************
 * hpairs.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, hypergraph_save_pairs APIs
 ******************************************************************************/
#include "hypergraph_file.h"

int main(int argc, char **argv)
{
    int  nhedges = 0, nvtxs = 0;
    int *eptr = NULL, *eind = NULL;

    if (argc == 1)
    {
        hypergraph_load(stdin, &nhedges, &nvtxs, &eptr, &eind);
    }
    else if (argc == 2)
    {
        hypergraph_load(argv[1], &nhedges, &nvtxs, &eptr, &eind);
    }
    hypergraph_save_pairs(stdout, nhedges, eptr, eind);
    delete[] eptr;
    delete[] eind;
    return 0;
}

