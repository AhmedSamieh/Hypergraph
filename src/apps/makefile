# Makefile
#  auther  Ahmed Samieh
#  email   ahmed.samieh@gmail.com

all:
	g++ -Wall -Wextra hinv.cpp -I../ ../hypergraph_inverse.cpp ../hypergraph_file.cpp -o hinv
	g++ -Wall -Wextra hpairs.cpp -I../ ../hypergraph_file.cpp -o hpairs
	g++ -Wall -Wextra horder.cpp -I../ -I../order ../hypergraph_file.cpp ../order/CutHillMcKee.cpp ../order/apply_order.cpp -o horder
	g++ -Wall -Wextra hedges.cpp -I../ ../hypergraph_edges.cpp ../hypergraph_file.cpp -o hedges

clean:
	rm -rf hinv hpairs horder hedges

