/**
 * @file main.c
 * @author Animesh Srivastava (animeshs1798@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#define clr system("clear")
#include "dbFunctions.h"


typedef enum {
    NONE,
    ADD_ENTRY,
    DELETE,
    SEARCH,
    MODIFY,
    DISPLAY_ALL,
    EXIT
} OPTIONS;


int main(){
    char login[10], pass[10], ch;
    FILE* file;

    buildCred();

    clr;
    printf("\n\t\t\t   Welcome to THE DATABASE.");
    printf("\n\t\tPlease enter LoginID and Password to continue .....\n\n\t\t\tLoginID - \t");
    scanf("%s", login);
    printf("\t\t\tPassword - \t");
    scanf("%s", pass);
    fflush(stdin);
    clr;

    /**
     * @brief Credential Verification for the operations access for the database 
     */
    int verify = verifyCreds(login, pass);
    if (!verify){
        printf("\nCredentials don't match... Exiting ..... \n");
        exit(0);
    }
    else{
        printf("\nCredentials Matched!!! ");
    }
    
    int choice = 0;

    /**
     * @brief Menu driven operations for the database
     */

    while(choice != EXIT){
        clr;
        printf("\n*******************************************************************");
        printf("\nWelcome to the Database Menu\nPlease select your choice ..\n");
        printf("\n1. Add an entry.\n2. Remove an entry by ID.\n3. Search an entry by ID.\n");
        printf("4. Modify an entry by ID.\n5. Display all the entries.\n6. Signout and Exit");
        printf("\n*******************************************************************");
        printf("\n\nYour Option -> ");

        scanf("%d", &choice);
        
        switch(choice){
            case ADD_ENTRY :
            {
                entryFormat entry;
                readEntry(&entry);
                file = fopen("mydb.dat", "ab+");
                int fback = append(file, entry);
                if (!fback)
                    printf("\nFailed...\n");
                else
                    printf("\nSuccess...");
                fclose(file);
                break;
            } 
            
            case DELETE :
            {
                int id;
                file = fopen("mydb.dat", "rb+");
                printf("\nEnter Id to be removed - ");
                scanf("%d", &id);
                int fback = delete(file, id);
                if (fback == -1)
                    printf("\nId not found...");
                else
                    printf("\nRemoved successfully....");
                fclose(file);
                remove("mydb.dat");
                rename("temp.dat", "mydb.dat");
                break;
            }   
            
            case SEARCH :
            {
                file = fopen("mydb.dat", "rb");
                int id;
                printf("\nEnter the Id to be searched... ");
                scanf("%d", &id);
                int fback = search(file, id);
                if (fback == -1)
                    printf("\nSearch Failed ...");
                else if (fback == 0)
                    printf("\nRecord with the given id not found ...");
                else {
                    printf("continue? (y) ");
                    while(getchar() != 'y');
                    printf("\nSearch Successfull ....");
                }
                fclose(file);
                break;
            }

            // case ADD_AT_POSITION :
            // {
            //     entryFormat entry;
            //     readEntry(&entry);
            //     int pos;
            //     printf("\nEnter the position for the entry - ");
            //     scanf("%d", &pos);
            //     file = fopen("mydb.dat", "wb+");
            //     int fback = appendAtPosition(file, entry, pos);
            //     if (fback == -1)
            //         printf("\nUnable to append...");
            //     else if (fback == 0)
            //         printf("\nPosition Overflow. Appending at last...");
            //     else
            //         printf("\nAppend successfull at given position ...");
            //     fclose(file);
            //     break;
            // }   

            case MODIFY :
            {
                int id;
                printf("\nEnter the ID to be modified - ");
                scanf("%d", &id);
                file = fopen("mydb.dat", "rb+");
                int fback = modify(file, id);
                if (fback == 0)
                    printf("\nID not found...");
                else   
                    printf("\nModification successful...");
                fclose(file);
                remove("mydb.dat");
                rename("temp.dat", "mydb.dat");
                break;
            }       
            case DISPLAY_ALL :
            {
                file = fopen("mydb.dat", "rb+");
                int fback = displayAll(file);
                while(getchar() != 'c');
                fclose(file);
                break;
            }
            case EXIT :
            {   
                printf("\nExiting now...\n");
                choice = EXIT;
                break;
            }
            default :
            {
                printf("\nPlease select from the given options...\n");
                char c = getchar();
                break;
            }
        }
    }
    return 0;
}