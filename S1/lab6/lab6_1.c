#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *f_min(double *tab, int n);

double randomDouble(double min, double max)
{
    return(((double)rand()/RAND_MAX)*(max-min)+min);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    
    const int N=10;
    double tab[N]={};
    for (int i = 0; i < N; i++)
    {
        tab[i]=randomDouble(0.0,1.0);
        printf("tab[%d] = %lf, adres elementu: %p\n",i,tab[i],tab+i);
    }

    double *min=f_min(tab,N);

    printf("\nMinimum: tab[%d] = %lf, adres elementu: %p\n",min-tab,*min,min);
    
    return 0;
}

double *f_min(double *tab, int n)
{
    double *min=tab;
    for (int i = 0; i < n; i++)
    {
        if(tab[i]<*min)
        {
            min=tab;
        }
    }
    return min;
}
