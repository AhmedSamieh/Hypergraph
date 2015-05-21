#include "hypergraph_file.h"
#include "hypergraph_inverse.h"

int main(int argc, char **argv)
{
    int  nhedges = 0, nvtxs = 0;
    int *eptr = NULL, *eind = NULL;
    int *vptr = NULL, *vind = NULL;

    if (argc == 1)
    {
        hypergraph_load(stdin, &nhedges, &nvtxs, &eptr, &eind);
    }
    else if (argc == 2)
    {
        hypergraph_load(argv[1], &nhedges, &nvtxs, &eptr, &eind);
    }
    // inverse the hypergraph
    vptr = new int[nvtxs + 1];
    vind = new int[eptr[nhedges]];
    hypergraph_invers(nhedges, nvtxs, eptr, eind, vptr, vind);
    hypergraph_save(stdout, nvtxs, nhedges, vptr, vind);

    delete[] vptr;
    delete[] vind;
    delete[] eptr;
    delete[] eind;
    return 0;
}
