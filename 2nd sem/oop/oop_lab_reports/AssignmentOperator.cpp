#include <iostream>
#include <string>
using namespace std;

class CopyString
{
    private:
        string name;
    public:
    //copyString(const string &str=""):data(str) {}
    CopyString(const string str="")
    {
        name=str;
    }    
    CopyString operator=(const CopyString other)
    //CopyString *operator=(const &CopyString other)
    {
        if (this ->name==other.name) //if condition meet bayo bhane matra janxa tala else again goes up.so no need to put else (else works if u put )
        {
            return this -> name;
        }
        name=other.name;
        return this->name;//or 8(this) also fine 
    }
    void print()
    {
        cout << name <<endl;
    }

};
int main(void)
{
    CopyString s1("CYpher the KIng");
    CopyString s2;
    s2=s1;//calls operator=() dunction ,s1 copies to s2
    s2.print();
//operator overloading samma auxa exam ma
}