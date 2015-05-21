/*
 * we will convert the vertices to hyperedges and the hyperedges to vertices
 * size of eptr will be changes from nhedges+1 to nvtxs+1
 * */
void hypergraph_invers(int  nhedges, int  nvtxs, int *eptr, int *eind, int *vptr, int *vind);
