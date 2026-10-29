#include "header.h"

int display_db(hash_t *ht)
{
    printf("\n---------------------------------DATABASE-------------------------------------\n");
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
            printf("\n[%d] [%s] %dfiles : ",i,mtemp->word,mtemp->filecount);
            
            //Traverse through subnode
            Slist *stemp = mtemp->sublink;
            while(stemp != NULL)
            {
                printf("file : %s : %dtimes ",stemp->filename,stemp->wordcount);
                stemp = stemp->link;
            }
            mtemp = mtemp->link;
      
        }
        //printf("\n");
    }
    printf("\n------------------------------------------------------------------------------\n");
    return SUCCESS;
}