#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int n_coins = 0, cents = 0;
    
    float change;
    do                                           // to reject negative inputs
    {
        change = get_float("Change owed : ");
    }
    while (change < 0);
    cents = round(change * 100);                 // to round off ro nearest penny
    if (cents != 0)
    {
        while (cents >= 25)                      // counts number of quarters
        {
            cents -= 25;
            n_coins++;
        }
        while (cents >= 10)                      // counts number of dimes
        {
            cents -= 10;
            n_coins++;
        }
        while (cents >= 5)                       // counts number of nickels
        {
            cents -= 5;
            n_coins++;
        }
        while (cents >= 1)                       // counts number of pennies
        {
            cents -= 1;
            n_coins++;
        }
    }
    printf("%i\n", n_coins);                     // prints final number of coins 
}
