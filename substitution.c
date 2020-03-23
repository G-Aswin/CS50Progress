#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int validate(int argc, string argv[]);
void encipher(string key, string pt);


int main(int argc, string argv[])
{
    int ret_val = validate(argc, argv);
    if (ret_val == 1)
    {
        return 1;
    }

    string key = argv[1];
    string pt = get_string("plaintext: ");
    printf("ciphertext: ");
    encipher(key, pt);
    return 0;
}

int validate(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage ./substitution KEY\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf ("KEY must be 26 characters long\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Use only alphabets !\n");
            return 1;
        }
    }
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        int c = 0;
        for (int j = 0; argv[1][j] != '\0'; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                c++;
            }
        }
        if (c != 1)
        {
            printf("Your KEY has repeated characters!\n");
            return 1;
        }
    }
    return 0;
}

void encipher(string key, string pt)
{
    for (int i = 0; pt[i] != '\0'; i++)
    {
        if (isalpha(pt[i]) != 0)
        {
            if (islower(pt[i]) != 0)
            {
                printf("%c", tolower(key[(int)pt[i]-97]));
            }
            if (isupper(pt[i]) != 0)
            {
                printf("%c", toupper(key[(int)pt[i]-65]));
            }
        }
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
}