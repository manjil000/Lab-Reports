#include <iostream>
using namespace std;

double finalprice(double price,double taxrate=0.1)
{
    return price + (price * taxrate);
}
int main()
{
    double amnt;

    cout << "Enter the base Price: ";
    cin >> amnt;

    cout << "Final price (default tax 10%): " << finalprice(amnt) << endl;
    cout << "FInal price (custom tax 5%): " << finalprice(amnt,0.05) << endl;
    return 0;
}