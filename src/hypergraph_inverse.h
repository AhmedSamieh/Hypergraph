/******************************************************************************
 * hypergraph_invers.h
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains the function to invers hypergraph,
 *          convert hyperedges to vertices and visa versa.
 *          size of eptr will be changed from nhedges+1 to nvtxs+1
 ******************************************************************************/
#ifndef HYPERGRAPH_INVERS_H
#define HYPERGRAPH_INVERS_H
void hypergraph_invers(int   nhedges,
                       int   nvtxs,
                       int  *eptr,
                       int  *eind,
                       int **inv_eptr,
                       int **inv_eind);
#endif

