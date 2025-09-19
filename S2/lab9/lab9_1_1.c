#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double zero(double x);
double linear(double x);
double quadratic(double x);

#define X_MIN 0.0
#define X_MAX 5.0
#define DX 0.1
#define FUN_NR_MAX 8

void print_info(void);
void print_value(double x,double (*fun_ptr)(double));
double (*choose_function(int fun_nr))(double);

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        print_info();
        exit(-1);
    }

    for (double x = X_MIN; x < X_MAX + 0.1 * DX; x += DX) 
    {
        printf("%10g ", x); // Wypisywanie argumentu x
        for (int i = 1; i < argc; ++i)
        {
            int fun_nr = atoi(*(argv + i)); // Numer funkcji, wybranej przez użytkownika.
            print_value(x, choose_function(fun_nr));
        }
        printf("\n");
    }
    return 0;
}

double linear(double x) { return 2 * x + 1.5; }

double quadratic(double x) { return x * x - 2 * x + 1.5; }

double zero(double x) { return 0; }

void print_value(double x,double (*fun_ptr)(double))
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

double (*choose_function(int fun_nr))(double)
{
    if (fun_nr < 0 || fun_nr > FUN_NR_MAX)
    {
        fprintf(stderr, "BLAD: numer funkcji musi byc dodatni i mniejszy od %d\n", FUN_NR_MAX);
        return zero;
    }

    switch (fun_nr)
    {
    case 0:
        return exp;
        break;
    case 1:
        return fabs;
        break;
    case 2:
        return exp2;
        break;
    case 3:
        return sqrt;
        break;
    case 4:
        return sin;
        break;
    case 5:
        return cos;
        break;
    case 6:
        return ceil;
        break;
    case 7:
        return linear;
        break;
    case 8:
        return quadratic;
        break;
    }
}
