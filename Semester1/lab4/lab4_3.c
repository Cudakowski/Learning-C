#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8

void U2(int p){
    char tab[N+1];

    if(!(-128<=p&&p<=127)){
        printf("Liczba %d jest poza zakresem [-128, 127]\n",p);
        return;
    }

    int temp=p;

    if(p<0){
        tab[0]='1';
        temp+=128;
    }
    else{
        tab[0]='0';
    }

    for (int i = N-1; i > 0; i--)
    {
        tab[i]=temp%2+'0';
        temp=temp/2;
    }


    tab[8]='\0';
    printf("%4d = %s\n",p,tab);
}

int main(void)
{
    for(int i= -130;i<131;i++)
        if(i<-125 || i>125 || i%50==0)
            U2(i);
    return 0;
}
