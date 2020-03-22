#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int validate(int n, string
             arr[]);                                              //function to check whether input is proper and returns error code or valid key


int main(int argc, string argv[])                                               //main function
{
    int ret, key;
    ret = validate(argc, argv);                                                 //collects return value from validate function
    if (ret == 0)
    {
        return 1;                                                               //if invalid command-line input, program ends here
    }
    else
    {
        key = ret;                                                              //valid key is stored here
    }

    string plaintext = get_string("plaintext: ");                               //asks user for the plain text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]) != 0)
        {
            printf("%c", ((((int)plaintext[i] - 96) + key) % 26) + 96);         //encrypts the lower case alphabets according to the key
        }
        else if (isupper(plaintext[i]) != 0)
        {
            printf("%c", ((((int)plaintext[i] - 64) + key) % 26) + 64);         //encrypts the upper case alphabets according to the key
        }
        else
        {
            printf("%c", plaintext[i]);                                         //prints as it is if its not an alphabet
        }
    }
    printf("\n");
}

int validate(int n, string
             arr[])                                               //function to check if command-line input is valid
{
    if (n != 2)                                                                 //returns error if more than one command-line input
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }
    else
    {
        int key = 0, pos = 0;
        for (int i = strlen(arr[1]) - 1; i >= 0; i--)                           //extracts the input from the array one-by-one
        {
            if (isdigit(arr[1][i]) == 0)                                        //checks if the array element is indeed a digit
            {
                printf("Usage: ./caesar key\n");
                return 0;
            }
            else
            {
                key += (arr[1][i] - 48) * pow(10, pos);                         //forms the final key to be returned back
                pos++;
            }
        }
        return key;                                                             //returns the input key
    }
}