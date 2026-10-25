#include <stdio.h>

#include "budget.h"
#include "employees.h"
#include "reports.h"
#include "utilities.h"

int main(void)
{
    Employee employees[10];
    BudgetItem budgets[10];
    int employeeCount = 0;
    int budgetCount = 0;
    int choice;

    do
    {
        printMainMenu();
        choice = inputInt("Enter choice: ");

        switch (choice)
        {
            case 1:
                if (employeeCount < 10)
                {
                    addEmployee(&employees[employeeCount]);
                    employeeCount++;
                    printf("Employee added successfully.\n");
                }
                else
                {
                    printf("Employee list is full.\n");
                }
                break;

            case 2:
                printEmployeeSummary(employees, employeeCount);
                break;

            case 3:
                if (budgetCount < 10)
                {
                    addBudget(&budgets[budgetCount]);
                    budgetCount++;
                    printf("Budget added successfully.\n");
                }
                else
                {
                    printf("Budget list is full.\n");
                }
                break;

            case 4:
                printBudgetSummary(budgets, budgetCount);
                break;

            case 5:
                printOverallSummary(employees, employeeCount, budgets, budgetCount);
                break;

            case 6:
                printf("Exiting MFMS...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
