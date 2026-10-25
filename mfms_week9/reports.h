#ifndef REPORTS_H
#define REPORTS_H

#include "budget.h"
#include "employees.h"

void printMainMenu(void);
void printEmployeeSummary(const Employee employees[], int count);
void printBudgetSummary(const BudgetItem budgets[], int count);
void printOverallSummary(const Employee employees[], int count, const BudgetItem budgets[], int budgetCount);

#endif
