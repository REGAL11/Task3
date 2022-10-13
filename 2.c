#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

void
arr_fill(int size,int* arr)
{
    for(int i = 0; i < size; i ++)
    {
        arr[i] = rand() % 101 - 50;
    }
}

void
arr_print(int size,int arr[size])
{
    printf("Your array:\n");
    for(int i = 0; i < size; i ++)
    {
        printf("[%d]: %d\t",i,arr[i]);
    }

    putchar('\n');
}

int
arr_getAverage(int size,int arr[size])
{
    int sum = 0;
    for(int i = 0; i < size; i++) sum += arr[i];

    return (sum / size);
}

int 
arr_countBiggerThanAver(int size,int arr[size])
{
    int count = 0,
        aver  = arr_getAverage(size, arr);

    for(int i = 0;i < size;i++) arr[i] > aver ? count += 1 : 0;

    return count;
}

int
arr_sumOfMod(int size,int arr[size])
{
    int start = 0,
        sum  = 0;

    for(int i = 0; i < size; i++ )
    {
        if(arr[i] < 0)
        {
            start = i + 1;
            break;
        }
    }

    if(start >= size) return 0;
    for(int i = start; i < size; i++)
    {
        if(arr[i] < 0) sum += -1 * arr[i];
        else sum += arr[i];
    }

    return sum;
}

int
main()
{
    int size = SIZE;
    int arr[size];

    arr_fill(size, arr);

    arr[0] = 115;
    arr[1] = 78;

    arr_print(size, arr);

    printf("Average: %d\n",arr_getAverage(size, arr));
    printf("Count of elements bigger than average: %d\n",
                            arr_countBiggerThanAver(size, arr));

    printf("Sum of modules of elements, after first negative: %d\n"
                                                ,arr_sumOfMod(size, arr));

    
    return EXIT_SUCCESS;
}