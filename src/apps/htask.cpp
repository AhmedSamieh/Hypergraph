/******************************************************************************
 * htask.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, hypergraph_save APIs
 *          reorder the equations
 *          1 - read the graph from cnf file 2 times
 *          2 - get abs value for one instance
 *          3 - inverse the output graph from step 2
 *          4 - get edge_edges connectivity graph
 *          5 - generate pairs file
 *          6 - find CutHillMcKee order
 *          7 - apply the order
 *          8 - generate pairs file
 *          9 - apply the order on the second instance from step 1
 *          10 - save the output
 ******************************************************************************/
#include "hypergraph_file.h"
#include "hypergraph_inverse.h"
#include "hypergraph_edges.h"
#include "order.h"

int main(int argc, char **argv)
{
    int  nhedges = 0, nvtxs = 0;
    int *eptr = NULL, *eind = NULL;
    int  org_nhedges = 0, org_nvtxs = 0;
    int *org_eptr = NULL, *org_eind = NULL;
    int *inv_eptr = NULL, *inv_eind = NULL;
    int *edges_eptr = NULL, *edges_eind = NULL;
    if (argc == 2)
    {
        hypergraph_load(argv[1], &nhedges, &nvtxs, &eptr, &eind, true);
        hypergraph_load(argv[1], &org_nhedges, &org_nvtxs, &org_eptr, &org_eind, true);
    }
    // abs
    for (int i = 0; i < eptr[nhedges]; i++)
    {
        if (eind[i] < 0)
        {
            eind[i] = -eind[i];
        }
        eind[i]--;
    }
    hypergraph_invers(nhedges, nvtxs, eptr, eind, &inv_eptr, &inv_eind);
    hypergraph_edges(nvtxs, nhedges, inv_eptr, inv_eind, &edges_eptr, &edges_eind);
    hypergraph_save_pairs("org.pairs", nvtxs, edges_eptr, edges_eind);
    int *order = new int[nvtxs], *iorder = new int[nvtxs];
    CutHillMcKee(nvtxs, edges_eptr, edges_eind, order);
    // order[L] = i means that the new label of node i (the one that had the initial label of i) will be L
    apply_order(nvtxs, &edges_eptr, &edges_eind, order);
    hypergraph_save_pairs("orderd.pairs", nvtxs, edges_eptr, edges_eind);
    printf("c new order :\n");
    for (int i = 0; i < nvtxs; i++)
    {
        iorder[order[i]] = i;
        printf("c %d\n", order[i] + 1);
    }
    for (int i = 0; i < org_eptr[org_nhedges]; i++)
    {
        if (org_eind[i] < 0)
        {
            org_eind[i] = -(iorder[-org_eind[i] - 1] + 1);
        }
        else
        {
            org_eind[i] = iorder[org_eind[i] - 1] + 1;
        }
    }
    printf("c new graph:\n");
    hypergraph_save(stdout, org_nhedges, org_nvtxs, org_eptr, org_eind, true);
    delete[] order;
    delete[] iorder;
    delete[] edges_eptr;
    delete[] edges_eind;
    delete[] inv_eptr;
    delete[] inv_eind;
    delete[] eptr;
    delete[] eind;
    delete[] org_eptr;
    delete[] org_eind;
    return 0;
}

