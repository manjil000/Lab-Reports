#include <iostream>
using namespace std;

class Counter {
    int value;
public:
    Counter(int v = 0) : value(v) {}

    // Prefix ++
    Counter operator++() {
        ++value;
        return *this;
    }

    // Postfix ++
    Counter operator++(int) {
        Counter temp = *this;
        value++;
        return temp;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c(5);

    cout << "Initial: ";
    c.display();

    ++c; // prefix
    cout << "After prefix ++: ";
    c.display();

    c++; // postfix
    cout << "After postfix ++: ";
    c.display();

    return 0;
}
