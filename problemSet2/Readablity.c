#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int words(string text);
int letters(string text);
int sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int wordCounts = words(text);
    int letterCount = letters(text);
    int sentencesCount = sentences(text);

    printf("word = %i\n", wordCounts);
    printf("letters = %i\n", letterCount);
    printf("sentences = %i\n", sentencesCount);

    float L = 100.0 * letterCount / wordCounts;
    float S = 100.0 * sentencesCount / wordCounts;

    float grade = 0.0588 * L - 0.296 * S - 15.8;

    int rounding = round(grade);

    if (rounding < 1)
    {
        // printf("Before Grade 1\n");
    }

    else if (rounding >= 16)
    {
        // printf("Grade 16+\n");
    }
    else
    {
        // printf("Grade %i\n", rounding);
    }
}

int words(string text)
{
    int length = strlen(text);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    count += 1;

    return count;
}

int letters(string text)
{
    int length = strlen(text);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        count++;
        if (ispunct(text[i]) || text[i] == ' ')
        {
            count--;
        }
    }
    return count;
}

int sentences(string text)
{
    int count = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            count++;
        }
    }
    return count;
}
