#include <iostream>

using namespace std;

class Marks
{
    int marks;
    public:
    Marks(int marks=0)
    {
        this->marks=marks;
    }
};
void operator++() //japendra lama hai mero nam hai
{
    cout << "Pre increment marks=" << ++marks <<endl;
}
void operator++(int)
{
    cout << "Post increment marks=" << ++marks <<endl;
}

int main(void)
{
    Marks m;
    ++m;//pre increment marks=1
    Marks m1(10);
    m1++;//post increment marks=10
    ++m1;//?   
}