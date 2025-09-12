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
    fprintf(fp, "%-25s %4d %4d %-15s %-5s\n", emp->empName, emp->empId, emp->dept.deptCode,emp->dept.deptName,emp->location);
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

void addTelephoneNumber(int empId) {
    FILE *fpEmp = fopen("emp.txt", "r");
    if (!fpEmp) {
        printf("Failed to open emp.txt\n");
        return;
    }

    char name[25], deptName[15], loc[5];
    int id, deptCode, found = 0;
    while (fscanf(fpEmp, "%24s %d %d %14s %4s", name, &id, &deptCode, deptName, loc) == 5) {
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

    int maxNo = deptCode * 1000 + 1;

    FILE *fpTel = fopen("temp.txt", "r+");
    if (!fpTel) {
        fpTel = fopen("temp.txt", "w+");
        if (!fpTel) {
            printf("Failed to open or create temp.txt\n");
            return;
        }
    }
    char tname[25], tdeptName[15], tloc[5];
    int tid, tdeptCode, telNo;
    rewind(fpTel);
    while (fscanf(fpTel, "%24s %d %d %14s %4s %d", tname, &tid, &tdeptCode, tdeptName, tloc, &telNo) == 6) {
        if(tid==empId){
            printf("Duplicate entry\n");
            return;
        }
        if (tdeptCode == deptCode && telNo >= maxNo) {
            maxNo = telNo + 1;
        }
    }
    fseek(fpTel, 0, SEEK_END);
    fprintf(fpTel, "%-25s %4d %4d %-15s %-5s %7d\n", name, id, deptCode, deptName, loc, maxNo);
    printf("Telephone number allocated : %d\n", maxNo);
    printf("Press enter to continue");
    while(getchar()!='\n');
    getchar();
    fclose(fpTel);
}

void enquireEmployeeName(char *name){
    FILE *fp=fopen("temp.txt","r");
    if(fp==NULL){
        printf("File cant be opened\n");
        return;
    }
    char tname[25],location[5],deptName[15];
    int empId,deptId,telNo;
    while(fscanf(fp,"%s %d %d %s %s %d",tname,empId,deptId,deptName,location,telNo)==6){
        if(strcmp(name,tname)==0){
            printf("%-25s %-5s %-15s %7d\n",tname,location,deptName,telNo);
        }
    }
    printf("Press enter to continue");
    while(getchar()!='\n');
    getchar();
    fclose(fp);
}

