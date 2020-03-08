#include <cs50.h>
#include <stdio.h>

int get_height(void);                                    //function to read height

int main(void)
{
    int h = get_height();                                //takes height from user
    
    for (int i = 0; i < h; i++)                          //loop to print the pyramid
    {
        for(int j= h - 1 - i; j > 0; j--)
        {
            printf(" ");
        }

        for(int k = 0; k < i + 1; k++)
        {
            printf("#");
        }   
        printf("\n");
    }   
}

int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height : ");
    }
    while ( ! (n >= 1 && n <= 8));
    return n;
}
