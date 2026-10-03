#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n, key, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements (sorted for binary search):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);

    printf("\n1. Linear Search\n2. Binary Search\nEnter your choice: ");
    scanf("%d", &choice);

    int result;
    if (choice == 1) {
        result = linearSearch(arr, n, key);
        if (result == -1)
            printf("Element not found using Linear Search.\n");
        else
            printf("Element found at position %d using Linear Search.\n", result + 1);
    }
    else if (choice == 2) {
        result = binarySearch(arr, n, key);
        if (result == -1)
            printf("Element not found using Binary Search.\n");
        else
            printf("Element found at position %d using Binary Search.\n", result + 1);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}