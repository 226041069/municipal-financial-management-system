#ifndef BUDGET_H
#define BUDGET_H

typedef struct {
    char department[30];
    double amount;
} BudgetItem;

void addBudget(BudgetItem *budget);
void displayBudget(const BudgetItem *budget);
double totalBudget(const BudgetItem budgets[], int count);

#endif
