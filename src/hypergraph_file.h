#include <cstdio>
void hypergraph_load(const char *filename, int *nhedges, int *nvtxs, int **eptr, int **eind);
void hypergraph_save(const char *filename, int nhedges, int nvtxs, int *eptr, int *eind);
void hypergraph_load(FILE *fp, int *nhedges, int *nvtxs, int **eptr, int **eind);
void hypergraph_save(FILE *fp, int nhedges, int nvtxs, int *eptr, int *eind);
