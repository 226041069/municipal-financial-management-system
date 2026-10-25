#include <stdio.h>

#include "budget.h"
#include "utilities.h"

void addBudget(BudgetItem *budget)
{
    readString("Enter department name: ", budget->department, sizeof(budget->department));
    budget->amount = inputDouble("Enter department budget: ");
}

void displayBudget(const BudgetItem *budget)
{
    printf("Department: %s\n", budget->department);
    printf("Budget: %.2f\n", budget->amount);
}

double totalBudget(const BudgetItem budgets[], int count)
{
    double total = 0.0;
    for (int i = 0; i < count; i++)
    {
        total += budgets[i].amount;
    }
    return total;
}
