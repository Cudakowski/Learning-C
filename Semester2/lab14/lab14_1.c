#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 64
#define EMAIL_MAX 64  // Rozmiar tablicy email w strukturze.
#define F_NAME_MAX 64 // Rozmiar tablicy first_name w strukturze.
#define L_NAME_MAX 64 // Rozmiar tablicy last_name w strukturze.

typedef enum
{
    STUDENT,
    F1_TEAM
} TYPE;

typedef struct
{
    TYPE type;
    union
    {
        struct
        {
            char first_name[F_NAME_MAX];
            char last_name[L_NAME_MAX];
            unsigned short age;
            char email[EMAIL_MAX];
        } student;

        struct
        {
            char name[64];
            unsigned points;
            unsigned championships;
        };
    };
} record;

int main(int argc, char const *argv[])
{
    #ifdef __STDC_LIB_EXT1__
    FILE *pFile;
    fopen_s(pFile,"db.csv","r");
    #else
    FILE *pFile=fopen("db.csv","r");
    #endif
    if (! pFile ) {
        printf ("Nie mozna utworzyc pliku.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    fpos_t position;
    fgetpos(pFile,&position);

    char Buffer[MAX_LINE_LENGTH];
    int count=0;
    while (!feof(pFile))
    {
        fgets(Buffer,MAX_LINE_LENGTH,pFile);
        count++;
    }
    count--;

    printf("%d\n",count);
    fsetpos(pFile,&position);

    record recordTab[count];

    char *temp;
    for (size_t i = 0 ; i < count ; i++)
    {
        fgets(Buffer,MAX_LINE_LENGTH,pFile);
        temp=strtok(Buffer,",");
        (recordTab+i)->type=atoi(temp);
        

        if((recordTab+i)->type==0)
        {
            strcpy((recordTab+i)->student.first_name,strtok(NULL,","));
            strcpy((recordTab+i)->student.last_name,strtok(NULL,","));
            (recordTab+i)->student.age=atoi(strtok(NULL,","));
            strcpy((recordTab+i)->student.email,strtok(NULL,"\n"));
        }
        else
        {
            strcpy((recordTab+i)->name,strtok(NULL,","));
            (recordTab+i)->points=atoi(strtok(NULL,","));
            (recordTab+i)->championships=atoi(strtok(NULL,","));
        }
    }

    for (size_t i = 0 ; i < count ; i++)
    {
        if((recordTab+i)->type==STUDENT)
        {
            printf("Dane studenta: %s %s, wiek: %u, adres: %s\n", (recordTab+i)->student.first_name, (recordTab+i)->student.last_name, (recordTab+i)->student.age,(recordTab+i)->student.email);
        }
    }

    for (size_t i = 0 ; i < count ; i++)
    {
        if((recordTab+i)->type==F1_TEAM)
        {
            printf("Dane fur: %s, punkty: %u, championshipss: %u\n", (recordTab+i)->name, (recordTab+i)->points, (recordTab+i)->championships);
        }
    }



    fclose(pFile);
    return 0;
}
