/******************************************************************************
 * horder.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 ******************************************************************************/
#include "hypergraph_file.h"
#include "hypergraph_inverse.h"
#include "hypergraph_edges.h"
#include <vector>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;
//#define DEBUG
int main(int argc, char **argv)
{
    int  number_of_devices = 0, number_of_nodes = 0;
    int *devices_nodes_eptr = NULL, *devices_nodes_eind = NULL;
    int *nodes_devices_eptr = NULL, *nodes_devices_eind = NULL;
    FILE *f;
    int *order = NULL, *iorder = NULL;
    set<int> internal_nodes;
    set<int> external_nodes;
    vector< set<int> > partition_internal_nodes_sets;
    vector< set<int> > partition_external_nodes_sets;
    set<int> temp_external_nodes;
    map<int, int> handled_devices; // device_partition
    map<int, int> temp_handled_devices;
    if (argc != 6)
    {
        return -1;
    }
    // load devices_nodes
    hypergraph_load(argv[1], &number_of_devices, &number_of_nodes, &devices_nodes_eptr, &devices_nodes_eind);
    // get nodes_devices
    hypergraph_invers(number_of_devices, number_of_nodes, devices_nodes_eptr, devices_nodes_eind, &nodes_devices_eptr, &nodes_devices_eind);
    // iorder[old_lable] = new_lable
    f = fopen(argv[2], "r");
    order  = new int[number_of_nodes];
    iorder = new int[number_of_nodes];
    for (int i = 0; i < number_of_nodes; i++)
    {
        int v;
        fscanf(f, "%d", &v);
        order[v] = i;
        iorder[i] = v;
    }
    fclose(f);
    for (double ratio = atof(argv[3]); ratio <= atof(argv[4]); ratio += atof(argv[5]))
    {
        int z_matrix_size = 0;
        int partition_number = 0;
        double old_ratio = 0.0, new_ratio = 0.0;
        internal_nodes.clear();
        external_nodes.clear();
        temp_external_nodes.clear();
        handled_devices.clear();
        partition_internal_nodes_sets.clear();
        partition_external_nodes_sets.clear();
#if defined(DEBUG) || 1
        printf("total number of nodes : %d, ratio : %f\n", number_of_nodes, ratio);
#endif
        for (int i = 0; i < number_of_nodes; i++)
        {
            int internal_node = 1;
            // for all devices connected to this node - convert to old order
#ifdef DEBUG
            printf("scan devices connected to node %d (new order), %d (old order)\n", i, order[i]);
#endif
            for (int j = nodes_devices_eptr[order[i]]; j < nodes_devices_eptr[order[i] + 1]; j++)
            {
                auto iter = handled_devices.find(nodes_devices_eind[j]);
                if (iter == handled_devices.end())
                {
                    temp_handled_devices.insert(make_pair(nodes_devices_eind[j], partition_number));
                    // for all nodes connected to this device
#ifdef DEBUG
                    printf("scan nodes connected to device %d\n", nodes_devices_eind[j]);
#endif
                    for (int k = devices_nodes_eptr[nodes_devices_eind[j]]; k < devices_nodes_eptr[nodes_devices_eind[j] + 1]; k++)
                    {
#ifdef DEBUG
                        printf("node %d (old order), %d (new order)\n", devices_nodes_eind[k], iorder[devices_nodes_eind[k]]);
#endif
                        // convert to new order
                        if (internal_nodes.find(iorder[devices_nodes_eind[k]]) == internal_nodes.end())
                        {
                            temp_external_nodes.insert(iorder[devices_nodes_eind[k]]);
#ifdef DEBUG
                            printf("insert node %d into external nodes\n", iorder[devices_nodes_eind[k]]);
#endif
                        }
                    }
                }
                else if (iter->second != partition_number)
                {
                    internal_node = 0;
                }
            }
            new_ratio = (external_nodes.size() + temp_external_nodes.size()) > 0 ?
                        (((double)internal_nodes.size() + internal_node) / (external_nodes.size() + temp_external_nodes.size())) : (double)internal_nodes.size();
#ifdef DEBUG
            printf("internal_nodes : %d, external_nodes : %d, temp_external_nodes : %d, new_ratio : %g\n",
                   (int)internal_nodes.size(),
                   (int)external_nodes.size(),
                   (int)temp_external_nodes.size(),
                   new_ratio);
#endif
            if (old_ratio >= ratio && new_ratio < old_ratio)
            {
#ifdef DEBUG
                printf("revert node %d from partition %d\n", i, partition_number);
#endif
                printf("partition %d : internal nodes = %d, external nodes = %d, handled devices = %d\n",
                       partition_number++,
                       (int)internal_nodes.size(),
                       (int)external_nodes.size(),
                       (int)handled_devices.size());
                partition_internal_nodes_sets.push_back(internal_nodes);
                partition_external_nodes_sets.push_back(external_nodes);
                z_matrix_size += external_nodes.size();
#if defined(DEBUG) || defined(PRINT_NODES)
                printf("internal nodes : [");
                for (auto iter = internal_nodes.begin();
                        iter != internal_nodes.end();
                        iter++)
                {
                    printf("%d ", *iter);
                }
                printf("]\n");
                printf("may be ports : [");
                for (auto iter = external_nodes.begin();
                        iter != external_nodes.end();
                        iter++)
                {
                    printf("%d ", *iter);
                }
                printf("]\n");
#endif
                internal_nodes.clear();
                external_nodes.clear();
                i--;
                old_ratio = 0.0;
            }
            else
            {
                external_nodes.insert(temp_external_nodes.begin(), temp_external_nodes.end());
                handled_devices.insert(temp_handled_devices.begin(), temp_handled_devices.end());
                if (1 == internal_node)
                {
#ifdef DEBUG
                    printf("for partition %d add %d to internal_nodes and remove it from external_nodes\n", partition_number, i);
#endif
                    internal_nodes.insert(i);
                    external_nodes.erase(i);
                }
                old_ratio = new_ratio;
#if defined(DEBUG)
                printf("internal nodes : [");
                for (auto iter = internal_nodes.begin();
                        iter != internal_nodes.end();
                        iter++)
                {
                    printf("%d ", *iter);
                }
                printf("]\n");
                printf("may be ports : [");
                for (auto iter = external_nodes.begin();
                        iter != external_nodes.end();
                        iter++)
                {
                    printf("%d ", *iter);
                }
                printf("]\n");
#endif
            }
            temp_external_nodes.clear();
            temp_handled_devices.clear();
        }
        if (internal_nodes.size() > 0)
        {
            printf("partition %d : internal nodes = %d, external nodes = %d, handled devices = %d\n", partition_number,
                   (int)internal_nodes.size(),
                   (int)external_nodes.size(),
                   (int)handled_devices.size());
            partition_internal_nodes_sets.push_back(internal_nodes);
            partition_external_nodes_sets.push_back(external_nodes);
            z_matrix_size += external_nodes.size();
#if defined(DEBUG) || defined(PRINT_NODES)
            printf("internal nodes : [");
            for (auto iter = internal_nodes.begin();
                    iter != internal_nodes.end();
                    iter++)
            {
                printf("%d ", *iter);
            }
            printf("]\n");
            printf("may be ports : [");
            for (auto iter = external_nodes.begin();
                    iter != external_nodes.end();
                    iter++)
            {
                printf("%d ", *iter);
            }
            printf("]\n");
#endif
        }
        else
        {
            for (auto it = handled_devices.begin();
                      it != handled_devices.end();
                      it++)
            {
                if (it->second == partition_number)
                {
                    printf("device %d connected to nodes : ", it->first);
                    for (int k = devices_nodes_eptr[it->first]; k < devices_nodes_eptr[it->first + 1]; k++)
                    {
                        printf("[%d (old order), %d (new order)] ", devices_nodes_eind[k], iorder[devices_nodes_eind[k]]);
                    }
                    int part = 0, max_included_nodes = 0;
                    for (auto part_iter = partition_external_nodes_sets.begin();
                              part_iter != partition_external_nodes_sets.end();
                              part_iter++)
                    {
                        int included_nodes = 0;
                        for (int k = devices_nodes_eptr[it->first]; k < devices_nodes_eptr[it->first + 1]; k++)
                        {
                            if (part_iter->find(iorder[devices_nodes_eind[k]]) != part_iter->end())
                            {
                                included_nodes++;
                            }
                        }
                        if (included_nodes >= max_included_nodes)
                        {
                            max_included_nodes = included_nodes;
                            part = part_iter - partition_external_nodes_sets.begin();
                        }
                    }
                    printf(" - attach it to partition %d\n", part);
                    it->second = part;
                    for (int k = devices_nodes_eptr[it->first]; k < devices_nodes_eptr[it->first + 1]; k++)
                    {
                        partition_external_nodes_sets[part].insert(iorder[devices_nodes_eind[k]]);
                    }
                }
            }
        }
        printf("Z matrix size : %d\n", z_matrix_size / 2);
        printf("\n");
    }
    delete[] order;
    delete[] iorder;
    delete[] nodes_devices_eptr;
    delete[] nodes_devices_eind;
    delete[] devices_nodes_eptr;
    delete[] devices_nodes_eind;
    return 0;
}

