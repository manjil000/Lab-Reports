#include <iostream>
using namespace std;

int main() {
    int *arr = new int[10];  // Dynamically allocate memory for 10 integers

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Simple Bubble Sort
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted integers:\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Free the memory

    return 0;
}
