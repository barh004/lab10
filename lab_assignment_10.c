#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Trie{
    int count;
    struct Trie *children[26]; //an array of 26 TrieNode pointers
};

struct Trie *createNode()
{
    struct Trie* Node = malloc(sizeof(struct Trie));
    Node->count = 0;
    for(int x = 0; x <= 25; x++){
        Node->children[x] = NULL;
    }
    
    return Node;
}

void insert(struct Trie *ppTrie, char *word)
{
    int size = strlen(word);
    struct Trie *tmp = ppTrie;
    
    for(int x = 0; x < size; x ++)
    {
        
        int place = (word[x] - 'a');
        if(tmp->children[place] == NULL)
        {
            tmp->children[place] = createNode();
        }

        tmp = tmp->children[place];        

    }
    tmp->count++;

}

int numberOfOccurances(struct Trie *pTrie, char *word)
{
    struct Trie *tmp = pTrie;
    for(int x = 0; x < strlen(word); x++)
    {
        int place = (word[x] - 'a');

        if(tmp->children[place] == NULL)
        {
            return 0;
        }

        tmp= tmp->children[place];
    
    }
    return tmp->count;
}

struct Trie *deallocateTrie(struct Trie *pTrie)
{


    struct Trie *tmp = pTrie;
    if(tmp == NULL)
    {
        return NULL;
    }
    for(int x = 0; x < 26; x++)
    {
        if(tmp->children[x] != NULL)
        {
            deallocateTrie(tmp->children[x]);
        }
    }
    free(tmp);
    return NULL;


}




int main(void)
{
    struct Trie* trie = createNode();
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure

      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

    for (int i=0;i<5;i++)
      {
        insert(trie, pWords[i]);
      }
      
     for (int i=0;i<5;i++)
     {
        printf("\t%s : %d\n",pWords[i], numberOfOccurances(trie, pWords[i]));
     }
    trie = deallocateTrie(trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}
