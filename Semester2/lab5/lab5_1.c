#include <stdio.h>
#include <stdlib.h>

char *read_line(void);
char *trim(char *string);
void safe_free(void **my_tab);

int main()
{
    char *str=read_line();

    //printf("A= %s\n",str);

    *(str+4)='\0';
    str=trim(str);

    //printf("A= %s\n",str);
    

    void **ptr=(void **)&str;
    safe_free(ptr);
    safe_free(ptr);

    return 0;
}

char *read_line(void)
{
    char character=0;
    int len=1;
    char *str=(char *)malloc(sizeof(char)*1);
    while (character!='\n')
    {
        character=getchar();
        str=(char *)realloc(str,sizeof(char)*len);
        *(str+len-1)=character;
        len++;
    }
        len--;
        *(str+len-1)='\0';
    //printf("wczytano %s\n",str );
    return str;
}

char *trim(char *string)
{
    int count=0;
    while (*(string+count)!='\0')
    {
        count++;
    }
    char *trim=(char *)realloc(string,sizeof(char)*count);
    //printf("trimed\n");
    return trim;
    
}

void safe_free(void **my_tab)
{
    if(*my_tab==NULL)
    {
        //printf("juz zwolniono\n");
        return;
    }
    
    free(*my_tab);
    *my_tab=NULL;
    //printf("zwolniono\n");
    return;
}
