// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
// Represents a node in a hash table
unsigned int word_counter = 0;
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table

const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index;
    node *cursor = NULL;
    index = hash(word);
    cursor = table[index];
    while (cursor != NULL)
    {
        if ( strcasecmp(cursor->word , word) == 0 )
        {
            return true ;
        }
        cursor = cursor->next;
    }
    return false ;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    unsigned int index;

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];
    while (fscanf(file , "%s" , buffer) != EOF)
    {
      node *new_node = malloc(sizeof(node));
      if (new_node == NULL)
      {
        fclose(file);
        return false;
      }
      strcpy(new_node->word , buffer);
      index = hash(buffer);
      new_node->next = table[index];
      table[index] = new_node;
      word_counter++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0 ; i<N ; ++i)
    {
      cursor = table[i];
      while (cursor != NULL)
      {
        tmp = cursor->next;
        free (cursor);
        cursor = tmp;
      }
    }
    return true;
}
