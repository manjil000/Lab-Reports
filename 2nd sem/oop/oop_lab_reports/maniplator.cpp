#include <iostream>
#include <iomanip>

using namespace std; 
int main(void)
{
    cout <<1 <<endl
         << 10 <<endl
         << 100 << endl
          << 1000 << endl; //by default left allignment
            //using setw(width) and setfill(char) manipulator
            cout << setw(5) << setfill('$') << 1 <<endl
                << setw(6) <<10<<endl
                << setw(7) << 100 << endl
                << setw(8) << 1000; 
}