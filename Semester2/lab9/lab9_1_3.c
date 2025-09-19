#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double linear(double x);
double quadratic(double x);

typedef double (*fujkcja)(double);

#define X_MIN 0.0
#define X_MAX 5.0
#define DX 0.1
#define FUN_NR_MAX 8

void print_info(void);
void print_value(double x,fujkcja fun_ptr);


int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        print_info();
        exit(-1);
    }



    fujkcja jump_table[]={
        exp,
        fabs,
        exp2,
        sqrt,
        sin,
        cos,
        ceil,
        linear,
        quadratic
    };

    for (double x = X_MIN; x < X_MAX + 0.1 * DX; x += DX) 
    {
        printf("%10g ", x); // Wypisywanie argumentu x
        for (int i = 1; i < argc; ++i)
        {
            int fun_nr = atoi(*(argv + i)); // Numer funkcji, wybranej przez użytkownika.
            if (fun_nr < 0 || fun_nr > FUN_NR_MAX)
            {
                fprintf(stderr, "BLAD: numer funkcji musi byc dodatni i mniejszy od %d\n", FUN_NR_MAX);
                return 0;
            }
            else
            {
                print_value(x, jump_table[fun_nr]);
            }
        }
        printf("\n");
    }
    return 0;
}

double linear(double x) { return 2 * x + 1.5; }

double quadratic(double x) { return x * x - 2 * x + 1.5; }

void print_value(double x,fujkcja fun_ptr)
{
    printf("%10g ", fun_ptr(x));
}

void print_info(void)
{
    printf("Podaj numer(y) funkcji:\n");
    printf("0 - f(x) = e^x\n");
    printf("1 - f(x) = |x|\n");
    printf("2 - f(x) = 2^x\n");
    printf("3 - f(x) = sqrt(x)\n");
    printf("4 - f(x) = sin(x)\n");
    printf("5 - f(x) = cos(x)\n");
    printf("6 - f(x) = [x]]\n");
    printf("7 - f(x) =  2x + 1.5\n");
    printf("8 - f(x) = x^2 - 2x + 1.5\n");
}

