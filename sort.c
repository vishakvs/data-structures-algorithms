#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ASC_SORT 10
#define DES_SORT 20

//-------------------------Comparison sorts----------------------//

// void bubblesort();

// Selection sort
int selectionsort(int *array, int count, int order)
{
        if (!array)
                return -10;
        if (!(order == 10 || order == 20))
                return -20;
        int i, j, tmp;
        if (order == ASC_SORT)
        {
                for (i = 0; i < count; i++)
                {
                        tmp = i;
                        for (j = i + 1; j < count; j++)
                        {
                                if (array[j] < array[tmp])
                                {
                                        tmp = j;
                                }
                        }
                        if (tmp != i)
                        {
                                int a = array[i];
                                array[i] = array[tmp];
                                array[tmp] = a;
                        }
                }
        }
        // could have omitted this if block, but considering the tiny
        // performance hit from comparing the 'order' variable for each loop,
        // had to include this block down here
        else if (order == DES_SORT)
        {
                for (i = 0; i < count; i++)
                {
                        tmp = i;
                        for (j = i + 1; j < count; j++)
                        {
                                if (array[j] > array[tmp])
                                {
                                        tmp = j;
                                }
                        }
                        if (tmp != i)
                        {
                                int a = array[i];
                                array[i] = array[tmp];
                                array[tmp] = a;
                        }
                }
        }
        return 0;
}

//----------------------test main--------------------------------//
int main()
{
        printf("%I64d %d\n", time(0), RAND_MAX);
        srand(time(0));
        int *arr = malloc(sizeof(int) * 1000);
        // int *selsort = malloc(sizeof(int) * 1000000);
        for (int i = 0; i < 1000; i++)
        {
                arr[i] = rand() % 250;
        }
        int a = selectionsort(arr, 1000, 20);
        printf("%d \n", a);
        for (int i = 0; i < 1000; i++)
        {
                printf("%d ", arr[i]);
        }
}