FILE_NAME=Linear
./hinv ../../test/${FILE_NAME}_devices_nodes.txt > ${FILE_NAME}_nodes_devices.txt
./hedges ${FILE_NAME}_nodes_devices.txt > ${FILE_NAME}_sparse_matrix_org.txt
./hpairs ${FILE_NAME}_sparse_matrix_org.txt > ${FILE_NAME}_sparse_matrix_org_pairs.txt

./hedges_metis ${FILE_NAME}_nodes_devices.txt > ${FILE_NAME}_sparse_matrix_org_for_metis.txt
./ndmetis ${FILE_NAME}_sparse_matrix_org_for_metis.txt
./horder_metis ${FILE_NAME}_sparse_matrix_org.txt ${FILE_NAME}_sparse_matrix_org_for_metis.txt.iperm > ${FILE_NAME}_sparse_matrix_mts.txt
./hpairs ${FILE_NAME}_sparse_matrix_mts.txt > ${FILE_NAME}_sparse_matrix_mts_pairs.txt
./hpart2 ${FILE_NAME}_sparse_matrix_mts.txt ${FILE_NAME}_nodes_devices.txt ../../test/${FILE_NAME}_devices_nodes.txt ${FILE_NAME}_sparse_matrix_org_for_metis.txt.iperm 4.0 20.0 1.0 > ${FILE_NAME}_sparse_matrix_mts_parts.txt
