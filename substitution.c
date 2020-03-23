#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//functions to check the validity of the command-line arguements and encipher the plaintext
int validate(int argc, string argv[]);
void encipher(string key, string pt);

//main function
int main(int argc, string argv[])
{
    //checking the validity
    int ret_val = validate(argc, argv);
    if (ret_val == 1)
    {
        return 1;
    }

    //transferring the key and aquiring the plaintext
    string key = argv[1];
    string pt = get_string("plaintext: ");
    printf("ciphertext: ");

    //getting the ciphertext
    encipher(key, pt);
    return 0;
}

//function to check the validity of the key
int validate(int argc, string argv[])
{
    //checks number of arguements are proper or not
    if (argc != 2)
    {
        printf("Usage ./substitution KEY\n");
        return 1;
    }

    //checks if length of the key is proper or not
    if (strlen(argv[1]) != 26)
    {
        printf("KEY must be 26 characters long\n");
        return 1;
    }

    //checks if there isnt any other character than alphabets
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Use only alphabets !\n");
            return 1;
        }
    }

    //checks if there is any repeated characters or not
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


//function to encipher the plaintext
void encipher(string key, string pt)
{
    for (int i = 0; pt[i] != '\0'; i++)
    {
        //checks if its an alphabet or not
        if (isalpha(pt[i]) != 0)
        {
            //if its a lower case alphabet
            if (islower(pt[i]) != 0)
            {
                printf("%c", tolower(key[(int)pt[i] - 97]));
            }

            //if its an upper case alphabet
            if (isupper(pt[i]) != 0)
            {
                printf("%c", toupper(key[(int)pt[i] - 65]));
            }
        }

        //if not an alphabet, prints the character as it is
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
}