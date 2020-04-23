// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5000;

// Counts the total number of words loaded
unsigned long int countword = 0;

// Hash table
node *table[N];




// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char checkword[strlen(word)];

    strcpy(checkword, word);

    int i = 0;
    while(checkword[i] != '\0')
    {
        if (isupper(checkword[i]) != 0)
        {
            checkword[i] = tolower(checkword[i]);
        }
        i++;
    }

    unsigned int index = hash(checkword);


    if (strcasecmp(table[index]->word, checkword) == 0)
    {
        return true;
    }
    else
    {
        node *temp = table[index]->next;
        while (temp != NULL)
        {
            if (strcasecmp(temp->word, word) == 0)
            {
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}






// Hashes word to a number
unsigned int hash(const char *word)
{
    //djb2 hash function from "http://www.cse.yorku.ca/~oz/hash.html"
    unsigned int hcode = 5381;
    char *hashword = malloc(45);
    strcpy(hashword, word);
    int c;

    while ((c = *hashword++))
    {
        hcode = ((hcode << 5) + hcode) + c; //"hcode * 33 + c"
    }

    return hcode % N;
}





// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //opens the dictionary file
    FILE *file;
    file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary\n");
        fclose(file);
        return false;
    }

    //array to store a word read from the dictionary
    char *currword = malloc(LENGTH * sizeof(char) + 1);

    //to read all the words in the dictionary
    while (fscanf(file, "%s", currword) != EOF)
    {
        //store the word in a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(n->word, currword);
        n->next = NULL;

        //get the hash index for this word
        unsigned int index = hash(n->word);

        if (table[index] == NULL)
        {
            table[index] = n;
            countword++;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
            countword++;
        }
    }
    fclose(file);
    return true;
}




// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return countword;
}





// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int index = 0; index < N; index++)
    {
        while (table[index] != NULL)
        {
            node *temp = table[index];
            table[index] = table[index]->next;
            free(temp);
        }
    }
    return true;
}
