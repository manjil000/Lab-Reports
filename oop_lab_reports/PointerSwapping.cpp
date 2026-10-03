#include <iostream>
using namespace std;

// Pass by reference
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Pass by pointer
void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    int p = 30, q = 40;

    cout << "Before swapByReference: x = " << x << ", y = " << y << endl;
    swapByReference(x, y);
    cout << "After swapByReference:  x = " << x << ", y = " << y << endl;

    cout << "\nBefore swapByPointer: p = " << p << ", q = " << q << endl;
    swapByPointer(&p, &q);  // Pass addresses
    cout << "After swapByPointer:  p = " << p << ", q = " << q << endl;

    return 0;
}
