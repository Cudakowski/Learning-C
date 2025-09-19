#include "Student_v1.h"

void print_student(const Student_v1 *student)
{
    assert(student != NULL);
    printf("Dane studenta: %s %s, wiek: %u, adres: %s\n", student->first_name, student->last_name, student->age, student->email);
}

void set_first_name(Student_v1 *student, const char *first_name)
{
    assert(first_name != NULL && student != NULL);

    student->first_name = malloc(strlen(first_name) + 1); // Uwaga: dynamiczna alokacja.
    if (student->first_name == NULL)
        return;

    strcpy(student->first_name, first_name);
}

void set_last_name(Student_v1 *student, const char *last_name)
{
    assert(last_name != NULL && student != NULL);

    student->last_name = malloc(strlen(last_name) + 1); // Uwaga: dynamiczna alokacja.
    if (student->last_name == NULL)
        return;

    strcpy(student->last_name, last_name);
}

void set_age(Student_v1 *student, unsigned int age)
{
    assert(student != NULL && age < 100);
    student->age = age;
}

void set_email(Student_v1 *student, const char *email)
{
    assert(email != NULL && student != NULL);
    strncpy(student->email, email, EMAIL_MAX); // Żeby nie wyjść poza tablicę.
    *(student->email + EMAIL_MAX - 1) = '\0';  // Znak końca łańcucha będzie konieczny, jeśli kopiowany łańcuch był za długi.
}

void initialize_student(Student_v1 *student, const char *first_name, const char *last_name, unsigned short age, const char *email)
{
    set_first_name(student, first_name);
    set_last_name(student, last_name);
    set_age(student, age);
    set_email(student, email);
}

int students_cmp(const void *a, const void *b)
{
    const Student_v1 *st1 = a;
    const Student_v1 *st2 = b;
    int to_return = 0;
    if ((to_return = strcmp(st1->last_name, st2->last_name)))
        return to_return; // Alfabetycznie po nazwisku.
    if ((to_return = strcmp(st1->first_name, st2->first_name)))
        return to_return; // Jeśli nazwiska te same: alfabetycznie po imieniu, itd.
    if (st1->age < st2->age)
        return -1;
    if (st1->age > st2->age)
        return 1;
    return strcmp(st1->email, st2->email); // Porównanie po adresie e-mail. Jeśli identyczne: będzie 0.
}

void free_student(Student_v1 *student)
{
    assert(student != NULL);
    free(student->first_name); // Zwolnienie pamięci po dynamicznie zaalokowanym imieniu
    free(student->last_name);  // i nazwisku.
    student->first_name = NULL;
    student->last_name = NULL;
}
