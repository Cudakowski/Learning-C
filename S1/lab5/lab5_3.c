#include <stdio.h>

long long int silnia(int k);

int main(int argc, char const *argv[])
{
    printf("Podaj liczbe calkowita: ");
    int k=0;
    scanf("%d",&k);
    printf("Wynik: %lld\n",silnia(k));
    return 0;
}

long long int silnia(int k)
{
    static int depth=1;
    printf("%d\n",depth);
    
    if (k==1||k==0)
    {
        return 1;
    }
    else
    {
        depth++;
        return (silnia(k-1)*k);
    }
}
