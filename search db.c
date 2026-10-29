#include "header.h"

int search_db(hash_t *ht)
{
    char word[100];
    int index;
    printf("Enter the word to search : \n");
    scanf("%s",word);
    for(int i = 0; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);
    }
    index = word[0] - 'a';
    printf("------------------------------------------------------------------------------\n");
    if(ht[index].link == NULL)
    {
        printf("INFO: %s word not present in database\n",word);
        printf("------------------------------------------------------------------------------\n");
        return FAILURE;
    }

    Mlist *Mtemp = ht[index].link;
    while(Mtemp != NULL)
    {
        if(strcmp(Mtemp->word,word) == 0)
        {
          printf("[%d][%s] %dfiles\n",index,word,Mtemp->filecount);

          Slist *Stemp = Mtemp->sublink;
          while(Stemp != NULL)
          {
              printf(": file : %s : %dtimes\n",Stemp->filename,Stemp->wordcount);
              Stemp = Stemp->link;
          }
          return SUCCESS;
       } 
       Mtemp = Mtemp->link;
    }

    printf("INFO:  %s word is not present in database\n",word);
    printf("------------------------------------------------------------------------------\n");
    return SUCCESS;

}
