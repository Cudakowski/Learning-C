#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int value(char a);
int my_charcmp(char a, char b);
int my_strcmp(const void *a, const void *b);


int main()
{
    char strings[][11] = {"u", "REh4HmPJRS", "One", "one", "@$9325", "two", "THREE", "four", "415", "@#$325", "@#$315", "@#9325", "five", "alpha", "zet", "0zero", "0123", "(text)", "8", "@#$325"};
    int n=sizeof(strings)/sizeof(*strings);
    

    qsort(strings,n,sizeof(*strings),my_strcmp);

    for (size_t i = 0; i < n; i++)
    {
        printf("%s\n",*(strings+i));
    }
    

    return 0;
}


int my_strcmp(const void *a, const void *b)
{
    const char *A=(const char *)a;
    const char *B=(const char *)b;
    int i=0;
    while (1)
    {
        if((*A+i)=='\0')
        {
            if((*B+i)=='\0')
            {
                return 0;
            }
            return 1;
        }
        
        if((*B+i)=='\0')
        {
            return -1;
        }

        if(my_charcmp(*(A+i),*(B+i))!=0)
        {
            return(my_charcmp(*(A+i),*(B+i)));
        }

        i++;
    }
    
}

int my_charcmp(char a, char b)
{
    return(value(a)-value(b));
}

int value(char a)
{
    if (isalpha(a))
    {
        if(islower(a))
        {
            a=toupper(a);
        }
        return(a+'9'-'0'+1-'A');
        
    }
    else if (isdigit(a))
    {
        return(a-'0');
    }
    else
    {
        return(a+'9'-'0'+1+'Z'-'A'+1);
    }
    
    
}
