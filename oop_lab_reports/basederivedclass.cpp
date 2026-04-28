#include <iostream>
using namespace std;

// Base class
class Person {
public:
    void showName() {
        cout << "Name: Rahul Bista" << endl;
    }
};

// Derived class
class Student : public Person {
public:
    void showRoll() {
        cout << "Roll No: 27" << endl;
    }
};

int main() {
    Student s;
    s.showName();   // inherited from base class
    s.showRoll();   // from derived class

    return 0;
}
