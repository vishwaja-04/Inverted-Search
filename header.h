#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

//Filelist Node struct
typedef struct node
{
    char *arr;
    struct node *link;
}Flist;

//subnode
typedef struct sub_node{
    int wordcount;
    char *filename;
    struct sub_node *link;
}Slist;
//main node
typedef struct main_node{
    int filecount;
    char *word;
    struct main_node *link;
    Slist *sublink;
}Mlist;
//hash table
typedef struct hash_table{
    int index;
    Mlist *link;
}hash_t;

int read_and_validation(int argc, char *argv[], Flist **head);
int insert_filename(char *filename, Flist **head);
int create_db(Flist *head, hash_t *ht);
int display_db(hash_t *ht);
int search_db(hash_t *ht);
int save_database(hash_t *ht);
int update_database(Flist **head,hash_t *ht);


#endif