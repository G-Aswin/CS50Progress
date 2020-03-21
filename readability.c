#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters( string text );
int count_words( string text );
int count_sentences( string text );

int main(void)
{
    string text = get_string("Text: ");
    float L = count_letters( text ) , S = count_sentences( text) ;
    int W = count_words( text ) ;

    L = (L * 100) / W ;
    S = (S * 100) / W ;

    float index = ((0.0588 * L) - (0.296 * S) - 15.8) ;
    index = roundf( index );

    if (index >= 16)
    {
        printf ("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf ("Before Grade 1\n");
    }
    else
    {
        printf ("Grade %.0f\n" , index);
    }
}


int count_letters( string text )
{
    int count = 0;
    for(int i = 0 , n = strlen(text); i < n ; i++)
    {
        if(isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}


int count_words( string text )
{
    int count = 0;
    for(int i = 0 , n = strlen(text); i < n ; i++)
    {
        if(text[i]==' ')
        {
            count++;
        }
    }
    return count+1;
}


int count_sentences( string text )
{
    int count = 0;
    for(int i = 0 , n = strlen(text); i < n ; i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}