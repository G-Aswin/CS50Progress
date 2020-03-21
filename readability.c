#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");                                     //reads the input text from the user
    float L = count_letters(text), S = count_sentences(text) ;              //stores number of letters and sentences respectively
    int W = count_words(text) ;                                             //stores number of words

    L = (L * 100) / W ;                                                     //number of letters for 100 words
    S = (S * 100) / W ;                                                     //number of sentences for 100 words

    float index = ((0.0588 * L) - (0.296 * S) - 15.8)
                  ;                     //calculates the index value according to Coleman-Liau Formulae
    index = roundf(index);                                                  //rounds the index to its nearest whole number

    if (index >= 16)                                                        //else-if ladder to print the grades accordingly
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}


int count_letters(string text)                                              //function to count the number of letters
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}


int count_words(string text)                                                //function to count the number of words
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}


int count_sentences(string text)                                            //function to count the number of sentences
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}