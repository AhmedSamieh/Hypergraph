/******************************************************************************
 * graph_partitioning.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 ******************************************************************************/
#include <cstdio>
#include <list>
#include <set>

using namespace std;

/*void graph_partition(int   nedges,
                     int   nvtxs,
                     int  *eptr,
                     int  *eind)
{
    set<int> internal_nodes;
    set<int> external_nodes;
    int start = 0, end = 0, ports = nodes;
    for (int i = 0; i < nedges; i++)
    {
        internal_nodes.insert(i);
        external_nodes.erase(i);
        for (int j = eptr[i]; j < eptr[i + 1]; j++)
        {
            if (internal_nodes.find(j) == internal_nodes.end())
            {
                external_nodes.insert(j);
            }
        }
        printf("%03d - internal : %03d , external : %03d\n",
               i,
               internal_nodes.size(),
               external_nodes.size());
        if (internal_nodes.size() > 1000 &&
            external_nodes.size() < (internal_nodes.size() >> 3))
        {
            if (external_nodes.size() > ports)
            {
                printf("from %03d to %03d has %03d ports\n", start, end, ports);
                i = end;
                start = end + 1;
                ports = nodes;
            }
            else
            {
                end = i;
                ports = external_nodes.size();
            }

        }
    }*/
/*int connections_all, connections_up, connections_down;
for (int i = 0; i < nedges; i++)
{
    connections_all = eptr[i + 1] - eptr[i];
    connections_up = 0;
    connections_down = 0;
    for (int j = eptr[i]; j < eptr[i + 1]; j++)
    {
        if (eind[j] > i)
        {
            connections_down++;
        }
        else if (eind[j] < i)
        {
            connections_up++;
        }
    }
    printf("%03d - total : %02d up : %02d down : %02d, from : %02d to : %02d\n",
           i, connections_all, connections_up, connections_down, eind[eptr[i]], eind[eptr[i + 1] - 1]);
}
(void)nvtxs;
}*/

