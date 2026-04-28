#include <iostream>
using namespace std;

class Counter {
    static int count;  // static data member
public:
    Counter() {
        count++;
    }

    // Static member function
    static void showCount() {
        cout << "Count: " << count << endl;
    }
};

// Initialize static member
int Counter::count = 0;

int main() {
    Counter c1, c2, c3;

    // Call static function without object
    Counter::showCount();

    return 0;
}
