#include <cs50.h>
#include <stdio.h>

int get_height(void);                                    //function to read height

int main(void)
{
    int h = get_height();                                //takes height from user
    
    for (int i = 0; i < h; i++)                          //loop to print the pyramid
    {
        for(int j= h - 1 - i; j > 0; j--)                //prints the initial spacing
        {
            printf(" ");
        }

        for(int k = 0; k < i + 1; k++)                   //prints the first pyramid
        {
            printf("#");
        }
        printf("  ");                                    //prints spacing b/w the pyramids
        for(int l = 0; l <= i; l++)                      //prints the second pyramid
        {
            printf("#");
        }   
        printf("\n");
    }   
}

int get_height(void)                                      //defined function to read correct value of height
{
    int n;
    do
    {
        n = get_int("Height : ");
    }
    while (!(n >= 1 && n <= 8));
    return n;
}
