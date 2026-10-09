#include <iostream>

using namespace std;
class Multiplication
{
    public:
    int data;
    Multiplication (int data=0)
    {
        this->data=data;

    }
   // Multiplication operator() (cost Multiplication m);//check for multiplication operator()Multiplication m const
    Multiplication operator() (Multiplication m)const
    {
        this->data=this->data*m.data;
        return *(this);
    }
};
int main(void)
{
    Multiplication mul1,mul2,mul3;
    cout << "Enter data of mull1 and mul2" << endl;
    mul3=mul1(mul2);//calling the overload operator
    cout << "Result" << mul3.data << endl;

}