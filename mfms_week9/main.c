#include <stdio.h>

#include "reports.h"
#include "utilities.h"

void printMainMenu(void)
{
    printf("\n=== MUNICIPAL FINANCIAL MANAGEMENT SYSTEM ===\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Add Budget\n");
    printf("4. Display Budgets\n");
    printf("5. Show Reports\n");
    printf("6. Exit\n");
    printDivider();
}

void printEmployeeSummary(const Employee employees[], int count)
{
    printf("\n=== EMPLOYEE SUMMARY ===\n");
    if (count == 0)
    {
        printf("No employees recorded.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        displayEmployee(&employees[i]);
        printf("\n");
    }
    printf("Total payroll: %.2f\n", totalPayroll(employees, count));
}

void printBudgetSummary(const BudgetItem budgets[], int count)
{
    printf("\n=== BUDGET SUMMARY ===\n");
    if (count == 0)
    {
        printf("No budgets recorded.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        displayBudget(&budgets[i]);
        printf("\n");
    }
    printf("Total budget: %.2f\n", totalBudget(budgets, count));
}

void printOverallSummary(const Employee employees[], int count, const BudgetItem budgets[], int budgetCount)
{
    printf("\n=== OVERALL REPORT ===\n");
    printf("Employee count: %d\n", count);
    printf("Budget count: %d\n", budgetCount);
    printf("Total payroll: %.2f\n", totalPayroll(employees, count));
    printf("Total budget: %.2f\n", totalBudget(budgets, budgetCount));
}
