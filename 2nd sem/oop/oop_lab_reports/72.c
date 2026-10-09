#include <stdio.h>
#include <string.h>

void sortNames(char names[50][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main() {
    char names[50][100];
    int n;

    printf("Enter number of students (max 50): ");
    scanf("%d", &n);
    getchar(); // To consume newline character

    printf("Enter names of %d students:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(names[i], 100, stdin);
        names[i][strcspn(names[i], "\n")] = 0; // Remove newline character
    }

    sortNames(names, n);

    printf("\nNames in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
