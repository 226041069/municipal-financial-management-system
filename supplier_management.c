#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define NAME_LEN 100
#define EMAIL_LEN 100
#define PHONE_LEN 20
#define TOWN_LEN 50

struct Supplier {
    char name[NAME_LEN];
    char email[EMAIL_LEN];
    char phone[PHONE_LEN];
    char town[TOWN_LEN];
};

void trimNewline(char *str)
{
    int len = strlen(str);

    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void addSupplier(struct Supplier *s)
{
    printf("Enter supplier name: ");
    fgets(s->name, sizeof(s->name), stdin);
    trimNewline(s->name);

    printf("Enter email: ");
    fgets(s->email, sizeof(s->email), stdin);
    trimNewline(s->email);

    printf("Enter phone: ");
    fgets(s->phone, sizeof(s->phone), stdin);
    trimNewline(s->phone);

    printf("Enter town: ");
    fgets(s->town, sizeof(s->town), stdin);
    trimNewline(s->town);
}

void displaySupplier(struct Supplier s)
{
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", s.name);
    printf("Email: %s\n", s.email);
    printf("Phone: %s\n", s.phone);
    printf("Town : %s\n", s.town);
}

void showNameLength(struct Supplier s)
{
    printf("\nSupplier name length: %zu\n", strlen(s.name));
    printf("Email length: %zu\n", strlen(s.email));
    printf("Town length: %zu\n", strlen(s.town));
}

int searchSupplier(struct Supplier suppliers[], int count, const char *target)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(suppliers[i].name, target) == 0)
        {
            return i;
        }
    }
    return -1;
}

void copySupplierExample()
{
    char original[100] = "ABC Office Supplies";
    char backup[100];

    strcpy(backup, original);

    printf("\n--- COPY EXAMPLE ---\n");
    printf("Original: %s\n", original);
    printf("Backup: %s\n", backup);
}

void buildSupplierDescription()
{
    char name[100] = "ABC Office Supplies";
    char town[50] = "Windhoek";
    char description[200] = "";

    strcpy(description, name);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");

    printf("\n--- SUPPLIER DESCRIPTION ---\n");
    printf("%s\n", description);
}

int main(void)
{
    struct Supplier suppliers[MAX_SUPPLIERS];
    int count = 0;
    int choice;
    char searchName[NAME_LEN];

    while (1)
    {
        printf("================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count < MAX_SUPPLIERS)
            {
                addSupplier(&suppliers[count]);
                count++;
                printf("\nSupplier added successfully.\n");
            }
            else
            {
                printf("\nMaximum number of suppliers reached.\n");
            }
        }
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("\nNo suppliers available.\n");
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    displaySupplier(suppliers[i]);
                }
            }
        }
        else if (choice == 3)
        {
            printf("\nEnter supplier name to search: ");
            fgets(searchName, sizeof(searchName), stdin);
            trimNewline(searchName);

            int result = searchSupplier(suppliers, count, searchName);

            if (result != -1)
            {
                printf("\nSupplier found.\n");
            }
            else
            {
                printf("\nSupplier not found.\n");
            }
        }
        else if (choice == 4)
        {
            if (count == 0)
            {
                printf("\nNo suppliers available.\n");
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    showNameLength(suppliers[i]);
                }
            }
        }
        else if (choice == 5)
        {
            printf("\nExiting program...\n");
            break;
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    printf("\n--- LAB TASK DEMOS ---\n");
    printf("Enter supplier name: ABC Office Supplies\n");
    printf("Enter email: sales@abc.com\n");
    printf("Enter phone: 0611234567\n");
    printf("Enter town: Windhoek\n");

    struct Supplier demo;
    strcpy(demo.name, "ABC Office Supplies");
    strcpy(demo.email, "sales@abc.com");
    strcpy(demo.phone, "0611234567");
    strcpy(demo.town, "Windhoek");

    displaySupplier(demo);
    showNameLength(demo);

    printf("\nEnter supplier name to search: Namibia Stationery\n");
    if (strcmp(demo.name, "Namibia Stationery") == 0)
    {
        printf("Supplier found.\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    copySupplierExample();
    buildSupplierDescription();

    return 0;
}
