#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define MAXMASS 100

typedef struct point {
    int mass;
    int isDeleted;
}point;

void createMesh(int size, point arr[size])
{
    for(int i =0;i < size; i++)
    {
        arr[i].mass = rand() % MAXMASS + 1;
        arr[i].isDeleted = 0;
    }
}

void print_mesh(int size,point arr[size])
{
	printf("Your mesh\n");

	for(int i = 0;i < size; i++) printf("[%d]\t",i);
	printf("\n");

	for(int i = 0;i < size; i++) printf(" %d \t",arr[i].mass);
	printf("\n");
}

void cycle(int size,point arr[size])
{
    int rem = size -1;

    print_mesh(size,arr);

    while (rem)
    {
        int min_mass = MAXMASS * MAXMASS;
        int min_crd = 0;
        for(int i = 0; i < size; i++)
        {
            if(arr[i].mass < min_mass )
            {
		if(arr[i].isDeleted) continue;

                min_mass = arr[i].mass;
                min_crd = i;
            }
        }

	printf("Deleting point [%d]\n",min_crd);

        for(int i = 1; i < size;i++)
        {
            int lc = min_crd - i,
                rc = min_crd + i;

            if(lc > 0)
            {
                if(!arr[lc].isDeleted)
                {
                    arr[lc].mass += min_mass;
                    arr[min_crd].isDeleted = 1;
		    arr[min_crd].mass = 0;

                    break;
                }
            }

            if(rc < size)
            {
                if(!arr[rc].isDeleted)
                {
                    arr[rc].mass += min_mass;
                    arr[min_crd].isDeleted = 1;
		    arr[min_crd].mass = 0;

                    break;
                }
            }
        }

	rem--;
    	print_mesh(size,arr);
	printf("Press any key to coninue . . . ");
	getchar();
    }
}

int main()
{
    int size = SIZE;
    point arr[size];

    createMesh(size, arr);
    cycle(size,arr);

    
    return EXIT_SUCCESS;
}
