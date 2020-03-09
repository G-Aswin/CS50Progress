#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int n_coins=0, cents=0;
    
    float change;
    do
    {
        change = get_float("Change owed : ");
    }
    while(change<0);
    cents = round(change * 100);
    if(cents!=0)
    {
        while(cents>=25)
        {
            cents-=25;
            n_coins++;
        }
        while(cents>=10)
        {
            cents-=10;
            n_coins++;
        }
        while(cents>=5)
        {
            cents-=5;
            n_coins++;
        }
        while(cents>=1)
        {
            cents-=1;
            n_coins++;
        }
    }
    printf("%i\n", n_coins);
}
