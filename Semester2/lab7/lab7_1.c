#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void printKawalek(const char *format,size_t cursorL,size_t cursorR);
void my_printf(const char *format, ...);


int main(int argc, char const *argv[])
{
    const char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    double pi = 3.14159265358979323846;
    int ten = 10;
    my_printf("");
    my_printf("Bez specyfikatorow\n");
    my_printf("%f", pi);
    my_printf("\t%s", text);
    my_printf("Tekst: %s\n", text);
    my_printf("Tekst: %s\nliczba calkowita: %d, liczba pi: %f, %d * %f = %f\n", text, ten, pi, ten, pi, ten * pi);
    return 0;
}

void my_printf(const char *format, ...)
{

    va_list list;
    va_start(list,format);

    size_t cursorL=0;
    size_t cursorR=0;

    while (*(format+cursorR)!='\0')
    {
        if(*(format+cursorR)=='%')
        {
            if(cursorL!=cursorR)
            {
                printKawalek(format,cursorL,cursorR);
            }


             switch (*(format+cursorR+1))
            {
            case 'd':
                printf("%d",va_arg(list, int));
                break;
            
            case 'f':
                printf("%lf",va_arg(list, double));
                break;

            case 's':
                printf("%s",va_arg(list, char *));
                break;

            default:
                printf("!!ALARM!!");
                break;
            }

            cursorR++;
            cursorL=cursorR+1;
        }
        cursorR++;
    }
    
    if(cursorL!=cursorR)
    {
        printKawalek(format,cursorL,cursorR);
    }

    va_end(list);
   
}

void printKawalek(const char *format,size_t cursorL,size_t cursorR)
{
    char *str=malloc(sizeof(char)*(cursorR-cursorL+1));
    *(str+cursorR-cursorL)='\0';
    strncpy(str,format+cursorL,cursorR-cursorL);
    printf("%s",str);
    free(str);
}
