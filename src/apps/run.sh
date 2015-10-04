# input file devices_nodes hypergraph
# output files :
#               - nodes_devices hypergraph
#               - nodes_nodes graph
#               - nodes_nodes pairs - original order
#               - nodes_nodes pairs - after ordering
cat ../../test/Linear_devices_nodes.txt | ./hinv | ./hedges > Linear_sparse_matrix.org
cat Linear_sparse_matrix.org | ./hpairs > Linear_sparse_matrix_pairs.org
cat Linear_sparse_matrix.org | ./horder | ./hpairs > Linear_sparse_matrix_pairs.orderd
