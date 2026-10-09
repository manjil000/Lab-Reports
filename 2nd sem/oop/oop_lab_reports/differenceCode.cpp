#include <iostream>
using namespace std;

int main()
{
    char charArray[100];
    string str;

    cout << "Enter a word  using cin: ";
    string word;

    cin >> word;
    cin.ignore();

    cout << "Enter a line using getline";
    getline(cin,str);

    cout << "Enter another line Using cin.getline";
    cin.getline(charArray,100);

    cout << "\n You entered(cin): " << word <<endl;
    cout << "\n You entered(getline): "<< str << endl;
    cout << "\nyou entered (cin.getline)" << charArray << endl;

    return 0;
}