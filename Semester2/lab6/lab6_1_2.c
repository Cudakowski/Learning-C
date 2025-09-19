#include <stdio.h>
#include <stdlib.h>

#define MONTHS_IN_YEAR 12

int main()
{
    unsigned short **months_v2;

    const unsigned short sizes[MONTHS_IN_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const char *MONTHS_NAMES[MONTHS_IN_YEAR] = {"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec","Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};
    
    //alokacja
    months_v2=malloc(sizeof(unsigned short *)*MONTHS_IN_YEAR);

    for (size_t i = 0; i < MONTHS_IN_YEAR; i++)
    {
        *(months_v2+i)=malloc(sizeof(unsigned short)*(*(sizes+i)));
    }

    //przypisywanie
    for (size_t i = 0; i < MONTHS_IN_YEAR; i++)
    {
        for (size_t j = 0; j < *(sizes+i); j++)
        {
            *(*(months_v2+i)+j)=j+1;
        }
    }

    //wyswietlanie
    for (size_t i = 0; i < MONTHS_IN_YEAR; i++)
    {
        printf("%11s:",MONTHS_NAMES[i]);
        for (size_t j = 0; j < *(sizes+i); j++)
        {
            printf(" %d",*(*(months_v2+i)+j));
        }
        printf("\n");
    }

    //dealokacja
    for (size_t i = 0; i < MONTHS_IN_YEAR; i++)
    {
        free(*(months_v2+i));
    }

    free(months_v2);
    
    return 0;
}

