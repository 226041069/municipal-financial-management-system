#include <stdio.h>
#include <string.h>

#define MAX_SALARIES 50
#define MAX_BUDGETS 10
#define MAX_REGISTRATIONS 20

int main(void)
{
    float salaries[MAX_SALARIES];
    float budgets[MAX_BUDGETS];
    char registrations[MAX_REGISTRATIONS][20];
    int i, j, n;
    float totalSalary = 0.0f, averageSalary, highestSalary, lowestSalary, searchSalary;
    float totalBudget = 0.0f, averageBudget;
    char searchReg[20];
    int foundSalary = 0, foundReg = 0;

    printf("MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n\n");

    printf("A. Employee Salaries\n");
    for (i = 0; i < MAX_SALARIES; i++)
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
        totalSalary += salaries[i];
    }

    highestSalary = salaries[0];
    lowestSalary = salaries[0];
    for (i = 1; i < MAX_SALARIES; i++)
    {
        if (salaries[i] > highestSalary)
            highestSalary = salaries[i];
        if (salaries[i] < lowestSalary)
            lowestSalary = salaries[i];
    }

    averageSalary = totalSalary / MAX_SALARIES;

    printf("\nEnter salary to search: ");
    scanf("%f", &searchSalary);
    for (i = 0; i < MAX_SALARIES; i++)
    {
        if (salaries[i] == searchSalary)
        {
            foundSalary = 1;
            break;
        }
    }

    printf("\nAll Salaries:\n");
    for (i = 0; i < MAX_SALARIES; i++)
    {
        printf("%.2f\n", salaries[i]);
    }
    printf("Average Salary: %.2f\n", averageSalary);
    printf("Highest Salary: %.2f\n", highestSalary);
    printf("Lowest Salary: %.2f\n", lowestSalary);
    if (foundSalary)
        printf("Salary %.2f was found.\n", searchSalary);
    else
        printf("Salary %.2f was not found.\n", searchSalary);

    printf("\nB. Department Budgets\n");
    for (i = 0; i < MAX_BUDGETS; i++)
    {
        printf("Enter budget %d: ", i + 1);
        scanf("%f", &budgets[i]);
        totalBudget += budgets[i];
    }

    averageBudget = totalBudget / MAX_BUDGETS;

    printf("\nAll Budgets:\n");
    for (i = 0; i < MAX_BUDGETS; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    for (i = 0; i < MAX_BUDGETS; i++)
    {
        for (j = i + 1; j < MAX_BUDGETS; j++)
        {
            if (budgets[i] > budgets[j])
            {
                float temp = budgets[i];
                budgets[i] = budgets[j];
                budgets[j] = temp;
            }
        }
    }

    printf("\nSorted Budgets (Lowest to Highest):\n");
    for (i = 0; i < MAX_BUDGETS; i++)
    {
        printf("%.2f\n", budgets[i]);
    }
    printf("Total Budget: %.2f\n", totalBudget);
    printf("Average Budget: %.2f\n", averageBudget);

    printf("\nC. Vehicle Registration Numbers\n");
    for (i = 0; i < MAX_REGISTRATIONS; i++)
    {
        printf("Enter registration %d: ", i + 1);
        scanf("%s", registrations[i]);
    }

    printf("\nAll Registrations:\n");
    for (i = 0; i < MAX_REGISTRATIONS; i++)
    {
        printf("%s\n", registrations[i]);
    }

    printf("\nEnter registration to search: ");
    scanf("%s", searchReg);
    for (i = 0; i < MAX_REGISTRATIONS; i++)
    {
        if (strcmp(registrations[i], searchReg) == 0)
        {
            foundReg = 1;
            break;
        }
    }

    if (foundReg)
        printf("Registration %s was found.\n", searchReg);
    else
        printf("Registration %s was not found.\n", searchReg);

    return 0;
}
