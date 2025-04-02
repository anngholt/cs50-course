// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 101;

// Hash table
node *table[N];
//global variable for counting words
unsigned int word_count = 0; 

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //get index for the word
    unsigned int index = hash(word);
    node *ptr = table[index];
    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
        ptr = ptr->next;

    }
    
    return false; //not found
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    int i = 0;
    while(word[i] != '\0')
    { 
        // use prime number to reduce collisions
        hash_value = (hash_value * 31 + tolower(word[i])) % N;
        i++;
    }
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    // Read each word in the file
    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source);
            return false;
        }
        // Add each word to the hash table
        strcpy(new_node->word, word);
        new_node->next = NULL;
        unsigned int index = hash(word);
        new_node->next = table[index];
        table[index] = new_node;
        word_count++; 
    }
    // Close the dictionary file
    fclose(source);
    return true; 
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false

bool unload(void)
{
    // Loop through each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];  // Start at the beginning of the list

        // Traverse the linked list, freeing nodes
        while (ptr != NULL)
        {
            node *temp = ptr;  // Store current node
            ptr = ptr->next;  // Move to next node
            free(temp);  // Free previous node
        }
    }
    return true;  // Memory successfully freed
}