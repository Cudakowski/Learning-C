#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10000

void TheFunkcja(const int n,double *srednia, double *warianc, double *odchyl);

double randomDouble(double min, double max)
{
    return(((double)rand()/RAND_MAX)*(max-min)+min);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    double srednia=0;
    double warianc=0;
    double odchyl=0;

    TheFunkcja(N,&srednia,&warianc,&odchyl);

    printf("Srednia: %lf\n",srednia);
    printf("Wariancja: %lf\n",warianc);
    printf("Odchylenie standardowe: %lf\n",odchyl);

    return 0;
}

void TheFunkcja(const int n,double *srednia, double *warianc, double *odchyl)
{
    double tab[n];
    double sum=0;
    for (int i = 0; i < n; i++)
    {
        tab[i]=randomDouble(0.0,1.0);
        sum+=tab[i];
    }

    *srednia=sum/n;

    double sum2=0;

    for (int i = 0; i < n; i++)
    {
        sum2+=(tab[i]-*srednia)*(tab[i]-*srednia);
    }
    
    *warianc=sum2/n;

    *odchyl=sqrt(*warianc);
    return;
}

