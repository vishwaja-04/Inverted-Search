#include "header.h"

int update_database(Flist **head,hash_t *ht)
{
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Check extension
    char *extn = strchr(filename, '.');
    printf("------------------------------------------------------------------------------\n");
    if(extn == NULL || strcmp(extn, ".txt") != 0)
    {
        printf("%s is not a .txt file\n", filename);
        return FAILURE;
    }

    printf("%s is a valid txt file\n", filename);

    // Check file exists
    FILE *fptr = fopen(filename, "r");

    if(fptr == NULL)
    {
        printf("%s file is not present\n", filename);
        return FAILURE;
    }

    // Check file is empty
    fseek(fptr, 0, SEEK_END);

    if(ftell(fptr) == 0)
    {
        printf("%s file is empty\n", filename);
        fclose(fptr);
        return FAILURE;
    }

    fclose(fptr);

    // Check duplicate and insert at last
    if(insert_filename(filename, head) == SUCCESS)
    {
        printf("%s file successfully added to Flist\n", filename);
    }
    else
    {
        printf("%s file is already present / not inserted\n", filename);
        return FAILURE;
    }

    Flist *temp = *head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    // 4. Create database only for the new file
    if(create_db(temp, ht) == SUCCESS)
    {
        printf("Database successfully updated with %s\n", filename);
        return SUCCESS;
    }

    printf("Database update failed\n");
    printf("------------------------------------------------------------------------------\n");
    return FAILURE;

}
