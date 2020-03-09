#include <stdio.h>
#include <cs50.h>
#include <math.h>

int checksum(long c_no);
int no_len(long c_no);

int main(void)
{
    long c_no = get_long("Number : ");
    if(checksum(c_no)==1)
    {
       // printf("Entered! %i\n", no_len(c_no));
        if(no_len(c_no) == 15)
        {
            if(c_no/10000000000000 == 34 || c_no/10000000000000 == 37)
                printf("AMEX\n");
        }
        else if(no_len(c_no) == 16)
        {
            if(c_no/100000000000000 >= 51 && c_no/100000000000000 <= 55)
                printf("MASTERCARD\n");
            else if(c_no/1000000000000000 == 4)
                printf("VISA\n");
        }
        else if(no_len(c_no) == 13)
        {
            if(c_no / 1000000000000 == 4)
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




int checksum(long c_no)
{
    int s_eve=0, s_odd=0, temp=0;
    while(c_no!=0)
    {
        s_odd += c_no%10;
        c_no /= 10;
        temp = (c_no%10)*2;
        while(temp!=0)
        {
            s_eve+=temp%10;
            temp/=10;
        }
        c_no /= 10;
    }

    if((s_odd+s_eve)%10==0)
        return 1;
    else
        return 0;
}

int no_len(long c_no)
{
    int len=0;
    while(c_no!=0)
    {
        len++;
        c_no/=10;
    }
    return len;
}
