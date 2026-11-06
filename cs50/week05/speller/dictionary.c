// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"
#include <stdlib.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;
unsigned int word_count = 0;

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
        // 检查当前节点
        if (strcasecmp(word, cursor->word) == 0)
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
    // TODO: Improve this hash function
    int a = toupper(word[0]) - 'A';
    int b = 0;
    if (isalpha(word[1]))
    {
        b = toupper(word[1]) - 'A';
    }
    return (26 * a) + b;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%45s", word) == 1)
    {
        node *p = malloc(sizeof(node));
        if (p == NULL)
        {  
            fclose(file);
            unload();
            return false;
        }
        strcpy(p->word, word);
        unsigned int index = hash(word);
        p->next = table[index];
        table[index] = p;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        // 处理 table[i] 对应的链表
        node *cursor = table[i];
        
        while (cursor != NULL)
        {
            node *temp = cursor->next;
            free(cursor);
            cursor = temp;
        }
        table[i] = NULL;
    }
    word_count = 0;
    return true;
}
