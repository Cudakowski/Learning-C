#include <stdio.h>

#include "Student_v1.h"

#define MAX_LINE_LENGTH 100
#define NAME_LENGTH 50

int main(int argc, char const *argv[])
{
    FILE *pFile=fopen("Students.csv","r+");
    if (! pFile ) {
        printf ("Nie mozna utworzyc pliku.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    fpos_t position;
    fgetpos(pFile,&position);

    char Buffer[MAX_LINE_LENGTH];
    int nStudents=0;
    while (!feof(pFile))
    {
        fgets(Buffer,MAX_LINE_LENGTH,pFile);
        nStudents++;
    }
    printf("%d\n",nStudents);

    fsetpos(pFile,&position);

    char tempFirstName[NAME_LENGTH];
    char tempLastName[NAME_LENGTH];
    char tempEmail[NAME_LENGTH];
    unsigned short tempAge;
    Student_v1 studentsTab[nStudents];
    for (size_t i = 0; i < nStudents; i++)
    {
        fscanf(pFile,"%s , %s , %d , %s",tempFirstName,tempLastName,&tempAge,tempEmail);
        initialize_student(studentsTab+i,tempFirstName,tempLastName,tempAge,tempEmail);
    }

    

    qsort(studentsTab,nStudents,sizeof(Student_v1),students_cmp);

    Student_v1 student_to_find = {.age = 23, "bilfooter@tumblr.com", .first_name = "Weider", "Bilfoot"};

    Student_v1 *student_found = bsearch(&student_to_find,studentsTab,nStudents,sizeof(Student_v1),students_cmp);

    print_student(student_found);

    fprintf(pFile,"\nSORTED\n");

    for (size_t i = 0; i < nStudents; i++)
    {
        fprintf(pFile,"%s , %s , %d , %s\n",(studentsTab+i)->first_name,(studentsTab+i)->last_name,(studentsTab+i)->age,(studentsTab+i)->email);
    }
    

    for (size_t i = 0; i < nStudents; i++)
        {
            free_student(studentsTab+i);
        }
    fclose(pFile);
    return 0;
}
