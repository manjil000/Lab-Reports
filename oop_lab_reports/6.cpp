#include <iostream>
using namespace std;

class Centimeter; // Forward declaration

class Meter {
    float m;
public:
    Meter(float val = 0) : m(val) {}

    float getMeter() const {
        return m;
    }

    // Conversion function: Meter → Centimeter
    operator Centimeter();
};

class Centimeter {
    float cm;
public:
    Centimeter(float val = 0) : cm(val) {}

    void show() {
        cout << "Distance: " << cm << " cm" << endl;
    }

    // Allow Meter class to access private members
    friend class Meter;
};

// Define conversion outside Meter
Meter::operator Centimeter() {
    return Centimeter(m * 100);
}

int main() {
    Meter m(2.5);          // 2.5 meters
    Centimeter c = m;      // Converted to centimeters

    c.show();              // Output: 250 cm

    return 0;
}
