# Hypergraph file format:
First line has 2 integers, the first integer is the number of hyperedges |E|, the second integer is the number of vertices |V|.
we will add third integer (fmt) to include information about the type of hg, as 3.4 section in hmetis manual.pdf

After the first line we have |E| lines store the vertices contained in each hyperedge, one line per hyperedge

vertices and hyperedges count start from zero to |V - 1| and |E - 1|

