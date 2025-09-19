#include <stdio.h>
#include <stdlib.h>

size_t copy_file(const char *src_file_name, const char *dest_file_name);

int main(int argc, char const *argv[])
{
    if(argc<3)
    {
        printf("Za malo argumentow!\n");
        return EXIT_FAILURE;
    }

    size_t bajty = copy_file(argv[1],argv[2]);

    return 0;
}

size_t copy_file(const char *src_file_name, const char *dest_file_name)
{
    FILE *src_file=fopen(src_file_name,"rb");
    if (! src_file ) {
        printf ("Nie mozna utworzyc pliku zrudlowego.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    char znak='0';

    FILE *dest_file;

    FILE *temp=fopen(dest_file_name,"r");
    if ( temp ) {
        fclose(temp);
        while (!(znak=='Y'||znak=='N'||znak=='y'||znak=='n'))
        {
            printf ("Plik juz istnieje.\nCzy nadpisac? Y/N\n") ;
            znak=getchar();
            while(getchar()!='\n');
        }
    
        if(znak=='Y'||znak=='y')
        {
            dest_file=fopen(dest_file_name,"wb");
        }
        else
        {
            exit (EXIT_SUCCESS) ;
        }
    }
    else
    {
        dest_file=fopen(dest_file_name,"wb");
    }

    size_t count=0;
    size_t tempRead=1;
    char buffer=0;
    while(1)
    {
        tempRead=fread(&buffer,1,1,src_file);
        if(tempRead==0)
        {
            break;
        }
        count+=1;
        fwrite(&buffer,1,1,dest_file);
    }
    fclose(src_file);
    fclose(dest_file);

    return count;
}
