#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct
{
    unsigned char znak;
    size_t size;
    unsigned short tab[];
}big_number;

big_number *rand_big_number(size_t n_min, size_t n_max);
void fprint_big_number(FILE *file, const big_number *big);

int main(int argc, char const *argv[])
{
    if(argc<4)
    {
        printf("Za malo argumentow!\n");
        return EXIT_FAILURE;
    }

    FILE *file=fopen("numbers.txt","w");
    if (! file ) {
        printf ("Nie mozna utworzyc pliku.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    srand(time(NULL));

    size_t count=atoi(argv[1]);
    size_t n_min=atoi(argv[2]);
    size_t n_max=atoi(argv[3]);

    big_number *tab[count];
    for (size_t i = 0; i < count; i++)
    {
        *(tab+i)=rand_big_number(n_min,n_max);
    }

    for (size_t i = 0; i < count; i++)
    {
        fprint_big_number(file,*(tab+i));
    }
    
    for (size_t i = 0; i < count; i++)
    {
        free(*(tab+i));
    }

    fclose(file);
    return 0;
}

big_number *rand_big_number(size_t n_min, size_t n_max)
{
    size_t size=n_min+rand()%(n_max-n_min+1);
    big_number *returned=malloc(sizeof(big_number)+size*sizeof(unsigned short));
    returned->znak=rand()%2;
    returned->size=size;
    *returned->tab=1+rand()%9;
    for (size_t i = 1; i < size; i++)
    {
        *(returned->tab+i)=rand()%10;
    }
    return returned;
}

void fprint_big_number(FILE *file, const big_number *big)
{
    if(big->znak==1)
    {
        fputc('-',file);
    }
    for (size_t i = 0; i < big->size; i++)
    {
        fputc(*(big->tab+i)+'0',file);
    }
    fputc('\n',file);
}
