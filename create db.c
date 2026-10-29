#include "header.h"

int create_db(Flist *f_head, hash_t *ht)
{
    Flist *temp=f_head;

    //Traverse all nodes present in Flist
    while(temp!=NULL)
    {
       printf("------------------------------------------------------------------------------\n");
       FILE *fptr = fopen(temp->arr,"r");
       if(fptr==NULL)
       {
          printf("Error: Unable to open %s\n",temp->arr);
          return FAILURE;
       }
       //printf("------------------------------------------------\n");
       printf("%s opened successfully\n",temp->arr);
       printf("------------------------------------------------------------------------------\n");
       char word[100];

       //Read word by word
       while(fscanf(fptr,"%99s",word)!=EOF)
       {
          int index;
          for(int i = 0; word[i] != '\0'; i++)
         {
            word[i] = tolower(word[i]);
         }
          //checking word start with alphabetical char or not.
          if(isalpha(word[0]))
          {
            index = word[0] - 'a';
          }
          else
          {
            index=  26;
          }
          //printf("Word = %s,index = %d\n",word,index);
          Mlist *mtemp=ht[index].link;
          while(mtemp!=NULL)
          {
            if(strcmp(mtemp->word,word) == 0)
            {
               break;
            }
            mtemp=mtemp->link;
          }
          //word does not exist
          if(mtemp == NULL)
          {
             Mlist *newM = malloc(sizeof(Mlist));
             if(newM == NULL)
             {
               fclose(fptr);
               return FAILURE;
             }
             newM->word = malloc(strlen(word)+1);
             if(newM->word == NULL)
             {
               free(newM);
               fclose(fptr);
               return FAILURE;
             }
             strcpy(newM->word,word);
             newM->filecount = 1;

             //create first sublist node

             Slist *newS = malloc(sizeof(Slist));
             if(newS == NULL)
             {
               fclose(fptr);
               return FAILURE;
             }
             newS->filename = malloc(strlen(temp->arr)+1);
             if(newS->filename == NULL)
             {
               free(newS);
               fclose(fptr);
               return FAILURE;
             }
             strcpy(newS->filename, temp->arr);
             
             newS->wordcount = 1;
             newS->link = NULL;
             newM->sublink = newS;

             //insert newM at beginning of mainnode list(insert at first)
             newM->link = ht[index].link;
             ht[index].link =newM;
          }
         //word is already exists.
          else
          {
              Slist *stemp = mtemp->sublink;
              while(stemp != NULL)
              {
                 //word is present in existing file or not.
                 if(strcmp(stemp->filename, temp->arr) == 0)
                 {
                    break;
                 }
                 stemp = stemp->link;
              }
              if(stemp != NULL)
              {
                 //same file
                 stemp->wordcount++;
              }
              else
              {
                 //create new slist node
                 Slist *newS = malloc(sizeof(Slist));
                 if(newS == NULL)
                 {
                    fclose(fptr);
                    return FAILURE;
                 }
                 newS->filename = malloc(strlen(temp->arr)+1);
                 if(newS->filename == NULL)
                 {
                    free(newS);
                    fclose(fptr);
                    return FAILURE;
                 }
                 strcpy(newS->filename, temp->arr);
                 newS->wordcount = 1;
                 newS->link = NULL;
                 
                 //insert Slist node
                 //newS->link = mtemp->sublink;
                 //mtemp->sublink = newS;
                 newS->link = NULL;

                 if(mtemp->sublink == NULL)
                 {
                     mtemp->sublink = newS;
                 }
                 else
                 {
                     Slist *stemp = mtemp->sublink;

                     while(stemp->link != NULL)
                     {
                           stemp = stemp->link;
                     }

                     stemp->link = newS;
                 }

                 //increase file count
                 mtemp->filecount++;
              }
          }
       }
       fclose(fptr);
       temp=temp->link;
    }
    printf("------------------------------------------------------------------------------\n");
    return SUCCESS;
}

