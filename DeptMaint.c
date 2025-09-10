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

int main() {
    int choice;
    while (1) {
        printf("Telephone Directory Maintenance System\n");
        printf("=======================================\n");
        printf("\nDepartment Maintenance Menu\n");
        printf("==============================\n");
        printf("1. Add Department\n");
        printf("2. Print Department Details \n");
        printf("3. Goto Main menu\n");
        printf("Enter your Choice : ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addDept();
                break;
            case 2:
                getAllEntiresFromDept();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
