#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int no=255;
    double pi=3.1415;

    cout << "Normal Output \n";
    cout << "Number: "<< no <<endl;
    cout << "Pi: " << pi << endl;

    cout << "\nUsing manipulators:\n";

    cout << "Hexadecimal: " << hex << no << endl;
    cout << "Octal: "<<  oct << no << endl;
    cout << "Decimal: "<< dec << no << endl;

    //cout <<;
    cout << "pi (2 decimal places): " << fixed << setprecision(2) << pi << endl;
 
    cout << setw(20) << no << "<--- setw(10) adds spacing" << endl;

    return 0;
}