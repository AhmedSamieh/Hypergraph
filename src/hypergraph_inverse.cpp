/******************************************************************************
 * hypergraph_invers.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains the code to invers hypergraph,
 *          convert hyperedges to vertices and visa versa.
 *          size of eptr will be changed from nhedges+1 to nvtxs+1
 ******************************************************************************/
#include <cstdio>
#include <list>

using namespace std;

void hypergraph_invers(int   nhedges,
                       int   nvtxs,
                       int  *eptr,
                       int  *eind,
                       int **inv_eptr,
                       int **inv_eind)
{
    if (inv_eptr == NULL || inv_eind == NULL)
    {
        return;
    }
    list<int> *vtxs = new list<int>[nvtxs];
    *inv_eptr = new int[nvtxs + 1];
    *inv_eind = new int[eptr[nhedges]];
    for (int i = 0; i < nhedges; i++)
    {
        for (int j = eptr[i]; j < eptr[i + 1]; j++)
        {
            vtxs[eind[j]].push_back(i);
        }
    }
    int j = 0;
    for (int i = 0; i < nvtxs; i++)
    {
        (*inv_eptr)[i] = j;
        for (list<int>::iterator iter = vtxs[i].begin();
             iter != vtxs[i].end();
             iter++)
        {
            (*inv_eind)[j++] = *iter;
        }
    }
    (*inv_eptr)[nvtxs] = j;
    delete[] vtxs;
}

