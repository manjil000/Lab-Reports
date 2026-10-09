#include <stdio.h>

int main() {
    int arr[10], i, key, found = 0;

    // Input 10 numbers
    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Search element
    for (i = 0; i < 10; i++) {
        if (arr[i] == key) {
            found = 1;
            printf("Element found at position %d\n", i + 1);
            break;
        }
    }

    // If element is not found
    if (!found)
        printf("Element not found\n");

    return 0;
}
