#include <stdio.h>

#include "employees.h"
#include "utilities.h"

void addEmployee(Employee *employee)
{
    readString("Enter employee name: ", employee->name, sizeof(employee->name));
    employee->id = inputInt("Enter employee ID: ");
    employee->salary = inputDouble("Enter employee salary: ");
}

void displayEmployee(const Employee *employee)
{
    printf("ID: %d\n", employee->id);
    printf("Name: %s\n", employee->name);
    printf("Salary: %.2f\n", employee->salary);
}

double totalPayroll(const Employee employees[], int count)
{
    double total = 0.0;
    for (int i = 0; i < count; i++)
    {
        total += employees[i].salary;
    }
    return total;
}
