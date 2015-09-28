/******************************************************************************
 * hypergraph_file.h
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains the functions to load and save hypergraph files.
 ******************************************************************************/
#ifndef HYPERGRAPH_FILE_H
#define HYPERGRAPH_FILE_H
#include <cstdio>
void hypergraph_load(const char *filename,
                     int        *nhedges,
                     int        *nvtxs,
                     int       **eptr,
                     int       **eind);
void hypergraph_save(const char *filename,
                     int         nhedges,
                     int         nvtxs,
                     int        *eptr,
                     int        *eind);
void hypergraph_save_pairs(const char *filename,
                           int         nhedges,
                           int        *eptr,
                           int        *eind);
void hypergraph_load(FILE *fp,
                     int  *nhedges,
                     int  *nvtxs,
                     int **eptr,
                     int **eind);
void hypergraph_save(FILE *fp,
                     int   nhedges,
                     int   nvtxs,
                     int  *eptr,
                     int  *eind);
void hypergraph_save_pairs(FILE *fp,
                           int   nhedges,
                           int  *eptr,
                           int  *eind);
#endif

