#include <iostream>
using namespace std;
class Bank
{
    private:
    int accountnumber=123466;
    friend void accessAcNumber(Bank);
    public:
    Bank():accountnumber(0)

};
void accessAcNumber(Bank b)
{
    cout << "Account numer=" << b.accountnumber <<endl;
}