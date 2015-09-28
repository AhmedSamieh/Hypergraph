/******************************************************************************
 * hypergraph_edges.h
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains the function to get edge_edges graph from the hypergraph,
 ******************************************************************************/
#ifndef HYPERGRAPH_EDGES_H
#define HYPERGRAPH_EDGES_H
void hypergraph_edges(int   nhedges,
                      int   nvtxs,
                      int  *eptr,
                      int  *eind,
                      int **edges_eptr,
                      int **edges_eind);
#endif

