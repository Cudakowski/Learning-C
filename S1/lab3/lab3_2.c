#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomDouble(double min, double max)
{
    return(((double)rand()/RAND_MAX)*(max-min)+min);
}

void wypiszTabDoubleN(double *First, int N)
{
    for (int i=0 ; i < N; i++)
    {
        printf("A[%d] = %6.2lf\n",i,*(First+i));
    }
    
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    const int N=10;
    double tab[N]={};

    for (int i = 0; i < N; i++)
    {
        tab[i]=randomDouble(-100.0,100.0);
    }
    
    printf("Wylosowano tablice:\n");
    wypiszTabDoubleN(tab,N);

    double temp=0;

    for (int i = 0; i < N/2; i++)
    {
        temp=tab[i];
        tab[i]=tab[N-i-1];
        tab[N-i-1]=temp;
    }
    

    printf("\nPo odwroceniu:\n");
    wypiszTabDoubleN(tab,N);
    
    return 0;
}
