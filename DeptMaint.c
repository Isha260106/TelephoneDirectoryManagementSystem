//Pre-processor directives
#include <stdio.h>
#include "FileFunctions.h"

/*
Function to add a department to the file dept.txt
Function Name : addDept
Arguments : void
Return Type : void
Author : 
Date : 08/09/2025
*/
void addDept() {
    Department dept;
    printf("Telephone Directory Maintenance System\n");
    printf("==================================\n");
    printf("\nAdd a Department\n");
    printf("===================\n");
    printf("Enter Department Name : ");
    scanf("%s", dept.deptName);
    
    addToDept(&dept);
    
    if (dept.deptCode != 0) {
        printf("Department Code : %d\n", dept.deptCode);
    }

    printf("\nPress Enter to continue...\n");
    while (getchar() != '\n');  
    getchar();                   
}


