#include <stdio.h>
#include <stdlib.h>

size_t get_size(FILE *file);
int read_one_int(FILE *file);

int main()
{
    FILE *file=fopen("secret.bin","rb+");
    if (! file ) {
        printf ("Nie mozna utworzyc pliku zrudlowego.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    int offset=read_one_int(file);
    do
    {
        fseek(file,offset*sizeof(int),SEEK_CUR);
        offset=read_one_int(file);
    }while(offset%2==0);

    for (size_t i = 0; i < offset*sizeof(int); i+=sizeof(int))
    {
        printf("%c",read_one_int(file));
    }
    printf("\n");
    
    fclose(file);
    return 0;
}

size_t get_size(FILE *file)
{
    fpos_t position;
    fgetpos(file,&position);
    fseek(file,0,SEEK_END);
    size_t size=ftell(file);
    fsetpos(file,&position);
    return size;
}

int read_one_int(FILE *file)
{
    int intBuffer=0;
    int zero=0;
    fread(&intBuffer,sizeof(int),1,file);
    fseek(file,-4,SEEK_CUR);
    fwrite(&zero,sizeof(int),1,file);
    return intBuffer;
}
