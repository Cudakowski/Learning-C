#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n=0;
    do
    {
        printf("Podaj wysokosc: ");
        scanf("%d",&n);
    } while (n<=0);
    
    for (int i = n; i >0; i--)
    {
        for(int k=0;k<n-i;k++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2*i-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    

    return 0;
}
