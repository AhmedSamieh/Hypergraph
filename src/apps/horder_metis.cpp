/******************************************************************************
 * horder.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, CutHillMcKee,
 *          apply_order APIs
 ******************************************************************************/
#include "hypergraph_file.h"
#include "order.h"

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int  nhedges = 0, nvtxs = 0;
        int *eptr = NULL, *eind = NULL;
        FILE *f = fopen(argv[2], "r");
        hypergraph_load(argv[1], &nhedges, &nvtxs, &eptr, &eind);
        int *order = new int[nhedges];
        for (int i = 0; i < nhedges; i++)
        {
            int v;
            //fscanf(f, "%d", &order[i]);
            fscanf(f, "%d", &v);
            order[v] = i;
        }
        fclose(f);
        apply_order(nhedges, &eptr, &eind, order);
        hypergraph_save(stdout, nhedges, nvtxs, eptr, eind);
        delete[] order;
        delete[] eptr;
        delete[] eind;
    }
    return 0;
}

