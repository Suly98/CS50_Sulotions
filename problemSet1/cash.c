#include <cs50.h>
#include <stdio.h>

int calculate_coins(int cents);
int main(void)

{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents <= 0);

    int result = calculate_coins(cents);
    printf("%i\n", result);
}

int calculate_coins(int cents)
{
    int counts = 0;

    while (cents > 0)
    {
        while (cents >= 25)
        {
            cents = cents - 25;
            counts++;
        }
        while (cents >= 10)
        {
            cents = cents - 10;
            counts++;
        }
        while (cents >= 5)
        {
            cents = cents - 5;
            counts++;
        }
        while (cents >= 1)
        {
            cents = cents - 1;
            counts++;
        }
    }
    return counts;
}
