
#./hinv ../../test/ram2k_devices_nodes.txt | ./hedges | ./horder_cm > ram2k_cm.txt
#cat ram2k_cm.txt | ./hpart > ram2k_cm_part.txt
#./hinv ../../test/ram2k_devices_nodes.txt | ./hedges | ./horder_rcm > ram2k_rcm.txt
#cat ram2k_rcm.txt | ./hpart > ram2k_rcm_part.txt

./hinv       ../../test/ram2k_devices_nodes.txt   > ../../test/ram2k_nodes_devices.txt
./hedges     ../../test/ram2k_nodes_devices.txt   > ../../test/ram2k_nodes_nodes.txt
./horder_cm  ../../test/ram2k_nodes_nodes.txt     > ../../test/ram2k_nodes_nodes_cm.txt
./horder_rcm ../../test/ram2k_nodes_nodes.txt     > ../../test/ram2k_nodes_nodes_rcm.txt
./hpairs     ../../test/ram2k_nodes_nodes.txt     > ../../test/ram2k_nodes_nodes_org_pairs.txt
./hpairs     ../../test/ram2k_nodes_nodes_cm.txt  > ../../test/ram2k_nodes_nodes_cm_pairs.txt
./hpairs     ../../test/ram2k_nodes_nodes_rcm.txt > ../../test/ram2k_nodes_nodes_rcm_pairs.txt
./hpart      ../../test/ram2k_nodes_nodes_cm.txt  > ../../test/ram2k_nodes_nodes_cm_parts.txt
./hpart      ../../test/ram2k_nodes_nodes_rcm.txt > ../../test/ram2k_nodes_nodes_rcm_parts.txt

./hinv       ../../test/dllrc_devices_nodes.txt   > ../../test/dllrc_nodes_devices.txt
./hedges     ../../test/dllrc_nodes_devices.txt   > ../../test/dllrc_nodes_nodes.txt
./horder_cm  ../../test/dllrc_nodes_nodes.txt     > ../../test/dllrc_nodes_nodes_cm.txt
./horder_rcm ../../test/dllrc_nodes_nodes.txt     > ../../test/dllrc_nodes_nodes_rcm.txt
./hpairs     ../../test/dllrc_nodes_nodes.txt     > ../../test/dllrc_nodes_nodes_org_pairs.txt
./hpairs     ../../test/dllrc_nodes_nodes_cm.txt  > ../../test/dllrc_nodes_nodes_cm_pairs.txt
./hpairs     ../../test/dllrc_nodes_nodes_rcm.txt > ../../test/dllrc_nodes_nodes_rcm_pairs.txt
./hpart      ../../test/dllrc_nodes_nodes_cm.txt  > ../../test/dllrc_nodes_nodes_cm_parts.txt
./hpart      ../../test/dllrc_nodes_nodes_rcm.txt > ../../test/dllrc_nodes_nodes_rcm_parts.txt

#./hinv ~/Desktop/ngspice-26/devices_nodes_hypergraph.txt > dll_nodes_devices_hg.txt
#./hedges dll_nodes_devices_hg.txt > dll_edges.txt
#./hpairs dll_edges.txt > dll_pairs.org
#./horder_cm dll_edges.txt > dll_cm.txt
#./horder_rcm dll_edges.txt > dll_rcm.txt
#./hpairs dll_rcm.txt > dll_pairs.rcm
#./hpairs dll_cm.txt > dll_pairs.cm
#./hpart dll_cm.txt > dll_rcm_part.txt
