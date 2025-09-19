#include <stdlib.h>
#include <string.h>

#include "functions_0d.h"

int i_rand(int min, int max)
{
    return(min+rand()%(max-min+1));
}

double d_rand(double min, double max)
{
    return(((double)rand()/RAND_MAX)*(max-min)+min);
}

void i_swap(int *restrict first, int *restrict second)
{
    if(first != second)
    {
        int temp = *first;
        *first=*second;
        *second=temp;
    }
}

void swap(void * first, void * second, size_t size)
{
    void *temp=malloc(size);
    
    memcpy(temp,first,size);
    memcpy(first,second,size);
    memcpy(second,temp,size);

    free(temp);
}


