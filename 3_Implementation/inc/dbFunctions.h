/**
 * @file dbFucntions.h
 * @author Animesh Srivastava (animeshs1798@gmail.com)
 * @brief Database Applications with 5 Operations
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __DB_FUNCTIONS_H__
#define __DB_FUNCTIONS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
    int id;
    long int phoneNumber;
    int salary;
    int joinYear;
    char name[20];
} entryFormat;

typedef struct{
    char logid[10];
    char password[10];
} creds;

void buildCred();

// char *path = "mydb.dat"; // location of the database file.

/**
 * @brief verify credentials to access database 
 * 
 * @param login login id for the database
 * @param pass password for the database
 * @return int : 1 for success / 0 for failure 
 */
int verifyCreds(char login[], char pass[]);

/**
 * @brief  read details from the user
 * @param entry structure of the details
 */
void readEntry(entryFormat *entry);

/**
 * @brief Adds entry details to the current database
 * 
 * @param filename - database name 
 * @param buffer - information to be added 
 */

int append(FILE* filename, entryFormat buffer);

/**
 * @brief remove an entry from the current database
 * 
 * @param filename database name
 * @param id id of the entry to be removed 
 */
int delete(FILE *filename, int id);

/**
 * @brief search an entry in the database
 * 
 * @param filename database name    
 * @param id id of the entry to be searched
 */
int search(FILE *filename, int id);

// /**
//  * @brief add information at a certain position 
//  * 
//  * @param filename database name    
//  * @param buffer information to added   
//  * @param pos position at which information has to be added
//  */
// int appendAtPosition(FILE *filename, entryFormat buffer, int pos);

/**
 * @brief modify a ceratin entry
 * 
 * @param filename database name
 * @param id id whose information has to be modified
 */
int modify(FILE* filename, int id);

/**
 * @brief display all the entries in the database
 * 
 * @param filename name of the database
 */
int displayAll(FILE* filename);

/**
 * @brief display one entry
 */
void display(entryFormat temp);

#endif /* #define __DB_FUNCTIONS_H__ */
