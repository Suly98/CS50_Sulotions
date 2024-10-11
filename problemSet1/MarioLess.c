#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;

    do
    {
        height = get_int("What is the height?\n");
    }
    while (height < 1);
    for (int i = 1; i <= height; i++)
    {
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int hash = 0; hash < i; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
