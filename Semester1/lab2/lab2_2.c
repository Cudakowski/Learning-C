#include <stdio.h>

int main(int argc, char const *argv[])
{
    double eps=1e-9;
    double sum=0.0;
    double next=1.0;
    int i=1;
    while (next>eps)
    {
        sum+=next;
        i+=1;
        next=1.0/(i*i);
    }
    printf("Po zsumowaniu %d elementow suma wyniosla: %.2lf",i-1,sum);
    
    return 0;
}
