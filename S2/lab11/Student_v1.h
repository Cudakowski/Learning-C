#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define EMAIL_MAX 50 // Rozmiar tablicy email w strukturze.

typedef struct
{
    char *first_name; // Uwaga: wskaźnik!
    char *last_name;  // Uwaga: wskaźnik!
    unsigned short age;
    char email[EMAIL_MAX];
} Student_v1;

void print_student(const Student_v1 *student);

void set_first_name(Student_v1 *student, const char *first_name);

void set_last_name(Student_v1 *student, const char *last_name);

void set_age(Student_v1 *student, unsigned int age);

void set_email(Student_v1 *student, const char *email);

void initialize_student(Student_v1 *student, const char *first_name, const char *last_name, unsigned short age, const char *email);

int students_cmp(const void *a, const void *b);

void free_student(Student_v1 *student);
