#include <iostream>
using namespace std;

class Employee {
    int id;
    string name;
    float salary;

public:
    // Default constructor
    Employee() {
        id = 0;
        name = "Not Assigned";
        salary = 0.0;
    }

    // Constructor with ID and Name
    Employee(int i, string n) {
        id = i;
        name = n;
        salary = 0.0;
    }

    // Constructor with all parameters
    Employee(int i, string n, float s) {
        id = i;
        name = n;
        salary = s;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << endl;
    }
};

int main() {
    Employee e1;
    Employee e2(101, "Bob");
    Employee e3(102, "Charlie", 55000.75);

    cout << "Using Constructor Overloading:\n";
    e1.display();
    e2.display();
    e3.display();

    return 0;
}
