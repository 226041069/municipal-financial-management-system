#ifndef BUDGETS_H
#define BUDGETS_H

typedef struct {
    int id;
    char department[30];
    double amount;
} Budget;

void addBudget(Budget *budget);
void displayBudget(const Budget *budget);
int saveBudgetsText(const char *filename, const Budget budgets[], int count);
int loadBudgetsText(const char *filename, Budget budgets[], int *count);

#endif
