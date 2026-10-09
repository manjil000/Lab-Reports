//user to user defined conversion details with the conversion of one object into another object;
//objx=objy
//1. using object casting function
//2. Using constructor
#include <iostream>
using namespace std;
class Hour //Destination Class
{
    public:
        int hours;
        Hour(int hours=0) //default constructor 
        {
            this -> hours =hours;
        }
        void display()
        {
            cout << " Hours=" <<hours<<endl;
        }
};
class Minutes
{
    public:
     int minutes;
     Minutes(int minutes=0)
     {
        this -> minutes=minutes;
     }
     operator Hour()//it converts minute into hours
     {
        Hour temp;
        temp.hours=minutes/60;
        return Hour(temp.hours);
     }
};
int main(void)
{
    Hour h;
    Minutes m(324);
    h=m;//object m is converted into object h, it calls casting function operator HOur()
    h.display(); 

}

