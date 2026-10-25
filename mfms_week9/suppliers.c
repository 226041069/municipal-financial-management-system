#ifndef SUPPLIERS_H
#define SUPPLIERS_H

typedef struct {
    int id;
    char name[50];
    char email[60];
    char phone[20];
    char town[30];
} Supplier;

void addSupplier(Supplier *supplier);
void displaySupplier(const Supplier *supplier);
int saveSuppliersText(const char *filename, const Supplier suppliers[], int count);
int loadSuppliersText(const char *filename, Supplier suppliers[], int *count);

#endif
