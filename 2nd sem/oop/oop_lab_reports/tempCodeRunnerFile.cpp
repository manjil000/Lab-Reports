#include <iostream>
using namespace std;

class Counter {
    int count;
public:
    Counter(int c = 0) : count(c) {}

    void display() {
        cout << "Count: " << count << endl;
    }

    // Return by reference
    Counter& increment() {
        ++count;
        return *this;
    }

    // Return by pointer (new object)
    static Counter* createCopy(const Counter &c) {
        return new Counter(c.count);
    }
};

int main() {
    Counter a(5);

    // Return by reference
    a.increment().increment(); // Chaining calls
    cout << "After chaining reference returns: ";
    a.display();

    // Return by pointer
    Counter* b = Counter::createCopy(a);
    cout << "Copy created using pointer: ";
    b->display();

    delete b; // Clean up

    return 0;
}
