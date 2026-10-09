#include<iostream>
using namespace std;

struct Emlyoee{
    int a,b;//dufault public

};
class Student{
    public:
    int a,b;//default private

};
typedef struct Employee EMP;
typedef Student STUD;
int main(void)
{
    EMP emp;
    STUD st;
    emp.a=24;
    emp.b=35;
    st.a=45;
    st.b=56;
}