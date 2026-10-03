#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Supplier {
    int supplier_id;
    char name[50];
    char address[100];
    int item_count;  // Number of different items supplied
};

struct Inventory {
    int item_id;
    char item_name[50];
    int supplier1_id;
    int supplier2_id;  // A max of two suppliers per item
};

// Function to add suppliers to file
void addSuppliers(const char *filename, int n) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Supplier s;
    for (int i = 0; i < n; i++) {
        printf("Enter Supplier ID, Name, Address, and Number of Items Supplied: ");
        scanf("%d", &s.supplier_id);
        scanf(" %[^\n]", s.name);
        scanf(" %[^\n]", s.address);
        scanf("%d", &s.item_count);
        fwrite(&s, sizeof(struct Supplier), 1, file);
    }
    fclose(file);
}

// Function to find suppliers with more than 10 different items
void findLargeSuppliers(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Supplier s;
    printf("\nSuppliers who supply more than 10 different items:\n");
    while (fread(&s, sizeof(struct Supplier), 1, file)) {
        if (s.item_count > 10) {
            printf("Supplier ID: %d, Name: %s, Address: %s\n", s.supplier_id, s.name, s.address);
        }
    }
    fclose(file);
}

int main() {
    const char *supplier_file = "supplier.dat";
    int n;

    printf("Enter number of suppliers: ");
    scanf("%d", &n);
    addSuppliers(supplier_file, n);

    // Find and display suppliers who supply more than 10 different items
    findLargeSuppliers(supplier_file);

    return 0;
}
