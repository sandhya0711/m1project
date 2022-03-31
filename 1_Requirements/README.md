# Requirements

## Introduction

1. This is a demo Database Management System
2. Secured using login id and password
3. Allows operations such as
   - Add data
   - Delete data
   - Modify
   - Search
   - Display All
4. For demostration the data is stored in 'mydb.dat'
5. The default `login id - 256000` and `Password - 12345`

## Cost and Features

| S.No. | Features | Cost (Rs.) |
| ---   | ---      |  ---       |
| 1 | Secured Login | 0 |
| 2 | Add Entry | 0 |
| 3 | Search | 0 |
| 4 | Modify | 0 |
| 5 | Delete | 0 |
| 6 | Display All | 0 |

## Defining our System

This is demo Database Management System. On execution the system requires from the use the login credential comprising of a unique Id and Password. On providing the correct Id and Password the operations to the database are then displayed and allowed by the program else it quits in receiving wrong information.

The menu displays options to add, delete, modify, search and display.

1. **Add -** Allows addition of new entry into the database with a unique id.
2. **Delete -** Allows deletion of a particular entry by a given id.
3. **Modify -** Allows modification of a particular field of the entry by id.
4. **Search -** For searching if an entry is present or not.
5. **Display -** To display all the entries present in the database.

## SWOT Analysis

![Drawing](https://user-images.githubusercontent.com/79442246/115001828-a8097180-9ec1-11eb-8723-1714e306fe8c.jpg)


## 4 W's and 1 H

### WHO -
   This will cater to all those who are beginners to database management and file handling
### WHAT -
   It's free and can be easily used by people of all ages
### WHEN -
   Database is a very imporatant tool in today's era and hence this will be welcomed at all times when someone wants to learn it.
### WHERE -
   Fields where records are being digitised and for teaching the beginners
### HOW -
   It will be used by everyone since simple to use.


# Detail Requirements

## High Level Requirements

|Id|Description|Category|Status|
|---|---|---|---|
|HLR1|Login should work|Technical|Implemented|
|HLR2|Menu should display|Technical|Implemented|
|HLR3|Decision making of the Program|Scenerio|Implemented|
|HLR4|File should edit according to the commands|Technical|Implemented|

## Low Level Requirements

|Id|Description|Category|HLRID|Status|
|---|---|---|---|---|
|LLR1|Menu should display when Credentials Match|Technical|1, 2|Implemented|
|LLR2|Program should exit when credentials don't match|Technical|1, 3|Implemented|
|LLR3|Action executed according to the input given|Technical|2, 3, 4|Implemented|
|LLR4|Appropriate error messages at failure and success of operations|Technical|1, 2, 3, 4|Implemented|

