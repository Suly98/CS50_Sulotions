#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int result(string word);

int main(void)
{

    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");

    int result1 = result(player1);
    int result2 = result(player2);

    if (result1 > result2)
    {
        printf("Player 1 wins!\n");
    }
    else if (result1 < result2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int result(string word)
{
    int num[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int index = 0;
    int sum = 0;
    int counter = 0;

    for (int i = 0, l = strlen(word); i < l; i++)
    {

        word[i] = toupper(word[i]); // CODE

        // if Capital case:
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            index = word[i] - 'A';
            sum += num[index];
        }
    }
    return sum;
}
