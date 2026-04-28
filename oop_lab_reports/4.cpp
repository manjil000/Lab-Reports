#include <iostream>
using namespace std;

class Distance {
    int meters;
public:
    // Constructor: converts int to Distance
    Distance(int m) {
        meters = m;
    }

    void show() {
        cout << "Distance: " << meters << " meters" << endl;
    }
};

int main() {
    int d = 100;

    // Basic to User-defined: int → Distance
    Distance dist = d;  // invokes constructor

    dist.show();

    return 0;
}
