/******************************************************************************
 * ReverseCutHillMcKee.cpp
 *  auther  Ahmed Samieh
 *  email   ahmed.samieh@gmail.com
 *
 *          contains the function to apply ReverseCutHillMcKee algorithm
 *          to find new order to reduce fillins
 ******************************************************************************/
void ReverseCutHillMcKee(int nedges, int *xadj, int *adjacency, int *order)
{
    // allocate memory
    int *degree = new int[nedges];
    int *handled = new int[nedges];
    // initialize data
    for (int i = 0; i < nedges; i++)
    {
        degree[i] = xadj[i + 1] - xadj[i];
#if defined(DEBUG)
        printf("%d ) degree = %d\n", i, degree[i]);
#endif
        handled[i] = 0;
    }
    for (int i = 0, j = nedges - 1, l = nedges - 1; i < nedges; i++)
    {
        if (handled[i] == 0)
        {
            int x = i;
#if defined(DEBUG)
            printf("insert new head\n");
#endif
            for (int k = i + 1; k < nedges; k++)
            {
                if (handled[k] == 0 && degree[k] < degree[x])
                {
#if defined(DEBUG)
                    printf("it may be %d\n", x);
#endif
                    x = k;
                }
            }
#if defined(DEBUG)
            printf("it will be %d\n", x);
#endif
            handled[x] = 1;
            order[j--] = x;
            for (; l > j; l--)
            {
#if defined(DEBUG)
                printf("find connectivity for %d\n", order[l]);
#endif
                for (int k = xadj[order[l]]; k < xadj[order[l] + 1]; k++)
                {
                    if (handled[adjacency[k]] == 0)
                    {
                        int y = adjacency[k];
#if defined(DEBUG)
                        printf("insert new connectivity\n");
#endif
                        for (int m = k + 1; m < xadj[order[l] + 1]; m++)
                        {
                            if (handled[adjacency[m]] == 0 && degree[adjacency[m]] < degree[y])
                            {
#if defined(DEBUG)
                                printf("it may be %d\n", y);
#endif
                                y = adjacency[m];
                            }
                        }
#if defined(DEBUG)
                        printf("it will be %d\n", y);
#endif
                        handled[y] = 1;
                        order[j--] = y;
                    }
                }
            }
        }
#if defined(DEBUG)
        else
        {
            printf("%d had been handled\n", i);
        }
#endif
    }
    // order[L] = i means that the new label of node i (the one that had the initial label of i) will be L
    // free memory
    delete[] handled;
    delete[] degree;
}

