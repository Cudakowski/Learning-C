#include <stdio.h>

float sum(float a, float b);
float sub(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);


int main(int argc, char const *argv[])
{
    float liczba1=0;
    float liczba2=0;
    char znak=0;

    printf ("Wpisz operacje do obliczenia: ");

    scanf("%f",&liczba1);
    scanf("%c",&znak);
    scanf("%f",&liczba2);

    switch (znak)
    {
    case '+':
        printf("Wynik: %f\n",sum(liczba1,liczba2));
        break;

    case '-':
        printf("Wynik: %f\n",sub(liczba1,liczba2));
        break;

    case '*':
        printf("Wynik: %f\n",multiply(liczba1,liczba2));
        break;

    case '/':
    printf("Wynik: %f\n",divide(liczba1,liczba2));
        break;
    
    default:
    printf("Nie rozpoznano znaku działania!\n");
        break;
    }

    return 0;
}

float sum(float a, float b)
{
    return(a+b);
}

float sub(float a, float b)
{
    return(a-b);
}

float multiply(float a, float b)
{
    return(a*b);
}

float divide(float a, float b)
{
    return(a/b);
}
