#include <stdio.h>
#include <string.h>

int main(void)
{
    char supplierName[100];
    char email[100];
    char phone[20];
    char town[50];
    char copyName[100];
    char searchName[100];

    printf("WEEK 7 MINI-ASSESSMENT\n\n");

    printf("Enter Supplier Name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter Phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter Town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("\nSupplier Information\n");
    printf("Supplier Name: %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town: %s\n", town);

    printf("\nSupplier Name Length: %zu\n", strlen(supplierName));

    strcpy(copyName, supplierName);
    printf("Copied Supplier Name: %s\n", copyName);

    printf("\nEnter Supplier Name to Search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplierName, searchName) == 0)
    {
        printf("Supplier found.\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    return 0;
}
