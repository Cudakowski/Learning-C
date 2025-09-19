#include <stdio.h>
#include <stdlib.h>

//#include "../my_functions/functions_1d.c"


double *my_alloc(int i_min, int i_max);
void my_free(double **my_tab, int i_min);
void printnij(double *tab,int min, int max);


int main()
{
    int min=-2,max=4;
    double *tab=my_alloc(min,max);

    for (int i = min; i <= max; i++)
    {
        tab[i]=8.8;
    }
    
    printnij(tab,min,max);

    d_array_set_random(tab+min+1,tab+max,4.1,5.6);

    printnij(tab,min,max);


    my_free(&tab,min);
    my_free(&tab,min);

    return 0;
}

double *my_alloc(int i_min, int i_max)
{
    double * tab=malloc(sizeof(double)*(i_max-i_min+1));
    return tab-i_min;
}

void my_free(double **my_tab, int i_min)
{   
    if(*my_tab==NULL)
    {
        return;
    }
    
    free(*my_tab+i_min);
    
    *my_tab=NULL;
    return;
}

void printnij(double *tab,int min, int max)
{
    for (int i = min; i <= max; i++)
    {
        printf("Indeks: %d, Wartosc: %lf, Adres: %p\n",i,tab[i],tab+i);
    }
}
