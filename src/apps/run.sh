# input file devices_nodes hypergraph
# output files :
#               - nodes_devices hypergraph
#               - nodes_nodes graph
#               - nodes_nodes pairs - original order
#               - nodes_nodes pairs - after ordering
cat ../../test/Linear_devices_nodes.txt | ./hinv | ./hedges > Linear_sparse_matrix.org
cat Linear_sparse_matrix.org | ./hpairs > Linear_sparse_matrix_pairs.org
cat Linear_sparse_matrix.org | ./horder | ./hpairs > Linear_sparse_matrix_pairs.orderd



cat ../../test/DAC_devices_nodes.txt | ./hinv | ./hedges > dac_sparse_matrix.org
cat dac_sparse_matrix.org | ./hpairs > dac_sparse_matrix_pairs.org
cat dac_sparse_matrix.org | ./horder | ./hpairs > dac_sparse_matrix_pairs.orderd

cat ../../test/ram2k_devices_nodes.txt | ./hinv | ./hedges > ram2k_sparse_matrix.org
cat ram2k_sparse_matrix.org | ./hpairs > ram2k_sparse_matrix_pairs.org
cat ram2k_sparse_matrix.org | ./horder | ./hpairs > ram2k_sparse_matrix_pairs.orderd

#./hinv ../../test/Linear_devices_nodes.txt | ./hedges | ./horder | ./hpart
