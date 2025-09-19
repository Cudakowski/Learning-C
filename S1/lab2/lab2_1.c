#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i=113; 
    int sum=0;
    long long int iloczyn=1;

    while(i<2000)
    {
        i+=226;
    }
    while (i<=3000)
    {
        printf("%d ",i);
        sum+=i;
        iloczyn*=i;
        i+=226;
    }
    printf("\nSuma = %d, iloczyn = %lld\n",sum,iloczyn);
    
    return 0;
}

