#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define EMAIL_MAX 50 // Rozmiar tablicy email w strukturze.
#define F_NAME_MAX 50 // Rozmiar tablicy first_name w strukturze.
#define L_NAME_MAX 50 // Rozmiar tablicy last_name w strukturze.

typedef struct
{
char first_name[F_NAME_MAX]; // Uwaga: tablica!
char last_name[L_NAME_MAX]; // Uwaga: tablica!
unsigned short age;
size_t email_max;
char email[]; // Uwaga: tablica elastyczna!
} Student_v3;


void print_student(const Student_v3 *student)
{
    assert(student != NULL);
    printf("Dane studenta: %s %s, wiek: %u, adres: %s\n", student->first_name, student->last_name, student->age, student->email);
}

int main()
{
    FILE *pFile=fopen("newnewStudents.bin","wb+");
    if (! pFile ) {
        printf ("Nie mozna utworzyc pliku.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    size_t size=20;

    Student_v3 *typek=malloc(sizeof(Student_v3)+size*sizeof(char));
    typek->age=26;
    typek->email_max=size;
    strcpy(typek->email,"fwheal0@wisc.edu");
    strcpy(typek->first_name,"Felic");
    strcpy(typek->last_name,"Wheal");

    fpos_t position;
    fgetpos(pFile,&position);


	print_student(typek);
    int nStudents=1;


    fwrite(typek,sizeof(Student_v3)+size*sizeof(char),nStudents,pFile);

	
    fsetpos(pFile,&position);


    Student_v3 *Wstudent=malloc(sizeof(Student_v3));

	fread(Wstudent,sizeof(Student_v3),nStudents,pFile);

    fsetpos(pFile,&position);
    Wstudent=realloc(Wstudent,sizeof(Student_v3)+Wstudent->email_max);

	fread(Wstudent,sizeof(Student_v3)+Wstudent->email_max,nStudents,pFile);

    
	print_student(Wstudent);


    free(typek);
    free(Wstudent);
    fclose(pFile);
    return 0;
}
