/******************************************************************************
 * order.h
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains all functions used to order the matrix
 ******************************************************************************/
#ifndef ORDER_H
#define ORDER_H
void apply_order(int nedges, int **xadj, int **adjacency, int *order);
void CutHillMcKee(int nedges, int *xadj, int *adjacency, int *iorder);
void ReverseCutHillMcKee(int nedges, int *xadj, int *adjacency, int *iorder);
#endif

