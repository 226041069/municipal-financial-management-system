#ifndef EMPLOYEES_H
#define EMPLOYEES_H

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

void addEmployee(Employee *employee);
void displayEmployee(const Employee *employee);
double totalPayroll(const Employee employees[], int count);

#endif
