#include <stdio.h>

#include "reports.h"
#include "utilities.h"

void printMainMenu(void)
{
    printf("\n======================================\n");
    printf("MFMS MANAGEMENT SYSTEM\n");
    printf("======================================\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Add Supplier\n");
    printf("4. Display Suppliers\n");
    printf("5. Add Asset\n");
    printf("6. Display Assets\n");
    printf("7. Add Budget\n");
    printf("8. Display Budgets\n");
    printf("9. Save Data\n");
    printf("10. Load Data\n");
    printf("11. Exit\n");
    printDivider();
}

void printEmployeeList(const Employee employees[], int count)
{
    printf("\n--- EMPLOYEE LIST ---\n");
    for (int i = 0; i < count; i++)
    {
        displayEmployee(&employees[i]);
        printf("\n");
    }
}

void printSupplierList(const Supplier suppliers[], int count)
{
    printf("\n--- SUPPLIER LIST ---\n");
    for (int i = 0; i < count; i++)
    {
        displaySupplier(&suppliers[i]);
        printf("\n");
    }
}

void printAssetList(const Asset assets[], int count)
{
    printf("\n--- ASSET LIST ---\n");
    for (int i = 0; i < count; i++)
    {
        displayAsset(&assets[i]);
        printf("\n");
    }
}

void printBudgetList(const Budget budgets[], int count)
{
    printf("\n--- BUDGET LIST ---\n");
    for (int i = 0; i < count; i++)
    {
        displayBudget(&budgets[i]);
        printf("\n");
    }
}
