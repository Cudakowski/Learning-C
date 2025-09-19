#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_identity(const short *first, const short *last);

int main(int argc, char const *argv[])
{
    short tab[5][5]={
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1}
    };

    if(is_identity(*tab,*tab+5*5))
    {
        printf("Git\n");
    }
    else
    {
        printf("NIE Git\n");
    }

    return 0;
}

bool is_identity(const short *first, const short *last)
{
    double m=sqrt((double)(last-first));
    int n=m;
    if((double)n!=m)
        return false;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if(j==i)
            {
                if(first[5*i+j]!=1)
                    return false;
            }
            else
            {
                if(first[5*i+j]!=0)
                    return false;
            }
        }
        
    }
    return true;
    
}
