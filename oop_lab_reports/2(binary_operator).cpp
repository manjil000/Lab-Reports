#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v = 0) : value(v) {}

    // Arithmetic: +
    Number operator+(const Number &n) const {
        return Number(value + n.value);
    }

    // Comparison: ==
    bool operator==(const Number &n) const {
        return value == n.value;
    }

    // Assignment: =
    Number& operator=(const Number &n) {
        value = n.value;
        return *this;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number a(10), b(20), c;

    c = a + b;  // arithmetic
    cout << "After a + b: ";
    c.display();

    cout << "Are a and b equal? ";
    cout << (a == b ? "Yes" : "No") << endl; // comparison

    Number d;
    d = c;  // assignment
    cout << "After assignment d = c: ";
    d.display();

    return 0;
}
