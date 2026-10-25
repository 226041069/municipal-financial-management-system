#include <stdio.h>
#include <string.h>

#include "employees.h"
#include "utilities.h"

void addEmployee(Employee *employee)
{
    employee->id = inputInt("Enter employee ID: ");
    readString("Enter employee name: ", employee->name, sizeof(employee->name));
    employee->salary = inputDouble("Enter employee salary: ");
}

void displayEmployee(const Employee *employee)
{
    printf("Employee ID: %d\n", employee->id);
    printf("Name: %s\n", employee->name);
    printf("Salary: %.2f\n", employee->salary);
}

int saveEmployeesText(const char *filename, const Employee employees[], int count)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        perror("Error opening employees file for writing");
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d|%s|%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    fclose(fp);
    return 1;
}

int loadEmployeesText(const char *filename, Employee employees[], int *count)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        perror("Error opening employees file for reading");
        return 0;
    }

    *count = 0;
    while (*count < 100 && fscanf(fp, "%d|%49[^|]|%lf\n",
                                  &employees[*count].id,
                                  employees[*count].name,
                                  &employees[*count].salary) == 3)
    {
        (*count)++;
    }

    fclose(fp);
    return 1;
}

int saveEmployeesBinary(const char *filename, const Employee employees[], int count)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp)
    {
        perror("Error opening employees binary file for writing");
        return 0;
    }

    fwrite(employees, sizeof(Employee), (size_t)count, fp);
    fclose(fp);
    return 1;
}

int loadEmployeesBinary(const char *filename, Employee employees[], int *count)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        perror("Error opening employees binary file for reading");
        return 0;
    }

    *count = 0;
    while (fread(&employees[*count], sizeof(Employee), 1, fp) == 1)
    {
        (*count)++;
    }

    fclose(fp);
    return 1;
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
