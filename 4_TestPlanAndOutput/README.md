# TEST PLAN and Corresponding Output

## High Level Test Plan 

|Test ID|Description|Exp. i/p|Exp. o/p|Actual o/p|Type of Test|
|---|---|---|---|---|---|
|H_01|Check if the login page is displayed properly|Program execution|Formatted Login Page|Formated Login Page|Requirement|
|H_02|Check if the menu is displayed properly|Login Credentials|Formatted menu page|Formatted menu page|Requirement|
|H_03|Not Stuck inside any Function|Function call|Proper function execution with return type and Message|Proper function execution with return type and Message|Requirement|

## Low Level Test Plan

|Test ID|Description|Exp. i/p|Exp. o/p|Actual o/p|Type of Test|
|---|---|---|---|---|---|
|L_01|Verify login credentials|Loginid and Password|Success -> Menu ; Failure -> exit|Success -> Menu ; Failure -> exit|Scenerio|
|L_02|Adding entry to the file|Details of individual|Details Added successfully|Details Added successfully|Technical|
|L_03|Deleting entry|Id of the individual|Id present -> Deleted; Id absent -> not found|Id present -> Deleted; Id absent -> not found|Technical|
|L_04|Modify Entry|Id of individual|Id present -> modify; Id absent -> not found|Id present -> modify; Id absent -> not found|Technical|
|L_05|Search Entry|Id of individual|Id present -> display; Id absent -> not found|Id present -> display; Id absent -> not found|Technical|
|L_06|Display All| - | If entries present -> Display them; else display "empty file"|If entries present -> Display them; else display "empty file"|Technical|

