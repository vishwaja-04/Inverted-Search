#include "header.h"

int read_and_validation(int argc, char *argv[], Flist **head)
{
    if(argc < 2)
    {
        printf("------------------------------------------------------------------------------\n");
        printf("ERROR: please provide atleast 1 .txt files\n");
        printf("------------------------------------------------------------------------------\n");
        return FAILURE;
    }
    for(int i=1; i < argc;i++)
    {
        printf("------------------------------------------------------------------------------\n");
       //check argv[i] extn is .txt or not
       char *extn = strrchr(argv[i], '.');
       if(extn !=NULL && strcmp(extn, ".txt") ==0)
       {
          printf("%s is valid txt file\n", argv[i]);
          //check the file is present or not
          FILE *fptr = fopen(argv[i], "r");
          if(fptr!=NULL)
          {
            // check the file is empty or not
            fseek(fptr, 0, SEEK_END);
            if(ftell(fptr))
            {
                if(insert_filename(argv[i],head)== SUCCESS)
                {
                    printf("successful: Inserting filename : %s into file linked list\n ",argv[i]);
                }
                else
                {
                    printf("%s file is not inserted in flist\n",argv[i]);
                }
            }
            else
            {
                 printf("%s file is empty\n",argv[i]);
            }
            fclose(fptr);

          }
          else
          {
            printf("%s file is not present\n",argv[i]);
           
          }
       } 
       else
       {
        printf("%s is not valid .txt file\n", argv[i]);

       }

    }
    printf("------------------------------------------------------------------------------\n");
    return SUCCESS;
}
int insert_filename(char *filename, Flist **head)
{
    //check for duplicate
    Flist *temp = *head;
    while(temp !=NULL)
    {
        if(strcmp(temp->arr,filename)==0)
        {
            printf("%s is already present\n", filename);
            return FAILURE;
        }
        temp=temp->link;
    }
    
    Flist *new = (Flist *)malloc(sizeof(Flist));
    if(new==NULL)
    {
        printf("memory allocation fails\n");
        return FAILURE;
    }
    new->arr=malloc(strlen(filename)+1);
    if(new->arr==NULL)
    {
        printf("memory allocation fails\n");
        free(new);
        return FAILURE;
    }
    strcpy(new->arr, filename);
    new->link = NULL;

    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        Flist *temp = *head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    return SUCCESS;
}