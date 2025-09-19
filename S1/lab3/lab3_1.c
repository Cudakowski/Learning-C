#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float randomFloat(float min, float max)
{
    return(((float)rand()/RAND_MAX)*(max-min)+min);
}


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int n=0;

    do
    {
        printf("Podaj liczbe losowan: ");
        scanf("%d",&n);
    } while (n<=0);

    int tab[10]={};
    float x=0;

    for (int i = 0; i < n; i++)
    {
        x=randomFloat(0.0,9.9999);
        for (int j = 0; j < 10; j++)
        {
            if(x>=0.0+j&&x<1.0+j){
                tab[j]+=1;
                break;
            }
        }
        
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("Przedzial [%d, %d): %d punktow.\n",i,i+1,tab[i]);
    }
    
    return 0;
}

