#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int validate (int n, string arr[]);


int main (int argc, string argv[])
{
    int ret,key;
    ret = validate(argc, argv);
    if(ret == 0)
    {
        return 1;
    }
    else
    {
        key = ret;
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]) != 0)
        {
            printf ("%c", ((((int)plaintext[i] - 96)+ key) % 26) + 96);
        }
        else if (isupper(plaintext[i]) != 0)
        {
            printf ("%c", ((((int)plaintext[i] - 64)+ key) % 26) + 64);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

int validate (int n, string arr[])
{
    if(n != 2)
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }
    else
    {
        int key=0, pos=0;
        for(int i = strlen(arr[1]) - 1; i >= 0; i--)
        {
            if(isdigit(arr[1][i]) == 0)
            {
                printf ("Usage: ./caesar key\n");
                return 0;
            }
            else
            {
                key += (arr[1][i] - 48)*pow(10, pos);
                pos++;
            }
        }
        return key;
    }
}