#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void join_snake_case(char **first,const char *last,size_t *size);

int main(int argc, char const *argv[])
{
    if(argc<2)
    {
        printf("Za malo argumentow!\n");
        return -1;
    }
    size_t size=strlen(argv[1])+1;
    char *str=malloc(sizeof(char)*size);
    strcpy(str,argv[1]);
    
    for (size_t i = 2; i < argc; i++)
    {
        //printf("%s\n",str);
        join_snake_case(&str,argv[i],&size);
    }
    printf("%s\n",str);
    
    free(str);

    return 0;
}

void join_snake_case(char **first,const char *last,size_t *size)
{
    *size+=strlen(last)+1;
    *first=realloc(*first,sizeof(char)*((*size)+1));
    strcat(*first,"_");
    strcat(*first,last);
    return;
}
