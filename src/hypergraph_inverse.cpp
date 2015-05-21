#include <list>

using namespace std;

void hypergraph_invers(int  nhedges,
                       int nvtxs,
                       int *eptr,
                       int *eind,
                       int *vptr,
                       int *vind)
{
    list<int> *vtxs = new list<int>[nvtxs];
    for (int i = 0; i < nhedges; i++)
    {
        for (int j = eptr[i]; j < eptr[i + 1]; j++)
        {
            vtxs[eind[j]].push_back(i);
        }
    }
    if (vptr != NULL && vind != NULL)
    {
        int j = 0;
        for (int i = 0; i < nvtxs; i++)
        {
            vptr[i] = j;
            for (list<int>::iterator iter = vtxs[i].begin();
                 iter != vtxs[i].end();
                 iter++)
            {
                vind[j++] = *iter;
            }
        }
        vptr[nvtxs] = j;
    }
    delete[] vtxs;
}
