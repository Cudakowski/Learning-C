#include <stdio.h>

int main(int argc, char const *argv[])
{
    char litera='0';
    do
    {
        printf("Podaj litere: ");
        scanf("%c",&litera);
    } while ('A'>litera||litera>'Z');

    char k;
    for (char i = litera; i >='A'; i--)
    {
        for (char j = 0; j <litera-i; j++)
        {
            printf(" ");
        }

        for(k ='A'; k<=i;k++)
        {
            printf("%c",k);
        }
        
        k--;

        while (k>'A')
        {
            printf("%c",--k);
        }
        
        printf("\n");
    }

    return 0;
}
