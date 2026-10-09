#include <iostream>
using namespace std;
void counter()
{
    //external euta variable to next files
static int count =0; //run this code with and without static and see the diff
cout << "Counter=" << ++count << endl;

}
int main()
{
    counter();
    counter();
    counter();
}