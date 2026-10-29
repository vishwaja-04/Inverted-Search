#include "header.h"

int save_database(hash_t *ht)
{
    char filename[100];
    printf("enter the filename: \n");
    scanf("%s",filename);
    printf("------------------------------------------------------------------------------\n");
    char *extn = strchr(filename, '.');
    if(extn !=NULL && strcmp(extn, ".txt") ==0)
    {
        printf("%s is valid txt file\n", filename);
        //open file in write mode
        FILE *fptr = fopen(filename, "w");
        if(fptr == NULL)
        {
            printf("File is not opened\n");
            return FAILURE;
        }
        for(int i = 0; i < 27; i++)
        {
        //check whether his index contains any Mlist
            if(ht[i].link == NULL)
            {
                continue;
            }
            Mlist *mtemp = ht[i].link;
            while(mtemp != NULL)
            {
                fprintf(fptr, "[%d] [%s] %dfiles : ",i,mtemp->word,mtemp->filecount);
            
                //Traverse through subnode
                Slist *stemp = mtemp->sublink;
                while(stemp != NULL)
                {
                    fprintf(fptr,"file : %s : %dtimes ",stemp->filename,stemp->wordcount);
                    stemp = stemp->link;
                }
                fprintf(fptr,"\n");

                mtemp = mtemp->link;
            }
    
        }
        fclose(fptr);
        printf("Database successfully saved in %s\n",filename);
        printf("------------------------------------------------------------------------------\n");
        return SUCCESS;
    
    }
    else
    {
        printf("%s is not .txt file\n", filename);
        printf("------------------------------------------------------------------------------\n");
        return FAILURE;
    }

}