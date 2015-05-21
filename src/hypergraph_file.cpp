#include <cstdio>
#include <cstring>
#include <list>
#include "hypergraph_file.h"

using namespace std;

void hypergraph_load(const char *filename,
                     int *nhedges,
                     int *nvtxs,
                     int **eptr,
                     int **eind)
{
    FILE *fp;
    if ((fp = fopen(filename, "r")) != NULL)
    {
        hypergraph_load(fp, nhedges, nvtxs, eptr, eind);
        fclose(fp);
    }
}
void hypergraph_load(FILE *fp,
                     int *nhedges,
                     int *nvtxs,
                     int **eptr,
                     int **eind)
{
    char buffer[128];
    list<int> *hedges;
    int number, offset, delta, hedges_index, counter;
    char byte, byte2;
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "%d%c%d%c%n", nhedges, &byte, nvtxs, &byte2, &delta);
    *eptr = new int[*nhedges + 1];
    hedges = new list<int>[*nhedges];
    counter = 0;
    hedges_index = 0;
    offset = 0;
    while (fgets(buffer + offset, sizeof(buffer) - offset, fp))
    {
        offset = 0;
        while (sscanf(buffer + offset, "%d%c%n", &number, &byte, &delta) == 2)
        {
            counter++;
            hedges[hedges_index].push_back(number);
            offset += delta;
            if (byte == '\n')
            {
                offset = sizeof(buffer) - 1;
                hedges_index++;
            }
        }
        if (offset < sizeof(buffer) - 1)
        {
            memmove(buffer, buffer + offset, sizeof(buffer) - offset);
        }
        offset = sizeof(buffer) - offset - 1;
    }
    *eind = new int[counter];
    counter = 0;
    hedges_index = 0;
    (*eptr)[hedges_index] = counter;
    for (int i = 0; i < *nhedges; i++)
    {
        for (list<int>::iterator iter = hedges[i].begin();
             iter != hedges[i].end();
             iter++)
        {
            (*eind)[counter++] = *iter;
        }
        (*eptr)[++hedges_index] = counter;
    }
    delete[] hedges;
}
void hypergraph_save(const char *filename,
                     int nhedges,
                     int nvtxs,
                     int *eptr,
                     int *eind)
{
    FILE *fp;
    if ((fp = fopen(filename, "w")) != NULL)
    {
        hypergraph_save(fp, nhedges, nvtxs, eptr, eind);
        fclose(fp);
    }
}
void hypergraph_save(FILE *fp,
                     int nhedges,
                     int nvtxs,
                     int *eptr,
                     int *eind)
{
    int i, j;

    fprintf(fp, "%d %d\n", nhedges, nvtxs);
    for (i = 0; i < nhedges; i++)
    {
        for (j = eptr[i]; j < eptr[i + 1]; j++)
        {
            fprintf(fp, "%s%d", j == eptr[i] ? "" : " ", eind[j]);
        }
        fprintf(fp, "\n");
    }
}
