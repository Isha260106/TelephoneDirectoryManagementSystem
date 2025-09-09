#include<stdio.h>
#include"FileFunctions.h"

void addDept(){
    //char deptName[15];
    Department dept;
    printf("Telephone Directory Maintenance System\n");
    printf("=======================================\n");
    printf("\nAdd a Department\n");
    printf("===================\n");
    printf("Enter Department Name : ");
    scanf("%s",dept.deptName);
    addToDept(dept);
    printf("Department Code : %d",dept.deptCode);
    printf("\nPress Any key to continue\n");
    getchar();
}

int main(){
    int choice;
    while(1){
        printf("Telephone Directory Maintenance System\n");
        printf("=======================================\n");
        printf("\nDepartment Maintenance Menu\n");
        printf("==============================\n");
        printf("1. Add Department\n2. Print Department Details\n3. Goto Main Menu\nEnter your Choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1 : //Add Department
                    addDept();
                    break;
            case 2 : //Print department details
                    break;
            case 3 : //Goto Main menu 
                    break;
            default:printf("Invalid Choice\n");        
        }
    }
    return 0;
}