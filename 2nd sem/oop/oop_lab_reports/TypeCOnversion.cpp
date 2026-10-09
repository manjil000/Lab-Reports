#include <iostream>
using namespace std;
namespace semseter2
    {
    void oop()
    {
        cout << "WE STUDY C++ AS OOP" <<endl;
        
    }
};
namespace semseter7
    {
    void oop()
    {
        cout << "WE STUDY jss as oop" <<endl;
        
    }
};
int main(void)
{
    semseter2::oop();//function is visible using scope resolution operator;//eutai name ko diif folder rakhna mildaina
    semseter7::oop();//function is visible using scope resolution operator;

}