#include"header.h"

int main(int argc, char *argv[])
{
    Flist *head = NULL;
    hash_t ht[27];

    //initialize the hash table
    for(int i = 0; i < 27; i++)
    {
       ht[i].index = i;
       ht[i].link = NULL;
    }

    if(read_and_validation(argc,argv,&head) == SUCCESS)
    {
        printf("read and validation is successful\n");
        printf("------------------------------------------------------------------------------\n");
        char choice;
        int option;
        do
        {
            printf("-------------------------------select your choice-----------------------------\n");
            printf("1.Create Database\n");
            printf("2.Display Database\n");
            printf("3.Search Database\n");
            printf("4.Update Database\n");
            printf("5.Save Database\n");
            printf("6.Exit\n");

            printf("Enter your choice: ");
            scanf("%d",&option);

            switch(option)
            {
                case 1:{
                    //create db
                    if(create_db(head,ht) == SUCCESS)
                    {
                        printf("Database created successfully\n");
                        printf("------------------------------------------------------------------------------\n");
                    }
                    else
                    {
                        printf("Database creation failed\n");
                        printf("------------------------------------------------------------------------------\n");
                    }
                    break;
                }
                case 2:{
                    //display db
                    if(display_db(ht) == SUCCESS)
                    {
                        printf("Database displayed successfully\n");
                        printf("------------------------------------------------------------------------------\n");
                    }
                    else
                    {
                        printf("Failed to display database\n");
                        printf("------------------------------------------------------------------------------\n");
                    }
                    break;
                }
                case 3:
                    //search db
                    search_db(ht);
                    break;
                case 4:{
                    //update db
                    if(update_database(&head,ht) == SUCCESS)
                    {
                        printf("Database updated successfully\n");
                        printf("------------------------------------------------------------------------------\n");
                    }
                    else
                    {
                        printf("Failed to update database\n");
                        printf("------------------------------------------------------------------------------\n");
                    }
                    break;
                }
                case 5:{
                    //save db
                    if(save_database(ht) == SUCCESS)
                    {
                        printf("Database saved successfully\n");
                        printf("------------------------------------------------------------------------------\n");
                    }
                    else
                    {
                        printf("Database saving failed\n");
                        printf("------------------------------------------------------------------------------\n");
                    }
                    break;
                }
                case 6:
                    //Exit
                    return 0;
                default:
                    printf("Invalid Choice\n");            
            }
            printf("\nDo you want to continue?\n");
            printf("enter Y/y to continue or N/n to discontinue : ");
            scanf(" %c",&choice);
        }while(choice == 'Y' || choice == 'y');
    }
    else
    {
        printf("ERROR: read and validation is not completed\n");
        printf("------------------------------------------------------------------------------\n");
    }


    return 0;
}