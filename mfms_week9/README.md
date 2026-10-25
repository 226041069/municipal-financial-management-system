#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budgets.h"
#include "reports.h"
#include "utilities.h"

#define MAX_EMPLOYEES 100
#define MAX_SUPPLIERS 100
#define MAX_ASSETS 100
#define MAX_BUDGETS 100

int ensureDataDirectory(const char *directory)
{
    struct stat st = {0};
    if (stat(directory, &st) == -1)
    {
        if (mkdir(directory, 0777) != 0)
        {
            perror("Unable to create data directory");
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    Employee employees[MAX_EMPLOYEES];
    Supplier suppliers[MAX_SUPPLIERS];
    Asset assets[MAX_ASSETS];
    Budget budgets[MAX_BUDGETS];

    int employeeCount = 0;
    int supplierCount = 0;
    int assetCount = 0;
    int budgetCount = 0;
    int choice;

    const char *dataDir = "data";
    if (!ensureDataDirectory(dataDir))
    {
        return 1;
    }

    do
    {
        printMainMenu();
        choice = inputInt("Enter choice: ");

        switch (choice)
        {
            case 1:
                if (employeeCount < MAX_EMPLOYEES)
                {
                    addEmployee(&employees[employeeCount]);
                    employeeCount++;
                    printf("Employee added successfully.\n");
                }
                else
                {
                    printf("Maximum employee limit reached.\n");
                }
                break;

            case 2:
                printEmployeeList(employees, employeeCount);
                break;

            case 3:
                if (supplierCount < MAX_SUPPLIERS)
                {
                    addSupplier(&suppliers[supplierCount]);
                    supplierCount++;
                    printf("Supplier added successfully.\n");
                }
                else
                {
                    printf("Maximum supplier limit reached.\n");
                }
                break;

            case 4:
                printSupplierList(suppliers, supplierCount);
                break;

            case 5:
                if (assetCount < MAX_ASSETS)
                {
                    addAsset(&assets[assetCount]);
                    assetCount++;
                    printf("Asset added successfully.\n");
                }
                else
                {
                    printf("Maximum asset limit reached.\n");
                }
                break;

            case 6:
                printAssetList(assets, assetCount);
                break;

            case 7:
                if (budgetCount < MAX_BUDGETS)
                {
                    addBudget(&budgets[budgetCount]);
                    budgetCount++;
                    printf("Budget added successfully.\n");
                }
                else
                {
                    printf("Maximum budget limit reached.\n");
                }
                break;

            case 8:
                printBudgetList(budgets, budgetCount);
                break;

            case 9:
            {
                char path[100];

                snprintf(path, sizeof(path), "%s/employees.txt", dataDir);
                if (!saveEmployeesText(path, employees, employeeCount))
                    printf("Failed to save employees.\n");

                snprintf(path, sizeof(path), "%s/suppliers.txt", dataDir);
                if (!saveSuppliersText(path, suppliers, supplierCount))
                    printf("Failed to save suppliers.\n");

                snprintf(path, sizeof(path), "%s/assets.txt", dataDir);
                if (!saveAssetsText(path, assets, assetCount))
                    printf("Failed to save assets.\n");

                snprintf(path, sizeof(path), "%s/budgets.txt", dataDir);
                if (!saveBudgetsText(path, budgets, budgetCount))
                    printf("Failed to save budgets.\n");

                printf("Data saved successfully.\n");
                break;
            }

            case 10:
            {
                char path[100];

                snprintf(path, sizeof(path), "%s/employees.txt", dataDir);
                if (loadEmployeesText(path, employees, &employeeCount))
                    printf("Employees loaded.\n");

                snprintf(path, sizeof(path), "%s/suppliers.txt", dataDir);
                if (loadSuppliersText(path, suppliers, &supplierCount))
                    printf("Suppliers loaded.\n");

                snprintf(path, sizeof(path), "%s/assets.txt", dataDir);
                if (loadAssetsText(path, assets, &assetCount))
                    printf("Assets loaded.\n");

                snprintf(path, sizeof(path), "%s/budgets.txt", dataDir);
                if (loadBudgetsText(path, budgets, &budgetCount))
                    printf("Budgets loaded.\n");
                break;
            }

            case 11:
                printf("Exiting MFMS...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 11);

    return 0;
}
