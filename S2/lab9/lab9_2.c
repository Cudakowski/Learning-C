#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADDRESS_LENGHT 50

typedef enum tStudent_status {STUDENT=1,GRADUATE,REMOVED=-1} student_status;

typedef struct tStudent
{
    char *first_name;
    char *last_name;
    int age;
    char address[ADDRESS_LENGHT];
    student_status status;
} Student;

typedef union
{
Student student;
int number;
} test_union;

void set_first_name( Student *student,char *first_name);
void set_last_name( Student *student,char *last_name);
void set_age( Student *student,int age);
void set_address( Student *student,char *address);
void set_status( Student *student, student_status status);
Student *initialize_student(char *first_name,char *last_name,int age,char *address, student_status status);
void print_student( Student *student);
Student *copy_of( Student *student);
Student get_older( Student *One, Student *Two);


int main(int argc, char const *argv[])
{
     Student student1={"Pan","Banan",69,"Kosely 69, Karkow",GRADUATE};
     Student *student2=initialize_student("Bieda","Deda",20,"U ciebie w domu",REMOVED);
     Student student3=get_older(&student1,student2);

    print_student(&student1);
    print_student(student2);
    print_student(&student3);

    int nStudentow=3;
     Student studentTab[nStudentow];
    *(studentTab)=student1;
    *(studentTab+1)=*student2;
    *(studentTab+2)=student3;

    printf("\n");
    for (size_t i = 0; i < nStudentow; i++)
    {
        print_student(studentTab+i);
    }


     Student *studentPtrTab[nStudentow];

    for (size_t i = 0; i < nStudentow; i++)
    {
        *(studentPtrTab+i)=copy_of(studentTab+i);
    }
    

    printf("\n");
    for (size_t i = 0; i < nStudentow; i++)
    {
        print_student(*(studentPtrTab+i));
    }

    printf("%d\n",sizeof(student1));

    printf("\n%d\n",sizeof(student1.first_name));
    printf("%d\n",sizeof(student1.last_name));
    printf("%d\n",sizeof(student1.age));
    printf("%d\n",sizeof(student1.address));
    printf("%d\n",sizeof(student1.status));

    printf("\n%d\n",sizeof(student1.status)+sizeof(student1.first_name)+sizeof(student1.last_name)+sizeof(student1.age)+sizeof(student1.address));

    printf("\n%d\n",sizeof(test_union));

    test_union unia;
    unia.student=student1;
    print_student(&unia.student);

    unia.number=69;
    printf("%d\n",unia.number);



    for (size_t i = 0; i < nStudentow; i++)
    {
        free(*(studentPtrTab+i));
    }

    free(student2);
    return 0;
}



void set_first_name( Student *student,char *first_name)
{
    student->first_name=first_name;
}

void set_last_name( Student *student,char *last_name)
{
    student->last_name=last_name;
}

void set_age( Student *student,int age)
{
    student->age=age;
}

void set_address( Student *student,char *address)
{
    strncpy(student->address,address,strlen(address));
}

void set_status( Student *student, student_status status)
{
    student->status=status;
}

 Student *initialize_student(char *first_name,char *last_name,int age,char *address, student_status status)
{
     Student *student=malloc(sizeof( Student));
    set_first_name(student,first_name);
    set_last_name(student,last_name);
    set_age(student,age);
    set_address(student,address);
    set_status(student,status);
}

void print_student( Student *student)
{
    printf("Dane studenta: %s %s, wiek: %d, adres: %s, ",student->first_name,student->last_name,student->age,student->address);

    switch (student->status)
    {
    case REMOVED:
        printf("status: usuniety z listy studentow.\n");
        break;
    case STUDENT:
        printf("status: jest studentem.\n");
        break;
    case GRADUATE:
        printf("status: ukonczyl studia.\n");
        break;
    
    default:
        break;
    }
}

 Student *copy_of( Student *student)
{
     Student *copied=initialize_student(student->first_name,student->last_name,student->age,student->address,student->status);
    return copied;
}

 Student get_older( Student *One, Student *Two)
{
    if(Two->age>One->age)
    {
        return *Two;
    }
    return *One;
}
