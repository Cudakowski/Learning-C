#include <stdlib.h>
#include <time.h>
#include "Student.c"
#include "list.c"

int main(int argc, char const *argv[])
{
    FILE *pFile=fopen("stud.bin","rb");
    if (! pFile ) {
        printf ("Nie mozna utworzyc pliku.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    Student *tab=malloc(sizeof(Student));
    size_t allocated=1;
    int n=-1;

    do 
    {
        n++;
        tab=realloc(tab,sizeof(Student)*(n+1));
        allocated=fread(tab+n,sizeof(Student),1,pFile);
        
    }while (allocated);

    for (size_t i = 0; i < n; i++)
    {
        print_student(tab+i);
    }
    
    


    free(tab);
    fclose(pFile);
    return 0;
}

