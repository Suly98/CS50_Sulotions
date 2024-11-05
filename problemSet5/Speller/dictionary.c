// Implements a dictionary's functionality
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int count = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int sum = 0;
    for (int j = 0; word[j] != '\0'; j++)
    {
        char lower = tolower((unsigned char) word[j]);
        sum += lower;
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // Open dictionary file
    FILE *source = fopen(dictionary, "r");

    // Check if the file was opened successfully
    if (source == NULL)
    {
        return false;
    }

    char word[LENGTH + 1]; // Buffer to store each word

    // Read each word in the file one at a time
    while (fscanf(source, "%s", word) == 1)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));

        // Check if malloc was successful
        if (n == NULL)
        {
            fclose(source);
            return false;
        }

        // Copy the word into the node
        strcpy(n->word, word);
        n->next = NULL;
        count++;

        // Hash the word to get a hash value
        unsigned int index = hash(word);

        // Insert node into the hash table at same location
        n->next = table[index];
        table[index] = n;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    unsigned int index = 0;

    while (index < N)
    {
        node *cursor = table[index];
        node *temp = cursor;

        while (temp != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
        table[index] = NULL;
        index++;
    }
    return true;
}
