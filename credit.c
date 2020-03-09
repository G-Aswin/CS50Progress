#include <stdio.h>
#include <cs50.h>
#include <math.h>

int checksum(long c_no);                            // function to validate Luhn's Algorithm
int no_len(long c_no);                              // function to return number of digits of a number

int main(void)
{
    long c_no = get_long("Number : ");
    if (checksum(c_no) == 1)
    {
        if (no_len(c_no) == 15)                     // check 15 digit numbers for possible validity
        {
            if (c_no / 10000000000000 == 34 || c_no / 10000000000000 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (no_len(c_no) == 16)                // check 16 digit numbers for possible validity
        {
            if (c_no / 100000000000000 >= 51 && c_no / 100000000000000 <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (c_no / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (no_len(c_no) == 13)                // check 13 digit numbers for possible validity
        {
            if (c_no / 1000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int checksum(long c_no)                                  // function to validate Luhn's Algorithm
{
    int s_eve = 0, s_odd = 0, temp = 0;
    while (c_no != 0)
    {
        s_odd += c_no % 10;
        c_no /= 10;
        temp = (c_no % 10) * 2;
        while (temp != 0)
        {
            s_eve += temp % 10;
            temp /= 10;
        }
        c_no /= 10;
    }

    if ((s_odd + s_eve) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int no_len(long c_no)                                     // function to return number of digits of a number
{
    int len = 0;
    while (c_no != 0)
    {
        len++;
        c_no /= 10;
    }
    return len;
}
