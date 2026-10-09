#include <iostream>
using namespace std;

class Employee {
    int id;
    string name;

public:
    // Default constructor
    Employee() {
        id = 0;
        name = "Unknown";
    }

    // Parameterized constructor
    Employee(int i, string n) {
        id = i;
        name = n;
    }

    // Copy constructor
    Employee(const Employee &e) {
        id = e.id;
        name = e.name;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    Employee e1;                     // Default
    Employee e2(101, "Alice");       // Parameterized
    Employee e3 = e2;                // Copy

    cout << "Default Constructor:\n";  e1.display();
    cout << "Parameterized Constructor:\n";  e2.display();
    cout << "Copy Constructor:\n";  e3.display();

    return 0;
}
