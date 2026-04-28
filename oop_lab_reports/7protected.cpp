#include <iostream>
using namespace std;

class Base {
protected:
    int protectedValue;
public:
    void setValue(int val) {
        protectedValue = val;
    }
};

// Derived class accessing protected member
class Derived : public Base {
public:
    void show() {
        cout << "Protected value from Base: " << protectedValue << endl;
    }
};

int main() {
    Derived obj;
    obj.setValue(42);
    obj.show();

    // obj.protectedValue = 10; // ❌ Error: cannot access protected member from main()

    return 0;
}
