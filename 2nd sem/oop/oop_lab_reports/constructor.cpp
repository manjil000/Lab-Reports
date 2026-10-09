#include <iostream>
using namespace std;
class shape
{
    int length,breath;
}
shape(int 1, int b)//parameterized contructor
{

int area()
{
    return lenth * breadth;
}
};

int main(void)
{
    shape noshape; //object->calls default constructor
    shape rectangle(20,40);
    cout << "Area of noshape" << noshape.area()<<endl;
    cout << "Area of rectangle" << rectangle.area()<<endl;

}
/*Constructor:It is a function having same name as class name. It is used to create objects of a class. Mainly it is used to initialize 
the instance variables. There are basically 3 types of constructors ,1.default 2. Parameterized and 3.COpy constructior(default and user defined)
 */