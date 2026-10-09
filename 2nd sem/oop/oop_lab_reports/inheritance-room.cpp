#include <iostream>
using namespace std;

class Room{
    protected:
        int l,b;
        Room(int l,int b) //what is this called? ==> it's construnctor
        {
            this -> l=l;
            this -> b=b;
        }
        //this(instance) means current class jun class ma use bhako xa tesma refer hunxa.
        int area()
        {
            return l*b;
        }

};
class kitchen:public Room{
    public:
    int height;
    kitchen(int l,int b,int h):Room(l,b)
    {
        this -> height =height;
    }
    int volume()
    {
        return l*b*height;

    }
};
int main(void)
{
    kitchen kroom(3,4,5);
    cout << "Area=" << kroom.area() <<end;
    cout << 
}