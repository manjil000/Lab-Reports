#include <iostream>
using namespace std;

class Demo {
    int id;
public:
    Demo(int i) {
        id = i;
        cout << "Constructor called for ID: " << id << endl;
    }

    ~Demo() {
        cout << "Destructor called for ID: " << id << endl;
    }

    void show() {
        cout << "Object ID: " << id << endl;
    }
};

int main() {
    Demo d1(1);
    {
        Demo d2(2);  // Local scope
        d2.show();
    } // d2 is destroyed here

    d1.show();

    return 0; // d1 is destroyed here
}
