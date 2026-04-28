#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() { // Function overridden
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog d;
    d.sound();  // Calls derived class version

    Animal a;
    a.sound();  // Calls base class version

    return 0;
}
