# Makefile
#  auther  Ahmed Samieh
#  email   ahmed.samieh@gmail.com

all:
	g++ -Wall -Wextra hinv.cpp -I../ ../hypergraph_inverse.cpp ../hypergraph_file.cpp -o hinv
	g++ -Wall -Wextra hpairs.cpp -I../ ../hypergraph_file.cpp -o hpairs
	g++ -Wall -Wextra horder_cm.cpp -I../ -I../order ../hypergraph_file.cpp ../order/CutHillMcKee.cpp ../order/apply_order.cpp -o horder_cm
	g++ -Wall -Wextra horder_rcm.cpp -I../ -I../order ../hypergraph_file.cpp ../order/ReverseCutHillMcKee.cpp ../order/apply_order.cpp -o horder_rcm
	g++ -Wall -Wextra horder_metis.cpp -I../ -I../order ../hypergraph_file.cpp ../order/apply_order.cpp -o horder_metis
	g++ -Wall -Wextra hedges.cpp -I../ ../hypergraph_edges.cpp ../hypergraph_file.cpp -o hedges
	g++ -Wall -Wextra hedges.cpp -I../ ../hypergraph_edges.cpp ../hypergraph_file.cpp -DMETIS -o hedges_metis
	g++ -Wall -Wextra hpart.cpp -I../ ../graph_partition.cpp ../hypergraph_file.cpp -o hpart
	g++ -Wall -Wextra hecho.cpp -I../ ../hypergraph_file.cpp -o hecho
	g++ -Wall -Wextra habs.cpp -I../ ../hypergraph_file.cpp -o habs
	g++ -Wall -Wextra htask.cpp -I../ -I../order ../order/apply_order.cpp ../order/CutHillMcKee.cpp ../hypergraph_edges.cpp ../hypergraph_inverse.cpp ../hypergraph_file.cpp -o htask

clean:
	rm -rf hinv hpairs horder_cm horder_rcm hedges hpart hecho habs htask

