#include <iostream>
using namespace std;

class Employee {
    int id;
    string name;
    float salary;

public:
    void setData(int i, string n, float s) {
        id = i;
        name = n;
        salary = s;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << endl;
    }
};

int main() {
    Employee e1, e2, e3;

    e1.setData(101, "Alice", 50000);
    e2.setData(102, "Bob", 55000);
    e3.setData(103, "Charlie", 60000);

    cout << "Employee Details:\n";
    e1.display();
    e2.display();
    e3.display();

    return 0;
}
