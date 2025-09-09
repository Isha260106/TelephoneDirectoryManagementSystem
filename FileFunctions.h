#ifndef fileFunctions_H
#define fileFunctions_H

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

void addToDept(Department dept);

void fetchPrevDeptCode(char *filename);

Department getAllEntiresFromDept(char *filename);

void addEmployee(char *filename,Employee emp);

Employee getAllEmployees(char *filename);

#endif
