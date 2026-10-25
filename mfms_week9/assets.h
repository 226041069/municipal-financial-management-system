#include <stdio.h>
#include <string.h>

#include "suppliers.h"
#include "utilities.h"

void addSupplier(Supplier *supplier)
{
    supplier->id = inputInt("Enter supplier ID: ");
    readString("Enter supplier name: ", supplier->name, sizeof(supplier->name));
    readString("Enter supplier email: ", supplier->email, sizeof(supplier->email));
    readString("Enter supplier phone: ", supplier->phone, sizeof(supplier->phone));
    readString("Enter town: ", supplier->town, sizeof(supplier->town));
}

void displaySupplier(const Supplier *supplier)
{
    printf("Supplier ID: %d\n", supplier->id);
    printf("Name: %s\n", supplier->name);
    printf("Email: %s\n", supplier->email);
    printf("Phone: %s\n", supplier->phone);
    printf("Town: %s\n", supplier->town);
}

int saveSuppliersText(const char *filename, const Supplier suppliers[], int count)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        perror("Error opening suppliers file for writing");
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d|%s|%s|%s|%s\n",
                suppliers[i].id,
                suppliers[i].name,
                suppliers[i].email,
                suppliers[i].phone,
                suppliers[i].town);
    }

    fclose(fp);
    return 1;
}

int loadSuppliersText(const char *filename, Supplier suppliers[], int *count)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        perror("Error opening suppliers file for reading");
        return 0;
    }

    *count = 0;
    while (*count < 100 && fscanf(fp, "%d|%49[^|]|%59[^|]|%19[^|]|%29[^|\n]\n",
                                  &suppliers[*count].id,
                                  suppliers[*count].name,
                                  suppliers[*count].email,
                                  suppliers[*count].phone,
                                  suppliers[*count].town) == 5)
    {
        (*count)++;
    }

    fclose(fp);
    return 1;
}
