//Agregration is also a relationship between 2 classes or objects in which 1 objects has a relationship with aother object object. E.g student has a address,emplyee has a dob and so on.

#include <iostream>
using namespace std;
class Address 
{
    public:
    Address(){}
    string city,state,country;
    Address(string city,string state,string country)
    {
        this->city=city;
        this -> state=state;
        this -> country=country;
    }
};
class student
{
    public:
    Address add;
    string name;
    int roll;
    student() {}//default constructor
    student(Address add,string name,int roll)
    {
        this -> add=add;
        this ->name=name;
        this ->roll=roll;
    }
    void display()
    {
        cout << "Student Roll" << "\t" << "Student Name" << "\t" << "studemt city " <<"\tstudent state" << "\t student country" << endl;
        cout << roll << "\t" << name << "\t" << add.city<<"\t"<< add.state << "\t" << "\t" << add.country <<endl; 
    }
};

int main(void)
{
    Address add("Kathmandu","Bagmati" , "Nepal");
    student st(add,"Ram",23);
    st.display();
}
