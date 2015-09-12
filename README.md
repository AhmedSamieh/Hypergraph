# Hypergraph
Base project for hypergraph partitioning

To check the order algorithm output

cat test/sparse_matrix | apps/hpairs > original
cat test/sparse_matrix | apps/horder | apps/hpairs > cm

Then open original using excel and drow XY scatter chart

