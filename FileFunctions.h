#ifndef fileFunctions_H
#define fileFunctions_H
<<<<<<< HEAD
//uytfdrcfgvhj
//structure templete defination for  storing department details 
=======

>>>>>>> parent of 2e083d4 (Telephone Enquiryby name added)
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

void addToDept(Department *dept);

void getAllEntiresFromDept();

void addEmployee(Employee *emp);

void getAllEmployees();

void addTelephoneNumber(int empId);

void enquireEmployeeName(char *name);

void enquireTelephoneNumber(int num);

void addDept();

#endif
