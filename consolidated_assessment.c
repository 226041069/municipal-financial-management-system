#include <stdio.h>
#include <string.h>

int main(void)
{
    char studentName[100];
    double test1, test2, assignment;
    double total;
    char result[20];

    printf("CONSOLIDATED ASSESSMENT EXERCISE\n\n");
    printf("Enter Student Name: ");
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = '\0';

    printf("Enter Test 1 Mark: ");
    scanf("%lf", &test1);

    printf("Enter Test 2 Mark: ");
    scanf("%lf", &test2);

    printf("Enter Assignment Mark: ");
    scanf("%lf", &assignment);

    total = test1 + test2 + assignment;

    if (total >= 75 && total <= 100)
    {
        strcpy(result, "Distinction");
    }
    else if (total >= 60 && total <= 74)
    {
        strcpy(result, "Credit");
    }
    else if (total >= 50 && total <= 59)
    {
        strcpy(result, "Pass");
    }
    else
    {
        strcpy(result, "Fail");
    }

    printf("\nStudent Assessment Report\n");
    printf("Student Name: %s\n", studentName);
    printf("Test 1: %.2f\n", test1);
    printf("Test 2: %.2f\n", test2);
    printf("Assignment: %.2f\n", assignment);
    printf("Total: %.2f\n", total);
    printf("Total Result: %s\n", result);

    return 0;
}
