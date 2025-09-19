#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../my_functions/functions_0d.h"
#include "../my_functions/functions_1d.h"
//#include "../my_functions/functions_1d.c"


#define ROWS 5
#define COLS 10

int main(void)
{
    srand(time(NULL));
    double matrix[ROWS][COLS]={};

    for (int w = 0;w<ROWS ;w++ )
        d_array_set_random( *(matrix+w),*(matrix+w)+COLS , w * 10, (w + 1) * 10);

    for (double(*row)[COLS] = matrix;row<matrix+ROWS ;row++ )
        d_array_print( (const double *)row,(const double *)row+COLS , (const char[]){'w', '=', row - matrix + '0', '\0'});


    return 0;
}
