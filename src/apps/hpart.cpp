/******************************************************************************
 * horder.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains test app for hypergraph_load, graph_partition
 ******************************************************************************/
#include "hypergraph_file.h"
#include <set>
#include <cstdlib>

using namespace std;
//#define DEBUG
int main(int argc, char **argv)
{
    int  nedges = 0, nvtxs = 0;
    int *eptr = NULL, *eind = NULL;
    /*if (argc == 2)
    {
        hypergraph_load(stdin, &nedges, &nvtxs, &eptr, &eind);
    }
    else*/if (argc == 5)
    {
        hypergraph_load(argv[1], &nedges, &nvtxs, &eptr, &eind);
    }
    set<int> internal_nodes;
    set<int> external_nodes;
    set<int> temp_external_nodes;
    int *visited = new int[nedges];
    //int start = 0, end = 0, ports = nodes;
    for (double ratio = atof(argv[2]); ratio <= atof(argv[3]); ratio += atof(argv[4]))
    {
        internal_nodes.clear();
        external_nodes.clear();
        temp_external_nodes.clear();
        double old_ratio = 0.0, new_ratio = 0.0;
        int number_of_partitions = 1;
        printf("total number of nodes : %d, ratio : %f\n", nedges, ratio);
        for (int i = 0; i < nedges; i++)
        {
            visited[i] = 0;
        }
        for (int i = 0; i < nedges; i++)
        {
            if (0 != visited[i] && number_of_partitions != visited[i])
            {
#ifdef DEBUG
                printf("node %d visited by partition %d\n", i, visited[i]);
#endif
                continue;
            }
#ifdef DEBUG
            printf("insert %d into internal\n", i);
#endif
            internal_nodes.insert(i);
            int exist_in_external = 0;
            if (external_nodes.find(i) != external_nodes.end())
            {
                exist_in_external = 1;
            }
            for (int j = eptr[i]; j < eptr[i + 1]; j++)
            {
                if (internal_nodes.find(eind[j]) == internal_nodes.end() &&
                        external_nodes.find(eind[j]) == external_nodes.end())
                {
#ifdef DEBUG
                    printf("insert %d into external\n", eind[j]);
#endif
                    temp_external_nodes.insert(eind[j]);
                }
            }
#ifdef DEBUG
            printf("%03d - internal nodes : %d , external nodes : %d , ratio : %d\n",
                   i,
                   (int)internal_nodes.size(),
                   (int)external_nodes.size() + temp_external_nodes.size(),
                   (int)((external_nodes.size() + temp_external_nodes.size() - exist_in_external) > 0 ?
                         (internal_nodes.size() / (external_nodes.size() + temp_external_nodes.size() - exist_in_external)) : internal_nodes.size()));
#endif
            new_ratio = (external_nodes.size() + temp_external_nodes.size() - exist_in_external) > 0 ?
                        (((double)internal_nodes.size()) / (external_nodes.size() + temp_external_nodes.size() - exist_in_external)) : (double)internal_nodes.size();
            if (old_ratio >= ratio && new_ratio < old_ratio)
            {
#ifdef DEBUG
                printf("remove %d from internal_nodes\n", i);
#endif
                internal_nodes.erase(i);
                printf("partition %d : internal nodes = %d, external_nodes = %d\n", number_of_partitions++,
                       (int)internal_nodes.size(),
                       (int)external_nodes.size());
#if defined(DEBUG) || 0
                printf("internal nodes : [");
                for (set<int>::iterator iter = internal_nodes.begin();
                        iter != internal_nodes.end();
                        iter++)
                {
                    printf("%d ", *iter);
                }
                printf("]\n");
                printf("may be ports : [");
                for (set<int>::iterator iter = external_nodes.begin();
                        iter != external_nodes.end();
                        iter++)
                {
                    printf("%d ", *iter);
                }
                printf("]\n");
#endif
                internal_nodes.clear();
                external_nodes.clear();
                temp_external_nodes.clear();
                i--;
                old_ratio = 0.0;
            }
            else
            {
#ifdef DEBUG
                printf("remove %d from external_nodes\n", i);
#endif
                external_nodes.erase(i);
                old_ratio = new_ratio;
                external_nodes.insert(temp_external_nodes.begin(), temp_external_nodes.end());
                temp_external_nodes.clear();
                visited[i] = number_of_partitions;
#ifdef DEBUG
                printf("partition %d touchs %d\n", number_of_partitions, i);
#endif
                for (int j = eptr[i]; j < eptr[i + 1]; j++)
                {
                    if (visited[eind[j]] == 0)
                    {
                        visited[eind[j]] = number_of_partitions;
#ifdef DEBUG
                        printf("partition %d touchs %d\n", number_of_partitions, eind[j]);
#endif
                    }
                }
            }
        }
        //printf("end of partition %d\n", number_of_partitions);
        printf("partition %d : internal nodes = %d, external_nodes = %d\n", number_of_partitions,
               (int)internal_nodes.size(),
               (int)external_nodes.size());
#if defined(DEBUG) || 0
        printf("internal nodes : [");
        for (set<int>::iterator iter = internal_nodes.begin();
                iter != internal_nodes.end();
                iter++)
        {
            printf("%d ", *iter);
        }
        printf("]\n");
        printf("may be ports : [");
        for (set<int>::iterator iter = external_nodes.begin();
                iter != external_nodes.end();
                iter++)
        {
            printf("%d ", *iter);
        }
        printf("]\n");
#endif
        printf("\n");
    }
    delete[] eptr;
    delete[] eind;
    return 0;
}

