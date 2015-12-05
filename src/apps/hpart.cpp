/******************************************************************************
 * horder.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, graph_partition
 ******************************************************************************/
#include "hypergraph_file.h"
//#include "graph_partition.h"
#include <set>

using namespace std;

int main(int argc, char **argv)
{
    int  nedges = 0, nvtxs = 0;
    int *eptr = NULL, *eind = NULL;

    if (argc == 1)
    {
        hypergraph_load(stdin, &nedges, &nvtxs, &eptr, &eind);
    }
    else if (argc == 2)
    {
        hypergraph_load(argv[1], &nedges, &nvtxs, &eptr, &eind);
    }
    set<int> internal_nodes;
    set<int> external_nodes;
    //int start = 0, end = 0, ports = nodes;
    for (int i = 0; i < nedges; i++)
    {
        //printf("insert %d into internal and remove it from external\n", i);
        internal_nodes.insert(i);
        external_nodes.erase(i);
        for (int j = eptr[i]; j < eptr[i + 1]; j++)
        {
            if (internal_nodes.find(eind[j]) == internal_nodes.end())
            {
                //printf("insert %d into external\n", eind[j]);
                external_nodes.insert(eind[j]);
            }
        }
        /*printf("%03d - internal nodes : %d , external nodes : %d , ratio : %d\n",
               i,
               (int)internal_nodes.size(),
               (int)external_nodes.size(),
               (int)(external_nodes.size() > 0 ? (internal_nodes.size()/external_nodes.size()) : internal_nodes.size()));*/
        printf("%d %d %d\n",
               (int)internal_nodes.size(),
               (int)external_nodes.size(),
               (int)(external_nodes.size() > 0 ? (internal_nodes.size()/external_nodes.size()) : internal_nodes.size()));
    }

    delete[] eptr;
    delete[] eind;
    return 0;
}

