#include <stdio.h>
#include "FileFunctions.h"

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


