#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selectionsort(int *array, int count)
{
        if (!array)
                return -10;
        int i, j, tmp;
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
        return 0;
}

int main()
{
        printf("%I64d %d\n", time(0), RAND_MAX);
        srand(time(0));
        int *arr = malloc(sizeof(int) * 1000);
        for (int i = 0; i < 1000; i++)
        {
                arr[i] = rand();
        }
        int a = selectionsort(arr, 1000);
        printf("%d \n", a);
        for (int i = 0; i < 1000; i++)
        {
                printf("%d ", arr[i]);
        }
}