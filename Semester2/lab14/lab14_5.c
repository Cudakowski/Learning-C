#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define L 3

typedef struct
{
    int age;
} Student;

Student (*get_array(size_t m))[N][L];
int i_rand(int min, int max);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    size_t m=10;

    Student (*array)[N][L]=get_array(m);

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            for (size_t k = 0; k < L; k++)
            {
                printf("Student: m=%u N=%u L=%u   age=%d\n",i,j,k,(*(*(array+i)+j)+k)->age);
            }
            
        }
        
    }
    
    free(array);
    return 0;
}

Student (*get_array(size_t m))[N][L]
{
    Student (*array)[N][L]=malloc(sizeof(Student)*m*N*L);
    for (size_t i = 0; i < m*N*L; i++)
    {
        ((*(*array))+i)->age=i_rand(19, 25);
    }
    return array;
}

int i_rand(int min, int max)
{
    return(min+rand()%(max-min+1));
}
