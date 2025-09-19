#include <stdlib.h>
#include <time.h>
#include "Student.h"
#include "list.h"

const char *ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *EMAIL_END="@student.agh.edu.pl";

typedef enum { LOWER, UPPER } LETTER_CASE;

void rand_name(char *array, size_t max_len);
int i_rand(int min, int max);
char rand_letter(LETTER_CASE letter_case);
void rand_email(char *array, size_t max_len);
Student *rand_student(void);
void remove_all_students(SortedList *list);

int main(int argc, char const *argv[])
{
    if(argc<2)
    {
        printf("Za malo argumentow!\n");
        return -1;
    }

    srand(time(NULL));

    int n = atoi(argv[1]);

    FILE *pFile=fopen(argv[2],"wb");
    if (! pFile ) {
        printf ("Nie mozna utworzyc pliku.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    SortedList pList;
    initialize_list(&pList);

    for (size_t i = 0; i < n; i++)
    {
        add(&pList,rand_student(),cmp_student_by_age);
    }

    print_list(&pList,print_student);


    Node *current = pList.head;
    for (size_t i = 0; i < n; i++)
    {
        fwrite(current->data,sizeof(Student),1,pFile);
        current = current->next;
    }


    remove_all_students(&pList);
    fclose(pFile);

    return 0;
}

char rand_letter(LETTER_CASE letter_case)
{
    switch (letter_case)
    {
    case LOWER:
        return(i_rand('a','z'));
        break;
    
    case UPPER:
        return(i_rand('A','Z'));
        break;
    
    default:
        return('?');
        break;
    }
}

int i_rand(int min, int max)
{
    return(min+rand()%(max-min+1));
}

void rand_name(char *array, size_t max_len)
{
    *array=rand_letter(UPPER);
    size_t n=i_rand(1,max_len-1);
    for (size_t i = 1; i < n; i++)
    {
        *(array+i)=rand_letter(LOWER);
    }
    *(array+n)='\0';
    return;
}

void rand_email(char *array, size_t max_len)
{
    size_t i = 0;
    size_t n=i_rand(1,max_len-20);
    for (; i < n; i++)
    {
        *(array+i)=rand_letter(UPPER);
    }
    strcpy(array+i,EMAIL_END);
    return;
}

Student *rand_student(void)
{
    Student *nowy=malloc(sizeof(Student));
    nowy->age=i_rand(18,30);
    rand_email(nowy->email,EMAIL_MAX);
    rand_name(nowy->first_name,F_NAME_MAX);
    rand_name(nowy->last_name,L_NAME_MAX);
    return nowy;
}


void remove_all_students(SortedList *list)
{
    Node *current = list->head; // Zmienna pomocnicza: aktualny węzeł.
    while (current != NULL)
    {
        Node *to_remove = current; // Zapamiętujemy wskaźnik, żeby zwolnić po nim pamięć, ale najpierw:
        current = current->next;   // przesuwamy wskaźnik na następny węzeł.
        free(to_remove->data);
        free(to_remove);           // Dopiero teraz można zwolnić.
    }
    list->head = NULL; // Lista stała się pusta: nie ma początkowego węzła.
}
