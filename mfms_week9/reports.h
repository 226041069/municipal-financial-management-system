#include <stdio.h>
#include <string.h>

#include "budgets.h"
#include "utilities.h"

void addBudget(Budget *budget)
{
    budget->id = inputInt("Enter budget ID: ");
    readString("Enter department name: ", budget->department, sizeof(budget->department));
    budget->amount = inputDouble("Enter department budget: ");
}

void displayBudget(const Budget *budget)
{
    printf("Budget ID: %d\n", budget->id);
    printf("Department: %s\n", budget->department);
    printf("Amount: %.2f\n", budget->amount);
}

int saveBudgetsText(const char *filename, const Budget budgets[], int count)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        perror("Error opening budgets file for writing");
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d|%s|%.2f\n",
                budgets[i].id,
                budgets[i].department,
                budgets[i].amount);
    }

    fclose(fp);
    return 1;
}

int loadBudgetsText(const char *filename, Budget budgets[], int *count)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        perror("Error opening budgets file for reading");
        return 0;
    }

    *count = 0;
    while (*count < 100 && fscanf(fp, "%d|%29[^|]|%lf\n",
                                  &budgets[*count].id,
                                  budgets[*count].department,
                                  &budgets[*count].amount) == 3)
    {
        (*count)++;
    }

    fclose(fp);
    return 1;
}
