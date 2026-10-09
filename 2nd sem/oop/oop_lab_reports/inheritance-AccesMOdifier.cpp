//public,protected and private data members and functions
#include <iostream>
using namespace std;
class access
{
    //private:   //private data only can be accessed within the class
    int id;
    string name;
    public:
    void display()
    {
        id=101;
        name="Ram";
        cout << id << " and " << name << endl;
    }
};
class Derived: public access
{
    public:
    void display()
    {
        access::id=102;
        accessL:name="shyam";
        cout << access:: << "and" << access
    }
};

int main(void)
{
    // access am;
    // am.display();   

    

}