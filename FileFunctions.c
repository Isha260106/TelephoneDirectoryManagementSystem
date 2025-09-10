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

        if (id > maxId) {
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
    while(fscanf(fp,"%15s %4d",name,&id)==2){
        printf("%-15s %4d\n",name,id);
    }
    return;
}