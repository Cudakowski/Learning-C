#include <stdio.h>
#include <ctype.h>

void funkcja(char * lancuch);

int main(int argc, char const *argv[])
{
    char lancuch[]="To jest TESTOWY lancuch";
    printf("PRZED: %s\n",lancuch);

    funkcja(lancuch);

    printf("PO:    %s\n",lancuch);

    return 0;
}

void funkcja(char * lancuch)
{
    
    char *ptr=lancuch;

    while (*ptr!='\0')
    {
        if(isupper(*ptr))
        {
            *ptr=tolower(*ptr);
        }
        else if(islower(*ptr))
        {
            *ptr=toupper(*ptr);
        }
        else if (isspace(*ptr))
        {
            *ptr='_';
        }
        ptr++;
        
    }

}
