#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if(argc==1)
    {
        printf("Podaj parametr!\n");
        return 1;
    }

    printf("%s =",argv[1]);

    char *ptr=strtok(argv[1]," ");

    double liczba1;
    double liczba2;
    char znak;

    liczba1=atof(ptr);

    ptr=strtok(NULL," ");

    znak=*ptr;

    ptr=strtok(NULL," ");

    liczba2=atof(ptr);


    switch (znak)
    {
    case '+':
        printf(" %lf\n",liczba1+liczba2);
        break;

    case '-':
        printf(" %lf\n",liczba1-liczba2);
        break;

    case '*':
        printf(" %lf\n",liczba1*liczba2);
        break;

    case '/':
    printf(" %lf\n",liczba1/liczba2);
        break;
    
    default:
    printf("Nie rozpoznano znaku działania!\n");
        break;
    }


    return 0;
}

