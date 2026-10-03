#include <iostream>
#include <math.h>
using namespace std;
//1)pass object as a value in funct-> and return object
//2)pass objects as a reference in func->
//3)Pass objects as a pointer in a func->

//for no 1)

class Time
{
    public: //by defaukt private hunxa
    int h,m,s;
    Time& difference(Time&,Time&); //returns object of a certain class return objects of same class->
    Time* difference(Time*,Time*);//prototype
    void displayTime(); //prototype
};
    //(time bhanne class) ::=>scope resolution operator->
Time *Time::difference(Time* t1,Time* t2)


{
    Time *t3=new Time();//memory created at execution or run time
    int s1=t1->h*3600+t1->m*60+t1->s;
    int s2=t2->h*3600+t2->m*60+t2->s;
    int dsec=abs(s1-s2);
    t3->h=dsec/3600;//hours
    int remsec=dsec%3600;//remaining seconds
    t3.m=remsec/60;
    t3->=remsec%60;
    return t3;
}
void Time::displayTime()
{
    cout <<h<<"hrs:"<<m<<"min:"<<s<<"sec:"<<endl;
}
int main(void)
{
Time t1,t2,t3;
Time *temp=new Time();
cout <<"Enter the hour,min and seconds of t1"<<endl;
cin >>t1.h>>t1.m>>t1.s;
cout <<"Enter the hour,min and seconds of t2"<<endl;
cin >>t2.s>>t2.m>>t2.s;

t3=t3->difference(t1,t2);
t3.displayTime();
}