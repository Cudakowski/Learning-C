#include <stdio.h>
#include <stdlib.h>

#include "functions_1d.h"

int ii_rand(int min, int max)
{
    return(min+rand()%(max-min+1));
}

double dd_rand(double min, double max)
{
    return(((double)rand()/RAND_MAX)*(max-min)+min);
}

void i_array_print(const int *first, const int *last, const char *header)
{
    printf("%s",header);
    for (; first < last; first++)
    {
        printf("%d ",*first);
    }
    printf("\n");
}

void d_array_print(const double *first, const double *last, const char *header)
{
    printf("%s",header);
    for (; first < last; first++)
    {
        printf("%lf ",*first);
    }
    printf("\n");
}

void i_array_set_zero(int *first, int *last)
{
    last--;
    for (; first <= last; last--)
    {
        *last=0;
    }
}

void d_array_set_zero(double *first, double *last)
{
    last--;
    for (; first <= last; last--)
    {
        *last=0.0;
    }
}

void i_array_set_random(int *first, int *last, int min, int max)
{
    last--;
    for (; first <= last; last--)
    {
        *last=ii_rand(min,max);
    }
}

void d_array_set_random(double *first, double *last, double min, double max)
{
    last--;
    for (; first <= last; last--)
    {
        *last=dd_rand(min,max);
    }
}

double d_sum(double *first, double *last)
{
    double sum=0;
    for (; first < last; first++)
    {
        sum+=*first;
    }
    return sum;
}

double d_avr(double *first, double *last)
{
    double sum=0;
    int count=last-first;
    for (; first < last; first++)
    {
        sum+=*first;
    }
    return (sum/count);
}

double d_multipy(double *first, double *last)
{
    double result=1;
    for (; first < last; first++)
    {
        result*=*first;
    }
    return result;
}

double * d_min(double *first, double *last)
{
    double *min=first;
    for (; first < last; first++)
    {
        if(*min>*first)
            min=first;
    }
    return min;
}

double * d_max(double *first, double *last)
{
    double *max=first;
    for (; first < last; first++)
    {
        if(*max<*first)
            max=first;
    }
    return max;
}
