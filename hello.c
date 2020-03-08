#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Your Name? : ");      //takes users name
    printf("hello, %s\n", name);                    //says hello to the user
}
