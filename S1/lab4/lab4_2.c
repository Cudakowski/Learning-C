#include <stdio.h>

unsigned int count1(unsigned int p);

int main(int argc, char const *argv[])
{
    printf("Liczba 2327 ma %u jedynek\n",count1(2327));
    return 0;
}

unsigned int count1(unsigned int p)
{
    unsigned int count=0;
    do 
    {
        if(p>p<<1){
            count+=1;
        }
        p=p<<1;
    }while (p!=0);
    return count;
}
