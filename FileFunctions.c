#include "FileFunctions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void addToDept(Department *dept){
    FILE *fp = fopen("dept.txt", "r+");
    if (fp == NULL) {
        fp = fopen("dept.txt", "w+");
        if (fp == NULL) {
            printf("Failed to create the file.\n");
            return;
        }
    }

    char name[15];
    int id;
    int maxId = 1000;

    char nameLower[15];
    char deptNameLower[15];
    for (int i = 0; dept->deptName[i]; i++) {
        deptNameLower[i] = tolower((unsigned char)dept->deptName[i]);
    }
    deptNameLower[strlen(dept->deptName)] = '\0';

    while (fscanf(fp, "%s %d", name, &id) == 2) {
        for (int i = 0; name[i]; i++) {
            nameLower[i] = tolower((unsigned char)name[i]);
        }
        nameLower[strlen(name)] = '\0';

        if (strcmp(nameLower, deptNameLower) == 0) {
            printf("Duplicate Entry\n");
            dept->deptCode = 0;
            fclose(fp);
            return;
        }

        if (id >= maxId) {
            maxId = id;
        }
    }

    dept->deptCode = maxId + 1;

    fseek(fp, 0, SEEK_END);
    fprintf(fp, "%s %d\n", dept->deptName, dept->deptCode);

    printf("Department added successfully!\n");

    fclose(fp);
}

void getAllEntiresFromDept(){
    FILE *fp = fopen("dept.txt", "r");
    char name[15];
    int id;
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    printf("Department DeptCode\n");
    while(fscanf(fp,"%s %d",name,&id)==2){
        printf("%-15s %4d\n",name,id);
    }
    fclose(fp);
    return;
}

void addEmployee(Employee *emp){
    FILE *fp = fopen("emp.txt", "r+");
    if (fp == NULL) {
        fp = fopen("emp.txt", "w+");
        if (fp == NULL) {
            printf("Failed to create the file.\n");
            return;
        }
    }
    char name[25],deptName[15],loc[5];
    int id,deptCode;
    int maxId = 1000;

    while (fscanf(fp, "%s %d %d %s %s", name, &id, &deptCode,deptName,loc) == 5) {
        if (id >= maxId) {
            maxId = id;
        }
    }

    emp->empId = maxId + 1;
    printf("\nEmployee Id : %d\n",emp->empId);

    getAllEntiresFromDept();

    printf("Enter Department Code : ");
    scanf("%d",&emp->dept.deptCode);
    FILE *fp1=fopen("dept.txt","r+");
    if(fp1==NULL){
        printf("File Not found\n");
        return;
    }
    int found=0;
    while(fscanf(fp1,"%s %d",name,&id)==2){
        if(id==emp->dept.deptCode){
            strcpy(emp->dept.deptName,name);
            found=1;
            break;
        }
    }
    fclose(fp1);
    if(found==0){
        printf("Invalid Code!!\n");
        return;
    }else{
    printf("Department Name : %s\n",emp->dept.deptName);
    //fclose(fp1);
    printf("Enter Location : ");
    scanf("%s",emp->location);
   
    
    fseek(fp, 0, SEEK_END);
    fprintf(fp, "%s %d %d %s %s\n", emp->empName, emp->empId, emp->dept.deptCode,emp->dept.deptName,emp->location);
    printf("Press enter to continue\n");
    while(getchar()!='\n');
    getchar();
    fclose(fp);
    }
}
void getAllEmployees(){
    FILE *fp = fopen("emp.txt", "r");
    char name[25],deptName[15];
    int id,deptCode;
    char loc[5];
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    printf("Employee EmpID\n");
    while(fscanf(fp,"%s %d %d %s %s",name,&id,&deptCode,deptName,loc)==5){
        printf("%-25s %4d %4d %-15s %-5s\n",name,id,deptCode,deptName,loc);
    }
    return;
}
void addTelephoneNumber(int empId){
    // FILE *fp=fopen("emp.txt","r");
    //  if (fp == NULL) {
    //     printf("Failed to open the file.\n");
    //     return;
    // }
    // char name[25],deptName[15],loc[5];
    // int deptCode,id,found=0;
    // while(fscanf(fp,"%s %d %d %s %s",name,&id,&deptCode,deptName,loc)==5){
    //     if(empId==id){
    //         found=1;
    //         break;
    //     }
    // }
    // fclose(fp);
    // if(found==0){
    //     printf("Employee ID not found\n");
    //     return;
    // }
    // else{
    //     printf("%-5s %4d\n",loc,deptCode);
    //     int maxNo=deptCode*1000+1;
    //     // printf("%d\n",maxNo);
    //     FILE *fp=fopen("temp.txt","r");
    //     FILE *fp1=fopen("temp.txt","a");
    //     if (fp == NULL ) {
    //         printf("Failed to open the file.\n");
    //         return;
    //     }
    //     int telNo,deptCode1;
    //     while(fscanf(fp,"%s %d %d %s %s %d",name,&id,&deptCode1,deptName,loc,telNo)==6){
    //         if(deptCode==deptCode1){
    //             if(telNo>=maxNo)
    //             {
    //                 maxNo=telNo+1;
    //             }
    //         }
    //     }
    //     fseek(fp, 0, SEEK_END);
    //     fprintf(fp1,"%s %d %d %s %s %d\n",name,id,deptCode1,deptName,loc,maxNo);
    //     fclose(fp);
    //     fclose(fp1);
    // }
     FILE *fpEmp = fopen("emp.txt", "r");
    if (fpEmp == NULL) {
        printf("Failed to open emp.txt\n");
        return;
    }

    char name[25], deptName[15], loc[5];
    int id, deptCode;
    int found = 0;
     while (fscanf(fpEmp, "%s %d %d %s %s", name, &id, &deptCode, deptName, loc) == 5) {
        if (id == empId) {
            found = 1;
            break;
        }
    }
    fclose(fpEmp);

    if (!found) {
        printf("Employee ID not found\n");
        return;
    }

    printf("Employee found: %-5s %4d\n", loc, deptCode);

    int maxNo = deptCode * 1000 + 1;

    // Open temp.txt to find the max telephone number for this department
    FILE *fpRead = fopen("temp.txt", "r");
    if (fpRead == NULL){return;}
        char tname[25], tdeptName[15], tloc[5];
        int tid, tdeptCode, tno;
        while (fscanf(fpRead, "%s %d %d %s %s %d", tname, &tid, &tdeptCode, tdeptName, tloc, &tno) == 6) {
            if (tdeptCode == deptCode && tno >= maxNo) {
                maxNo = tno + 1;
            }
        }
        fclose(fpRead);
    

    // Open temp.txt in append mode to add the new record
    FILE *fpAppend = fopen("temp.txt", "a");
    if (fpAppend == NULL) {
        printf("Failed to open temp.txt for appending\n");
        return;
    }

    // Append the new telephone record
    fprintf(fpAppend, "%s %d %d %s %s %d\n", name, id, deptCode, deptName, loc, maxNo);

    printf("Added telephone number %d for employee %s\n", maxNo, name);

    fclose(fpAppend);
}
