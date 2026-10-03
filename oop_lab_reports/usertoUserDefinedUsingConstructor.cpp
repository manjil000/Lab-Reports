#include <iostream>
using namespace std;

class Minutes
{
    public:
        int minutes;
        Minutes(int minutes=0)
        {
            this -> minutes=minutes;
        }
        int getMinute()
        {
            return minutes;
        }
};
class Hours
{
    public:
    int hours;
    Hours(int hours=0)
    {
        this -> hours=hours;
    }
     Hours(Minutes m)
        {
            this -> hours=m.getMinute() / 60;
        }
        void display()
        {
            cout << "hours=" << hours <<endl;
        }
};
int main(void)
{
    Hours h;
    Minutes m(234);
    h=m;
    h.display();
}