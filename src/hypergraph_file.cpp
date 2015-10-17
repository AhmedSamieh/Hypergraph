/******************************************************************************
 * hypergraph_file.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains the code to load and save hypergraph files.
 ******************************************************************************/
#include <cstdio>
#include <cstring>
#include <list>
#include "hypergraph_file.h"

using namespace std;

void hypergraph_load(const char *filename,
                     int        *nhedges,
                     int        *nvtxs,
                     int       **eptr,
                     int       **eind)
{
    FILE *fp;
    if ((fp = fopen(filename, "r")) != NULL)
    {
        hypergraph_load(fp, nhedges, nvtxs, eptr, eind);
        fclose(fp);
    }
    else
    {
        printf("Cannot Open File %s\n", filename);
    }
}
void hypergraph_load(FILE *fp,
                     int  *nhedges,
                     int  *nvtxs,
                     int **eptr,
                     int **eind)
{
    char buffer[128];
    list<int> *hedges;
    int number, delta, hedges_index, counter;
    unsigned int offset;
    char byte, byte2;
    //fgets(buffer, sizeof(buffer), fp);
    do
    {
        fgets(buffer, sizeof(buffer), fp);
    }
    while (buffer[0] == 'c');
    if (buffer[0] == 'p')
    {
        sscanf(buffer + 6, "%d%c%d%c%n", nvtxs, &byte2, nhedges, &byte, &delta);
    }
    else
    {
        sscanf(buffer, "%d%c%d%c%n", nhedges, &byte, nvtxs, &byte2, &delta);
    }
    *eptr = new int[*nhedges + 1];
    hedges = new list<int>[*nhedges];
    counter = 0;
    hedges_index = 0;
    offset = 0;
    while (fgets(buffer + offset, sizeof(buffer) - offset, fp))
    {
        //printf("buffer = {%s}\n", buffer);
        offset = 0;
        while (sscanf(buffer + offset, "%d%c%n", &number, &byte, &delta) == 2)
        {
            //printf("number = %d, byte = %c, delta = %d\n", number, byte, delta);
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
    if (offset != 0)
    {
        offset = 0;
        sscanf(buffer + offset, "%d%c%n", &number, &byte, &delta);
        //printf("number = %d, byte = %c, delta = %d\n", number, byte, delta);
        counter++;
        hedges[hedges_index].push_back(number);
        offset += delta;
        if (byte == '\n')
        {
            offset = sizeof(buffer) - 1;
            hedges_index++;
        }
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
                     int         nhedges,
                     int         nvtxs,
                     int        *eptr,
                     int        *eind)
{
    FILE *fp;
    if ((fp = fopen(filename, "w")) != NULL)
    {
        hypergraph_save(fp, nhedges, nvtxs, eptr, eind);
        fclose(fp);
    }
    else
    {
        printf("Cannot Open File %s\n", filename);
    }
}
void hypergraph_save(FILE *fp,
                     int   nhedges,
                     int   nvtxs,
                     int  *eptr,
                     int  *eind)
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
void hypergraph_save_pairs(const char *filename,
                           int         nhedges,
                           int        *eptr,
                           int        *eind)
{
    FILE *fp;
    if ((fp = fopen(filename, "w")) != NULL)
    {
        hypergraph_save_pairs(fp, nhedges, eptr, eind);
        fclose(fp);
    }
    else
    {
        printf("Cannot Open File %s\n", filename);
    }
}
void hypergraph_save_pairs(FILE *fp,
                           int   nhedges,
                           int  *eptr,
                           int  *eind)
{
    int i, j;

    for (i = 0; i < nhedges; i++)
    {
        for (j = eptr[i]; j < eptr[i + 1]; j++)
        {
            fprintf(fp, "%d %d\n", i, eind[j]);
        }
    }
}

