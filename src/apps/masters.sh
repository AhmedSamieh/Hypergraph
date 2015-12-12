FILE_NAME=Linear
./hinv ../../test/${FILE_NAME}_devices_nodes.txt > ${FILE_NAME}_nodes_devices.txt
./hedges ${FILE_NAME}_nodes_devices.txt > ${FILE_NAME}_sparse_matrix_org.txt
./hpairs ${FILE_NAME}_sparse_matrix_org.txt > ${FILE_NAME}_sparse_matrix_org_pairs.txt

./horder_cm ${FILE_NAME}_sparse_matrix_org.txt > ${FILE_NAME}_sparse_matrix_cm.txt
./hpairs ${FILE_NAME}_sparse_matrix_cm.txt > ${FILE_NAME}_sparse_matrix_cm_pairs.txt
./hpart ${FILE_NAME}_sparse_matrix_cm.txt 5.0 > ${FILE_NAME}_sparse_matrix_cm_parts.txt

./horder_rcm ${FILE_NAME}_sparse_matrix_org.txt > ${FILE_NAME}_sparse_matrix_rcm.txt
./hpairs ${FILE_NAME}_sparse_matrix_rcm.txt > ${FILE_NAME}_sparse_matrix_rcm_pairs.txt
./hpart ${FILE_NAME}_sparse_matrix_rcm.txt 5.0 > ${FILE_NAME}_sparse_matrix_rcm_parts.txt

./hedges_metis ${FILE_NAME}_nodes_devices.txt > ${FILE_NAME}_sparse_matrix_org_for_metis.txt
./ndmetis ${FILE_NAME}_sparse_matrix_org_for_metis.txt
./horder_metis ${FILE_NAME}_sparse_matrix_org.txt ${FILE_NAME}_sparse_matrix_org_for_metis.txt.iperm > ${FILE_NAME}_sparse_matrix_mts.txt
./hpairs ${FILE_NAME}_sparse_matrix_mts.txt > ${FILE_NAME}_sparse_matrix_mts_pairs.txt
./hpart ${FILE_NAME}_sparse_matrix_mts.txt 5.0 > ${FILE_NAME}_sparse_matrix_mts_parts.txt
