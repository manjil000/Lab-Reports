#include <iostream>
using namespace std;

class Person{
    public:
    int id;
    string name;
    float marks;
    Person()//is called when objects are created
    {
        cout << "Memory allocation" <<endl;
    }
    ~Person()//is called when objects are deleted 
    {
        cout << "Memory deallocation" << endl;
    }

};
int main()
{
    Person p[5];//compile time mem allocation in stack memeory
    Person *ptr=new Person[5];//runtime memory allocation in heap memory
        delete[] ptr;//it deltes the array of pointer
}