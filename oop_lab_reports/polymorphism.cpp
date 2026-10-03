#include <iostream>
using namespace std;

class Distance
{
    private:
    int meter;

    //friend function
    friend int addFive(Distance);//this is not defination it's a parameter and also object of distance
    //function lie outside the scope then use scope rwsolution operator.

};