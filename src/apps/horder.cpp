/******************************************************************************
 * horder.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, CutHillMcKee,
 *          apply_ order APIs
 ******************************************************************************/
#include "hypergraph_file.h"
#include "order.h"

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
    int *order = new int[nhedges];
    CutHillMcKee(nhedges, eptr, eind, order);
    apply_order(nhedges, &eptr, &eind, order);
    hypergraph_save(stdout, nhedges, nvtxs, eptr, eind);
    delete[] order;
    delete[] eptr;
    delete[] eind;
    return 0;
}
