#ifndef EMPLOYEES_H
#define EMPLOYEES_H

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

void addEmployee(Employee *employee);
void displayEmployee(const Employee *employee);
int saveEmployeesText(const char *filename, const Employee employees[], int count);
int loadEmployeesText(const char *filename, Employee employees[], int *count);
int saveEmployeesBinary(const char *filename, const Employee employees[], int count);
int loadEmployeesBinary(const char *filename, Employee employees[], int *count);

double totalPayroll(const Employee employees[], int count);

#endif
