#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char menu();
void clear (void);
void caseA();
void caseB();



int main(int argc, char const *argv[])
{
    //char kek[50];
    char znak=0;

    while (1)
    {
        znak=menu();

        switch (znak)
        {
        case 'A':
            caseA();
            break;

        case 'B':
            caseB();
            break;

        case 'D':
            printf("Na swiecie jest 10 rodzajow ludzi: ci, ktorzy rozumieja system binarny,\ni ci, ktorzy go nie rozumieja.\n");
            while(getchar()!=' ');

            break;

        case 'Q':
            return 0;
            break;
        
        default:
            printf("Nierozpoznana opcja [%c], podaj jeszcze raz!\n",znak);
            break;
        }

        clear();
        system("@cls||clear");
        //fflush(stdin);
    }
    
    return 0;
}

char menu()
{
    printf( "**************************************************\n"
                "Wybierz opcje:\n"
                "--> A: wykonaj mnozenie.\n"
                "--> B: zadaj zagadke.\n"
                "--> D: wyswietl dowcip.\n"
                "--> Q: zakoncz program.\n"
                "**************************************************\n");
        char znak;
        fflush(stdin);
        scanf("%c",&znak);
        fflush(stdin);

        if('a'<=znak&&znak<='z')
            znak=toupper(znak);
        
        system("@cls||clear");
        return znak;
}

void caseA()
{
    printf( "--------------------------------------------------\n"
            "1. ZADANIE\n"
            "Mnozenie int * int. Podaj a i b: ");
    
    clear();
    int a=1,b=1, err=0;
    

    while (1)
    {
        //fflush(stdin);
        err=scanf("%d %d",&a,&b);
        clear();
        //fflush(stdin);
        if(err==2)
            break;
        printf("Podano bledne wartosci. Podaj dwie liczby calkowite, oddzielone bialym znakiem: ");
        //scanf("%s",kek);
    }
    
    printf("%d * %d = %d\n",a,b,a*b);

    printf( "--------------------------------------------------\n\n");

    //clear();
    //fflush(stdin);
    while(getchar()!=' ');
    //fflush(stdin);
    //clear();
}

void caseB()
{
    printf( "--------------------------------------------------\n"
            "2. ZADANIE\n"
            "Jakie miasto jest stolica Polski? Podaj nazwe miasta: ");

    int err=0, up=0;
    char miasto[50];
    char dobrze[]="warszawa";
    char zle[]="krakow";
    

    while (1)
    {
        //fflush(stdin);
        //clear();
        scanf("%s",miasto);
        //clear();
        //fflush(stdin);
        up=strspn(miasto," ");

        for (char *ptr = miasto; ptr < miasto+strlen(miasto); ptr++)
        {
            *ptr=tolower(*ptr);
        }
        

        if(strncmp(dobrze,miasto,8+up)==0)
        {
            printf("Brawo, zgadles!\n");
            break;
        }

        if (strncmp(zle,miasto,6+up)==0)
        {
            printf("Nie, Krakow nie jest stolica Polski!\n");
            break;
        }


        

        printf("Podaj prawidlowa nazwe miasta: ");
        //scanf("%s",kek);
    }
    clear();
    while(getchar()!=' ');

    return;
}


void clear (void)
{
    while ( getchar() != '\n' );
}
