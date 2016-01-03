/******************************************************************************
 * habs.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, hypergraph_save APIs
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
    for (int i = 0; i < eptr[nhedges]; i++)
    {
        if (eind[i] < 0)
        {
            eind[i] = -eind[i];
        }
    }
    hypergraph_save(stdout, nhedges, nvtxs, eptr, eind);
    delete[] eptr;
    delete[] eind;
    return 0;
}

