#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Declare friend function
    friend void printLength(const Box &b);

    // Declare friend class
    friend class BoxPrinter;
};

// Friend function definition
void printLength(const Box &b) {
    cout << "Friend function: Length = " << b.length << endl;
}

// Friend class definition
class BoxPrinter {
public:
    void displayLength(const Box &b) {
        cout << "Friend class: Length = " << b.length << endl;
    }
};

int main() {
    Box box(10);

    printLength(box);        // Access private member via friend function

    BoxPrinter printer;
    printer.displayLength(box);  // Access private member via friend class

    return 0;
}
