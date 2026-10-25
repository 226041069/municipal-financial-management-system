#include <stdio.h>

int main(void)
{
    double totalRevenue;
    double totalExpenses;
    double balance;
    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("MUNICIPAL BUDGET CALCULATOR\n\n");

    printf("Enter Total Revenue: ");
    scanf("%lf", &totalRevenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &totalExpenses);

    balance = totalRevenue - totalExpenses;

    printf("\nMunicipal Budget Summary\n");
    printf("Revenue: %.2f\n", totalRevenue);
    printf("Expenses: %.2f\n", totalExpenses);
    printf("Balance: %.2f\n", balance);

    printf("\nExtension Exercise\n");
    printf("Enter Number of Departments: ");
    scanf("%d", &departments);

    printf("Enter Payroll: ");
    scanf("%lf", &payroll);

    printf("Enter Procurement: ");
    scanf("%lf", &procurement);

    printf("Enter Assets: ");
    scanf("%lf", &assets);

    printf("\nBasic Municipal Financial Summary\n");
    printf("Departments: %d\n", departments);
    printf("Payroll: %.2f\n", payroll);
    printf("Procurement: %.2f\n", procurement);
    printf("Assets: %.2f\n", assets);

    return 0;
}
