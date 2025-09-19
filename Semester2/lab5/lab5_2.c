#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *const ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void decrypt(char *input_string, const char *key);
char *generate_key(const char *key_init);
char *read_line(void);
char *trim(char *string);
void safe_free(void **my_tab);
void encrypt(char *input_string, const char *key);
char *trimN(char *string,int n);


int main()
{
    printf("Podaj klucz: ");
    char *key=read_line();

    //key=trimN(key,10);
    //printf("Terimed key %s\n",key);

    char *gen=generate_key(key);
    printf("gen %s\n",gen);



    printf("Podaj tekst: ");
    char *str=read_line();

    //str=trimN(str,10);
    //printf("Trimedstr %s\n",str);



    encrypt(str,gen);
    printf("Zaszyfrowane: %s\n",str);

    decrypt(str,gen);
    printf("Odszyfrowane: %s\n",str);

    

    safe_free((void **)&str);
    safe_free((void **)&gen);
    safe_free((void **)&key);

    return 0;
}

char *read_line(void)
{
    char character=0;
    int len=1;
    char *str=(char *)malloc(sizeof(char)*1);
    while (character!='\n')
    {
        character=getchar();
        str=(char *)realloc(str,sizeof(char)*len);
        *(str+len-1)=character;
        len++;
    }
        len--;
        *(str+len-1)='\0';
    //printf("wczytano %s\n",str );
    return str;
}

char *trim(char *string)
{
    int count=0;
    while (*(string+count)!='\0')
    {
        count++;
    }
    char *trim=(char *)realloc(string,sizeof(char)*count);
    //printf("trimed\n");
    return trim;
    
}

void safe_free(void **my_tab)
{
    if(*my_tab==NULL)
    {
        //printf("juz zwolniono\n");
        return;
    }
    
    free(*my_tab);
    *my_tab=NULL;
    //printf("zwolniono\n");
    return;
}

char *generate_key(const char *key_init)
{
    int len=strlen(ALPHABET)+1;
    char *generatedKey=malloc(sizeof(char)*len);
    strcpy(generatedKey,ALPHABET);

    int cursor=0;
    //int start=0;
    int j=0;
    char temp;
    

    while (*(key_init+j)!='\0'&&cursor!=len)
    {
        if(isalpha(*(key_init+j)))
        {
            if(isupper(*(key_init+j)))
            {
                for (size_t i = cursor; i < len; i++)
                {
                    //printf("%c == %c\n",*(generatedKey+i),*(key_init+j));
                    if(*(generatedKey+i)==*(key_init+j))
                    {
                        //printf("co\n");
                        for (size_t k = i; k > cursor; k--)
                        {
                            //printf("co%d\n",k);
                            temp=*(generatedKey+k-1);
                            *(generatedKey+k-1)=*(generatedKey+k);
                            *(generatedKey+k)=temp;
                        }
                        cursor++;
                        break;
                    }
                }
            }
            else
            {
                for (size_t i = cursor; i < len; i++)
                {
                    //printf("%c == %c\n",*(generatedKey+i),toupper(*(key_init+j)));
                    if(*(generatedKey+i)==toupper(*(key_init+j)))
                    {
                        //printf("co\n");
                        for (size_t k = i; k > cursor; k--)
                        {
                            //printf("co%d",k);
                            temp=*(generatedKey+k-1);
                            *(generatedKey+k-1)=*(generatedKey+k);
                            *(generatedKey+k)=temp;
                        }
                        cursor++;
                        break;
                    }
                }
            }
        }
        j++;
    }
    return generatedKey;
}

void encrypt(char *input_string, const char *key)
{
    for (; *input_string!='\0'; input_string++)
    {
        if(isalpha(*input_string))
        {
            if(islower(*input_string))
            {
                for (size_t i = 0; i <= strlen(ALPHABET); i++)
                {
                    if (toupper(*input_string)==*(ALPHABET+i))
                    {
                        *input_string=tolower(*(key+i));
                        break;
                    }
                    
                }
            }
            else
            {
                for (size_t i = 0; i <= strlen(ALPHABET); i++)
                {
                    if (*input_string==*(ALPHABET+i))
                    {
                        *input_string=*(key+i);
                        break;
                    }
                    
                }
            }
        }
    }
    
}

void decrypt(char *input_string, const char *key)
{
    for (; *input_string!='\0'; input_string++)
    {
        if(isalpha(*input_string))
        {
            if(islower(*input_string))
            {
                for (size_t i = 0; i <= strlen(ALPHABET); i++)
                {
                    if (toupper(*input_string)==*(key+i))
                    {
                        *input_string=tolower(*(ALPHABET+i));
                        break;
                    }
                    
                }
            }
            else
            {
                for (size_t i = 0; i <= strlen(ALPHABET); i++)
                {
                    if (*input_string==*(key+i))
                    {
                        *input_string=*(ALPHABET+i);
                        break;
                    }
                    
                }
            }
        }
    }
    
}

char *trimN(char *string,int n)
{
    int len=0;
    for (char *temp=string; *(temp)!='\0'; temp++)
    {
        len++;
    }
    if(len<n)
    {
        printf("Trim nieudany! len=%d < n=%d\n",len,n);
        return(string);
    }
    
    
    *(string+n)='\0';
    return(trim(string));
}
