#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    /*To validate the key --
        -- checking if there is only one CLA*/
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    /*Checking if the key is valid --*/
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        // -- if it is less than 26 chars --
        if (l < 26)
        {
            printf("key must contain 26 characters.\n");
            return 1;
        }
        // -- if it has no alphabetics--
        else if (!isalpha(argv[1][i]))
        {
            printf("key must only contain alphabetic characters\n");
            return 1;
        }
        // -- adding another loop to check if there
        // are repeated characters
        for (int j = strlen(argv[1]); j > i; j--)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    string plainText = get_string("plaintext: ");

    string cipherText[strlen(plainText)];
    printf("ciphertext: ");
    for (int i = 0, l = strlen(plainText); i < l; i++)
    {
        if (islower(plainText[i]))
        {
            char letter = plainText[i];
            int index = letter - 'a';
            char word = argv[1][index];
            printf("%c", tolower(word));
        }
        else if (isupper(plainText[i]))
        {
            char letter = plainText[i];
            char word = argv[1][letter - 'A'];
            printf("%c", toupper(word));
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}
