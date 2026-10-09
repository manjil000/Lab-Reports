#include <iostream>
using namespace std;

class Student
{
    public:
    virtual void display() =0; //pure virtual function student class is
};
class studentVedas :public student:
{
    public:
    void display()
    {
        cout << "I am ambition Student" << endl;
    }
};
int main(void)
{
    Student *p1,new Student(); //refrence
    
    //Student stobj;//object
    StudentVedas sv;
    StudentAmbition sa;
    p1=&sv;
    p1->display();
    p1=&sa;
}
//virtual le function lie call  nahune banauxa  


class StudentVedas : public Student{
    void
}