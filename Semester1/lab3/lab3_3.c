#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInt(int min, int max)
{
    return(min+rand()%(max-min+1));
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int N=50;
    char tab1[N+1]={};
    char tab2[N+1]={};
    char result[N+2]={};

    for (int i = 1; i < N; i++)
    {
        tab1[i]=randomInt('0','9');
        tab2[i]=randomInt('0','9');
    }
    tab1[0]=randomInt('1','9');
    tab2[0]=randomInt('1','9');
    tab1[N]='\0';
    tab2[N]='\0';

    printf("  %s\n",tab1);
    printf("+ %s\n",tab2);
    
    for (int i = 0; i < N+2; i++)
    {
        printf("-");
    }
    
    char temp=0;
    char sum=0;

    for (int i = N-1; i >=0; i--)
    {
        sum=(tab1[i]-'0')+(tab2[i]-'0')+temp;
        temp=sum/10;
        result[i+1]=sum%10+'0';
    }
    if(temp){
        result[0]=temp+'0';
    }
    else{
        result[0]=' ';
    }
    result[N+1]='\0';
    printf("\n %s\n",result);
    


    return 0;
}

