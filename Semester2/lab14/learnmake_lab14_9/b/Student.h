#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define EMAIL_MAX 64  // Rozmiar tablicy email w strukturze.
#define F_NAME_MAX 64 // Rozmiar tablicy first_name w strukturze.
#define L_NAME_MAX 64 // Rozmiar tablicy last_name w strukturze.

typedef struct
{
    char first_name[F_NAME_MAX];
    char last_name[L_NAME_MAX];
    unsigned short age;
    char email[EMAIL_MAX];
} Student;

void print_student(const void *);

int cmp_student_by_age(const void *a, const void *b);

#endif