#include <iostream>

using namespace std;
class Complex
{
    public:
        int real,img;
        void getData()
        {
            cout << "Enter the values of real and imaginary" << endl;
            cin >> real >> img;
        }
        void display()
        {
            cout << "(" << real << "+" << img << "i)" << endl;
        }
        Complex &addComplex(Complex &c)//what if cost COnst &c
        {
            c.real=real +c.real;
            c.img=img + c.img;
            return c;
        }
        Complex *addComplex (const Complex *c)
        {
            cout << "I am this pointer" << endl;
            this -> real=real +c->real;
            this -> img =img +c->img;
            return this; 
        }   
        Complex *addComplex( Complex *c)
        {
            cout << " I am not this pointer" << endl;
            c->real=real +c-> real;
            c-> img =img +c -> img;
            return c;
        }
};
int main(void)
{
    Complex c1,c2,c3;
    Complex *temp=new Complex();
    c1.getData();
    c2.getData();
    temp=c2.addComplex(&c1);
    cout << "Addition of 2 complex number 1s:"<< endl;
    temp->display();
}