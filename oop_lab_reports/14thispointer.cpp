#include <iostream>
using namespace std;

class Box {
    int length;
public:
    Box(int length) {
        // Use this pointer to distinguish member from parameter
        this->length = length;
    }

    void display() {
        cout << "Length = " << this->length << endl;
    }
};

int main() {
    Box b(15);
    b.display();

    return 0;
}
