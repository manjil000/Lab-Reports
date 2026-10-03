#include <iostream>
using namespace std;

int area(int side)
{
    return side *  side;
}
int area(int length,int width)
{
    return length * length;
}
double area(double radius)
{
    return 3.1415 * radius * radius;
}
int main()
{
    cout << "Area of square(side=5): " << area(5) << endl;
    cout << "Area of rectangle(length=4,width=6): " << area(4,6) << endl;
    cout << "Area of circle(radius=3.5): " << area(3.5) <<endl;
    
    return 0;
}
