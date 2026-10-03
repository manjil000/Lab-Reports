#include <iostream>
using namespace std;
class student
{
    private:
        char name[20];
        char address[30];

    public:
        void student_getdata()
        {
            cout << "Enter anema nd address";
            cin >> name >> address;
        }    
       void student_putdata()
       {
        cout << "Name:"<<name<<endl;
        cout << "Address:"<<address;
       } 
};
class undergradstudent:public student{
    private:
    char faculty[5];
    public:
    void student_getrecord()
    {
        student::student_putdata();//function call
        cout << "\nfaculty:" << faculty;
    }
};
class graduateStudent:public student
{
    private:
    char faculty[5];
    char thesis_on[30];
    public:
    void student_getrecord()
    {
        student::student_getdata();//function call
        cout << "Enter ur faculty(eg MCCSIT/MBM/MCA)";
        cin >> faculty;
        cout << "Enter ur thesis subject";
        cin >> thesis_on;
    }
    void student_record_display()
    {
        student::student_putdata();//function call
        cout << "\nFaculty:" << faculty;
        cout << "\nThesis student:" << thesis_on;
    }
};
int main(void)
{
undergradstudent u_obj;
graduateStudent g_obj;
u_obj.student_getrecord();
u_obj.student_record_Display();
u_obj.
}
