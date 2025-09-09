#include "FileFunctions.h"
#include<stdio.h>
#include<string.h>
void addToDept(Department dept){
    FILE *fp=fopen("dept.txt","r+");
    char name[256];
    int id,maxId=1000;
    if(fp==NULL){
        printf("Failed to open the file");
        return;
    }
    rewind(fp);

    while(fscanf(fp,"%s %d",name,&id)==2){
        if(strcmp(name,dept.deptName)==0){
            printf("Duplicate Entry\n");
            return;
        }
        if(id>maxId){
            maxId=id;
        }
    }
    id=maxId+1;
    fseek(fp, 0, SEEK_END);
    fprintf(fp,"%s\t%d\n",dept.deptName,id);
}