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
}
node;

int word_count=0;// for counting the total number of words
// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
   int hi=hash(word);
   node *cursor=table[hi];

   if(strcasecmp(cursor->word,word)==0)
   {
       return true;
   }
   while(cursor->next!=NULL)
   {
      cursor=cursor->next;
      if(strcasecmp(cursor->word,word)==0)
      {
          return true;
      }

   }
   return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int n = (int) tolower(word[0]) - 97; // for each letter according to ASCII code
    return n;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE  *file=fopen(dictionary,"r");
    char dicWord[LENGTH];
    if(file==NULL)
    {
        return false;
    }



    while(fscanf(file,"%s",dicWord)!=EOF)
    {

        node *new_node=malloc(sizeof(node));

        if(new_node==NULL)
        {
            fclose(file);
            return false;
        }
        strcpy(new_node->word,dicWord);


        int h=hash(dicWord);

        new_node->next=table[h];
        table[h]=new_node;
        word_count++;
        }


    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *cursor;
    node *tmp;
    // freeing linked lists
   for (int i = 0; i < N; i++)
   {
       if(table[i]==NULL)
       {
           continue;
       }

       cursor=table[i];
       tmp=cursor;
        while (cursor->next != NULL)
        {
            cursor=cursor->next;
            free(tmp);
            tmp=cursor;

        }
        free(cursor);
    }
    return true;
}
