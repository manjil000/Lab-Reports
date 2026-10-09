#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float salary;
};

void writeEmployeeData(const char *filename, int n) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    struct Employee emp;
    for (int i = 0; i < n; i++) {
        printf("Enter Employee ID, Name, Designation, and Salary: ");
        scanf("%d", &emp.emp_id);
        scanf(" %[^\n]", emp.name);
        scanf(" %[^\n]", emp.designation);
        scanf("%f", &emp.salary);
        fwrite(&emp, sizeof(struct Employee), 1, file);
    }
    fclose(file);
}

void readEmployeeData(const char *filename, struct Employee employees[], int *n) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    *n = 0;
    while (fread(&employees[*n], sizeof(struct Employee), 1, file)) {
        (*n)++;
    }
    fclose(file);
}

void sortEmployees(struct Employee employees[], int n) {
    struct Employee temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employees[j].emp_id > employees[j + 1].emp_id) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void displayEmployees(struct Employee employees[], int n) {
    printf("\nEmployee Records Sorted by Employee ID:\n");
    printf("ID\tName\t\tDesignation\tSalary\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%.2f\n", employees[i].emp_id, employees[i].name, employees[i].designation, employees[i].salary);
    }
}

int main() {
    const char *filename = "employee.dat";
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    writeEmployeeData(filename, n);

    struct Employee employees[n];
    readEmployeeData(filename, employees, &n);
    sortEmployees(employees, n);
    displayEmployees(employees, n);

    return 0;
}
