#include <iostream>
using namespace std;

class Distance {
    int meters;
public:
    Distance(int m = 0) : meters(m) {}

    // Type conversion function: Distance → int
    operator int() {
        return meters;
    }

    void show() {
        cout << "Distance: " << meters << " meters" << endl;
    }
};

int main() {
    Distance dist(150);

    int d = dist;  // invokes operator int()
    cout << "Converted to int: " << d << " meters" << endl;

    return 0;
}
