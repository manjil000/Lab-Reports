#include <iostream>
using namespace std;

class Sample {
    int data;
public:
    Sample(int d = 0) : data(d) {}

    void display() {
        cout << "Data: " << data << endl;
    }

    // Passed by value
    void updateByValue(Sample s) {
        s.data += 10;
        cout << "[By Value] Updated Data inside function: " << s.data << endl;
    }

    // Passed by reference
    void updateByReference(Sample &s) {
        s.data += 10;
        cout << "[By Reference] Updated Data inside function: " << s.data << endl;
    }

    // Passed by pointer
    void updateByPointer(Sample *s) {
        s->data += 10;
        cout << "[By Pointer] Updated Data inside function: " << s->data << endl;
    }
};

int main() {
    Sample a(5), b(5), c(5);

    Sample updater;
    updater.updateByValue(a);
    cout << "After By Value: ";
    a.display();  // unchanged

    updater.updateByReference(b);
    cout << "After By Reference: ";
    b.display();  // changed

    updater.updateByPointer(&c);
    cout << "After By Pointer: ";
    c.display();  // changed

    return 0;
}
