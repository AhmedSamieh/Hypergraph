/******************************************************************************
 * hypergraph_edges.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains the code to get edge_edges graph from the hypergraph,
 ******************************************************************************/
#include <cstdio>
#include <list>
#include <set>

using namespace std;

void hypergraph_edges(int   nhedges,
                      int   nvtxs,
                      int  *eptr,
                      int  *eind,
                      int **edges_eptr,
                      int **edges_eind)
{
    if (edges_eptr == NULL || edges_eind == NULL)
    {
        return;
    }
    list<int> *vtxs = new list<int>[nvtxs];
    set<int> *edges = new set<int>[nhedges];
    *edges_eptr = new int[nhedges + 1];
    for (int i = 0; i < nhedges; i++)
    {
        for (int j = eptr[i]; j < eptr[i + 1]; j++)
        {
            vtxs[eind[j]].push_back(i);
        }
    }
    int k = 0;
    for (int i = 0; i < nhedges; i++)
    {
        for (int j = eptr[i]; j < eptr[i + 1]; j++)
        {
            for (list<int>::iterator iter = vtxs[eind[j]].begin();
                 iter != vtxs[eind[j]].end();
                 iter++)
            {
                edges[i].insert(*iter);
            }
        }
        k += edges[i].size();
    }
    *edges_eind = new int[k];
    int j = 0;
    for (int i = 0; i < nhedges; i++)
    {
        (*edges_eptr)[i] = j;
        for (set<int>::iterator iter = edges[i].begin();
             iter != edges[i].end();
             iter++)
        {
#ifdef METIS
            if (i != *iter)
            {
                (*edges_eind)[j++] = *iter + 1;
            }
#else
            (*edges_eind)[j++] = *iter;
#endif
        }
    }
    (*edges_eptr)[nhedges] = j;
    delete[] vtxs;
    delete[] edges;
}

