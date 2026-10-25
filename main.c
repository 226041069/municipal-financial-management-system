#include <stdio.h>
#include <string.h>

int main(void)
{
    char municipalityName[100];
    char mayorName[100];
    int population;

    printf("Municipal Financial Management System\n");
    printf("Welcome to Windhoek Municipality\n\n");

    printf("Enter Municipality Name: ");
    fgets(municipalityName, sizeof(municipalityName), stdin);
    municipalityName[strcspn(municipalityName, "\n")] = '\0';

    printf("Enter Mayor's Name: ");
    fgets(mayorName, sizeof(mayorName), stdin);
    mayorName[strcspn(mayorName, "\n")] = '\0';

    printf("Enter Population: ");
    scanf("%d", &population);

    printf("\n====================================\n");
    printf("Municipal Financial Management Report\n");
    printf("====================================\n");
    printf("Municipality Name: %s\n", municipalityName);
    printf("Mayor's Name: %s\n", mayorName);
    printf("Population: %d\n", population);
    printf("====================================\n");

    return 0;
}
