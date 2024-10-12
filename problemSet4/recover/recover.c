#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE \n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("File was not found!\n");
    }

    BYTE buffer[512];

    int count = 0;

    FILE *cardOut = NULL;

    char filename[8] = {0};

    while (fread(buffer, sizeof(BYTE), 512, card) != 0)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (cardOut != NULL)
            {
                fclose(cardOut);
            }

            sprintf(filename, "%03i.jpg", count++); // creating a new file!
            cardOut = fopen(filename, "w");
        }

        if (cardOut != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, cardOut);
        }
    }

    fclose(card);
    fclose(cardOut);

    return 0;
}
