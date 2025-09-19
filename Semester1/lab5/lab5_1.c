#include <stdio.h>
//#include <stdlib.h>

int main(int argc, char const *argv[])
{
    unsigned int x=0;
    printf("podaj liczbe: ");
    scanf("%u",&x);

    int n =(8*sizeof(x))/2;

    unsigned int mask=0;
    mask = (~mask)<<n;

    unsigned int half1=0;
    unsigned int half2=0;

    half1=mask&x;
    half2=(~mask)&x;

    half1=~half1;
    half1=mask&half1;

    printf("%u",half1+half2);
    return 0;
}

