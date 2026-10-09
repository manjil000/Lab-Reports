#include <stdio.h>
using namespace std;

class logical
{
public:
bool status;
logical (bool status)
{
    this -> status=status;
}
bool operator&&(logical lo)//operatoe Overloading function
{
    if (status && lo.status)
        return true;
    else
    return false;

}
};
int main(void)
{
    logical l1(true),l2(false);
    if (11 && 12)
        cout << "Condition sis true" << endl;
    else
        cout <<"Condition is false" << endl;
}