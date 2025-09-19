#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void join_snake_case(char **first,const char *last,size_t *size);
void camelCase(char **first,size_t *size);


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
    
    camelCase(&str,&size);
    printf("%s\n",str);

    free(str);

    return 0;
}

void join_snake_case(char **first,const char *last,size_t *size)
{
    *size+=strlen(last)+1;
    *first=realloc(*first,sizeof(char)*(*size));
    strcat(*first,"_");
    strcat(*first,last);
    return;
}

void camelCase(char **first,size_t *size)
{
    char *ptr= strtok(*first,"_");
    ptr= strtok(NULL,"_");
    unsigned short count=0;
    while (ptr !=NULL)
    {
        count+=1;
        *ptr+='A'-'a';
        strcat(*first,ptr);
        ptr= strtok(NULL,"_");
    }
    *size-=count;
    *first=realloc(*first,*size);
    //printf("%d\n",count);
}
