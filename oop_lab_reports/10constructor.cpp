#include <iostream>
using namespace std;

class Base {
    int baseVal;
public:
    Base(int val) : baseVal(val) {
        cout << "Base class constructor called, value: " << baseVal << endl;
    }
};

class Derived : public Base {
    int derivedVal;
public:
    Derived(int bVal, int dVal) : Base(bVal), derivedVal(dVal) {
        cout << "Derived class constructor called, value: " << derivedVal << endl;
    }
};

int main() {
    Derived obj(10, 20);

    return 0;
}
