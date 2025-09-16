//Declaration of user defined header file which consists of function declaration 
//for implementing various operations on files  
//Preprocessor directives
#ifndef fileFunctions_H
#define fileFunctions_H

//structure templete defination for  storing department details 
typedef struct {
    int deptCode;
    char deptName[15];
}Department;

//structure templete definition for storing employee details
typedef struct {
    char empName[25];
    int empId;
    Department dept;
    char location[5];
}Employee;

//Function declarations for telephone directory maintenance system
void addToDept(Department *dept);

void getAllEntiresFromDept();

void addEmployee(Employee *emp);

void getAllEmployees();

void addTelephoneNumber(int empId);

void enquireEmployeeName(char *name);

void enquireTelephoneNumber(int num);

void addDept();

#endif
