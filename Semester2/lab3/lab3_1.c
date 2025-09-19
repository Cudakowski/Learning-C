#include <stdio.h>

//#include "../my_functions/functions_1d.c"


void testEndianness();
void funk(double *tab, size_t size, double *sum, double *avr, double *mult, double **minptr, double **maxptr);

int main(int argc, char const *argv[])
{

    testEndianness();
    
    size_t size=20;
    double tab[size];

    d_array_set_random(tab,tab+size,-10.0,10.0);
    d_array_print(tab,tab+size,"Przed:\n");

    double sum;
    double avr;
    double mult;
    double *minptr;
    double *maxptr;

    funk(tab,size,&sum,&avr,&mult,&minptr,&maxptr);
    
    printf("sum=%lf, avr=%lf, mult=%lf, min=%lf, max=%lf\n",sum,avr,mult,*minptr,*maxptr);

    return 0;
}

void testEndianness()
{
    unsigned int i=0xAABBCCDD;//dane
    void *ptr=&i;//do początku danych czyli albo AA albo DD
    //printf("%d",*((unsigned char*)(ptr+3)));
    if(*((unsigned char*)(ptr))>*((unsigned char*)(ptr+1)))//porównywanie z następnym czyli albo AA z BB albo DD z CC
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
}

void funk(double *tab, size_t size, double *sum, double *avr, double *mult, double **minptr, double **maxptr)
{
    *sum=d_sum(tab,tab+size);
    *avr=d_avr(tab,tab+size);
    *mult=d_multipy(tab,tab+size);
    *minptr=d_min(tab,tab+size);
    *maxptr=d_max(tab,tab+size);
}
