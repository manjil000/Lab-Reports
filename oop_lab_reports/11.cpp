#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    void info() {
        cout << "This is a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    // Shape s; // ❌ Error: cannot instantiate abstract class

    Circle c;
    c.info();    // inherited normal function
    c.draw();    // overridden pure virtual function

    return 0;
}

