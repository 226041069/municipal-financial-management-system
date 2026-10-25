#include <stdio.h>
#include <string.h>

#include "utilities.h"

int inputInt(const char *prompt)
{
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    clearInputBuffer();
    return value;
}

double inputDouble(const char *prompt)
{
    double value;
    printf("%s", prompt);
    scanf("%lf", &value);
    clearInputBuffer();
    return value;
}

void readString(const char *prompt, char *buffer, size_t size)
{
    printf("%s", prompt);
    if (fgets(buffer, (int)size, stdin) == NULL)
    {
        buffer[0] = '\0';
        return;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
}

void clearInputBuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        ;
    }
}

void printDivider(void)
{
    printf("----------------------------------------------\n");
}
