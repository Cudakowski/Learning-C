#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../my_functions/functions_1d.c"
#include "../my_functions/functions_0d.c"

#define ROWS 4
#define COLS 7

double *min_pointer(double * first,size_t size);
double **min_pointers_of_rows(double (* first)[COLS],int rows);

int main()
{   
    srand(time(NULL));

    
    double tab[ROWS][COLS];

    for (size_t i = 0; i < ROWS; i++)
    {
        d_array_set_random(*(tab+i),*(tab+i+1),4.0,6.0);
    }
    
    for (size_t i = 0; i < ROWS; i++)
    {
        d_array_print(*(tab+i),*(tab+i+1),"");
    }


    printf("\n");


    double * minptr=min_pointer(*tab,ROWS*COLS);
    printf("A = %p = %lf\n",minptr,*minptr);


    printf("\n");


    double **mintab=min_pointers_of_rows(tab,ROWS);
    for (size_t i = 0; i < ROWS; i++)
    {
        printf("%p  =  %lf\n",*(mintab+i),*(*(mintab+i)));
    }


    printf("\n");

    
    swap(minptr,*(mintab+3),sizeof(*tab));


    for (size_t i = 0; i < ROWS; i++)
    {
        d_array_print(*(tab+i),*(tab+i+1),"");
    }

    free(mintab);

    return 0;
}

double *min_pointer(double * first,size_t size)
{
    return(d_min(first,first+size));
}

double **min_pointers_of_rows(double (* first)[COLS],int rows)
{
    double **tab=malloc(sizeof(double)*rows);
    for (size_t i = 0; i < rows; i++)
    {
        *(tab+i)=d_min(*(first+i),*(first+i+1));
    }
    return tab;
}
