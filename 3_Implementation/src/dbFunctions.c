/**
 * @file dbFunctions.c
 * @author Animesh Srivastava (animeshs1798@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "dbFunctions.h"

void buildCred(){
    FILE *file = fopen("./cred/creds.dat", "wb+");
    if (file == NULL){
        printf("error");
        exit(0);
    }
    creds cred;
    strcpy(cred.logid, "admin");
    strcpy(cred.password, "12345");
    fwrite(&cred, sizeof(creds), 1, file);
    fclose(file);
    file = NULL;
    return ;
}


int verifyCreds(char login[], char pass[]){
    FILE *file = fopen("./cred/creds.dat", "rb");
    if (file == NULL){
        printf("error");
        exit(0);
    }
    creds cred;
    fread(&cred, sizeof(creds), 1, file);
    int ret;
    if (strcmp(login, cred.logid) == 0 && strcmp(pass, cred.password) == 0)
        ret = 1;
    else
        ret = 0;
    fclose(file);
    file = NULL;
    return ret; 
}

int append(FILE* filename, entryFormat buffer){
    if (filename == NULL)
        return 0;
    fwrite(&buffer, sizeof(entryFormat), 1, filename);
    return 1;
}

void readEntry(entryFormat *entry){
    printf("\nEnter name (String) - ");
    scanf("%s", entry -> name);
    printf("Enter Employee-ID (Numeric) - ");
    scanf("%d", &entry -> id);
    printf("Enter Phone Number (10-digit Numeric)- ");
    scanf("%ld", &entry -> phoneNumber);
    printf("Enter Joining Year (4-digit Numeric) - ");
    scanf("%d", &entry -> joinYear);
    printf("Enter salary (Numeric) - ");
    scanf("%d", &entry -> salary);
}

int delete(FILE* filename, int id){
    entryFormat temp;
    int flag = -1;
    FILE *fp;
    if (filename == NULL)
        return -1;
    fp = fopen("temp.dat", "wb+");
    while(fread(&temp, sizeof(entryFormat), 1, filename) == 1){
        if (temp.id == id)
            flag = 1;
        else 
            fwrite(&temp, sizeof(entryFormat), 1, fp);
    }
    fclose(fp);
    return flag;
}

int search(FILE* filename, int id){
    entryFormat temp;
    if (filename == NULL)
        return -1;
    while(fread(&temp, sizeof(entryFormat), 1, filename) == 1){
        if (temp.id == id){
            display(temp);
            return 1;
        }
    }
    return 0;
}

// int appendAtPosition(FILE* file, entryFormat buffer, int pos){
//     ;
// }

int modify(FILE* filename, int id){
    entryFormat temp;
    FILE *fp;
    fp = fopen("temp.dat", "wb");
    int choice, flag = 0;
    while(fread(&temp, sizeof(entryFormat),1 , filename) == 1){
        if (temp.id == id){
            printf("Current Details : \n");
            display(temp);
            printf("\nEnter the field to be modified .... \n1. ID\n2. Name\n3. Phone Number\n4. Salary\n5. Join Year\n\nChoice - ");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                {
                    printf("Enter the new ID - ");
                    scanf("%d", &temp.id);
                    break;
                }
                case 2:
                {
                    printf("Enter the new name - ");
                    scanf("%s", temp.name);
                    break;
                }
                case 3:
                {
                    printf("Enter the new Phone Number - ");
                    scanf("%ld", &temp.phoneNumber);
                    break;
                }
                case 4:
                {
                    printf("Enter the new salary - ");
                    scanf("%d", &temp.salary);
                    break;
                }
                case 5:
                {
                    printf("Enter the new Join Year - ");
                    scanf("%d", &temp.joinYear);
                    break;
                }
                default:{
                    printf("Wrong Choice... Exiting without changes");
                    break;
                }
            }
            flag = 1;
        }
        fwrite(&temp, sizeof(entryFormat), 1, fp);
    }
    fclose(fp);
    fp = NULL;
    return flag;
}

int displayAll(FILE* filename){
    entryFormat temp;
    int flag = 0;
    while(fread(&temp, sizeof(entryFormat), 1, filename)){
        display(temp);
        printf("\n");
        flag = 1;
    }
        if (!flag)
            printf("Empty file.. Enter 'c' to continue...");
        else    
            printf("Enter 'c' to continue ...");
    return 1;
}

void display(entryFormat temp){
    printf("\nID - %d\n", temp.id);
    printf("Name - %s\n", temp.name);
    printf("Ph. Number - %ld\n", temp.phoneNumber);
    printf("Salary - %d\n", temp.salary);
    printf("Join Year - %d\n", temp.joinYear);
}