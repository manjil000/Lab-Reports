#include <iostream>
using namespace std;

class number{
    public:
        int data;
        void display(){
            cout << "The sum of 2 objects=" << data <<endl;
        }
        number* operator+(number nobj)
        {
            this->data=this->data + nobj.data;//jasle call garxa tyo this data hunxa
            return *(this);
        }

};
int main(void)
{
    number n1,n2,*n3;
    n1.data=24;
    n2.data=36;
    n3=n1-n2;//compiler  treat as n1.operaor +(n2)
    //n1.add(n2);
    n3->display()
}