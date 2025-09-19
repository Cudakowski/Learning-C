#include <stdio.h>
#include <time.h>
#include "../my_functions/functions_0d.c"

void keksort(int *a, int *b, int *c, int *d);
void ifSwap(int *x, int *y);
void test();


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    const int MIN= -100;
    const int MAX= 49;

    const int MAX_HIST= 15;

    int tab[MAX_HIST]={};

    const int COUNT=1000;
    const int STEP=((MAX-MIN+1)/15);

    int random;

    for (int i = 0; i < COUNT; i++)
    {
        random=i_rand(MIN,MAX);
        tab[(random-MIN)/STEP]+=1;
    }

    for (int i = 0; i < MAX_HIST; i++)
    {
        printf("[%d, %d] = %d\n",MIN+i*STEP,MIN+i*STEP+9,tab[i]);
    }
    
    test();
    

    return 0;
}

void keksort(int *a, int *b, int *c, int *d)
{   
    ifSwap(a,b);
    ifSwap(a,c);
    ifSwap(a,d);
    ifSwap(b,c);
    ifSwap(b,d);
    ifSwap(c,d);
}

void ifSwap(int *x, int *y)
{
    if(*x>*y)
        swap(x,y,sizeof(*x));
}

void test()
{
    int a,b,c,d;
    for (int i = 0; i < 300; i++)
    {
        a=i_rand(1,100);
        b=i_rand(1,100);
        c=i_rand(1,100);
        d=i_rand(1,100);
        keksort(&a,&b,&c,&d);
        if(!(a<=b&&b<=c&&c<=d))
        {
            printf("Blad!\n");
            return;
        }    
    }
    printf("Good!\n");
    return;
}

