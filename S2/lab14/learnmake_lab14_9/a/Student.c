#include "Student.h"

int cmp_student_by_age(const void *a, const void *b)
{
    const Student *A=a;
    const Student *B=b;
    return(A->age-B->age);
}


void print_student(const void *student)
{
    assert(student != NULL);
    const Student *student_a = student;
    printf("Dane studenta: %s %s, wiek: %u, adres: %s\n", student_a->first_name, student_a->last_name, student_a->age,student_a->email);
}

