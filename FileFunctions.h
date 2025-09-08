#include<stdio.h>

typedef struct {
    int deptCode;
    char deptName[15];
}Department;

typedef struct {
    char empName[25];
    int empId;
    Department dept;
    char location[5];
}Employee;

void addToDept(char *filename, Department dept);

void fetchPrevDeptCode(char *filename);

Department getAllEntiresFromDept(char *filename);

void addEmployee(char *filename,Employee emp);

Employee getAllEmployees(char *filename);


