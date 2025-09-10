#include<stdio.h>
#include "FileFunctions.h"
void deptMaintenance(){
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
                return;
                break;
            default:
                printf("Invalid Choice\n");
        }
    } 
}

int main(){
    int choice;
    while(1){
        printf("Telephone Directory Maintenance System\n");
        printf("==================================\n");
        printf("Main Menu\n");
        printf("==========\n");
        printf("1. Department Maintenance\n2. Employee Maintenance\n3.Telephone Directory Maintenance\n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: deptMaintenance();
                break;
        
        default:
            break;
        }
    }
    return 0;
}