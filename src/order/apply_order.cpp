/******************************************************************************
 * apply_order.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains the function to change matrix order
 ******************************************************************************/
// nedges    : input
// xadj      : input/output
// adjacency : input/output
// order     : input - order[new_lable] = old_lable
void apply_order(int nedges, int **xadj, int **adjacency, int *order)
{
    int i, j;
    int *iorder, *temp_xadj, *temp_adjacency;

    iorder = new int[nedges];
    temp_xadj = new int[nedges + 1];
    temp_adjacency = new int[(*xadj)[nedges]];
    // iorder[old_lable] = new_lable
    for (i = 0; i < nedges; i++)
    {
        iorder[order[i]] = i;
    }
    temp_xadj[0] = 0;
    for (i = 0; i < nedges; i++)
    {
        temp_xadj[i + 1] = temp_xadj[i] + (*xadj)[order[i] + 1] - (*xadj)[order[i]];
        for (j = temp_xadj[i]; j < temp_xadj[i + 1]; j++)
        {
            temp_adjacency[j] = iorder[(*adjacency)[j - temp_xadj[i] + (*xadj)[order[i]]]];
        }
    }
    delete[] iorder;
    delete[] *xadj;
    delete[] *adjacency;
    *xadj = temp_xadj;
    *adjacency = temp_adjacency;
}

