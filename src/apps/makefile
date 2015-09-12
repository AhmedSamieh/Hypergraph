# Makefile
#  auther  Ahmed Samieh
#  email   ahmed.samieh@gmail.com

all:
	g++ hinv.cpp -I../ ../hypergraph_inverse.cpp ../hypergraph_file.cpp -o hinv
	g++ hpairs.cpp -I../ ../hypergraph_file.cpp -o hpairs
	g++ horder.cpp -I../ -I../order ../hypergraph_file.cpp ../order/CutHillMcKee.cpp ../order/apply_order.cpp -o horder

clean:
	rm -rf hinv hpairs horder

