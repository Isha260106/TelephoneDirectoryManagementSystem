#include "FileFunctions.h"
#include<stdio.h>
#include<string.h>
void addToDept(char *filename, Department dept){
    FILE *fp=fopen(filename,'a');
    char buffer[256];
    int id=1000;
    if(fp==NULL){
        printf("Failed to open the file");
        return;
    }
    rewind(fp);
    while(fgets(fp,"%s %d",buffer,&id)!=NULL){
        if(strcmp(buffer,dept.deptName)==0){
            printf("Duplicate Entry\n");
            return;
        }
    }
    fprintf(fp,"%s\t%d\n",dept.deptName,id++);
}