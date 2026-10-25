#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budgets.h"

void printMainMenu(void);
void printEmployeeList(const Employee employees[], int count);
void printSupplierList(const Supplier suppliers[], int count);
void printAssetList(const Asset assets[], int count);
void printBudgetList(const Budget budgets[], int count);

#endif
