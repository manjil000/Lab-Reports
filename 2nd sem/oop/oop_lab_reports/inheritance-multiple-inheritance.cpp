#include <iostream>
using namespace std;

class marks
{
    protected: //data are public but functions are protected
        int id;
        string name;
        int marks[3];
        public:
        int getData()
        {
            cout << "Enter the data" << endl;
            cin >> id >> name;
            cout << "Enter marks of 5 sub." << endl;
            for (int i=0;i<5;i++)
            {
                cout << "Marks[" << i <<"]:";
                cin >> marks[i];
            }
        }
};
class actmarks
{
    protected:
    int acmarks;
    public:
    void getAcMarks()
    {
        cout << "Enter activity mark out of 100" << endl;
        cin >> acmarks;
    }
};
class Fcalc:public marks,public actmarks //multiple inheritance
{
    public:
        int total=0;
        double per;
        double gettotal()
        {
            total =acmarks;
            for (int i=0;i<5;i++)
            {
                total +=marks[i];
            }
            return total;
        }
    double getPer()
{
    return (double)gettotal() /6;
} 
string getname()
{
    return name;
} 
string GPA()
{
    string aplus,a,bplus, 
}  
};
int main(void)
{
    Fcalc final;
    final.getData();
    final.getAcMarks();
    cout << final.getname() << " My total marks" << final.gettotal() << endl;
    cout <<final.getname() << "has Percemtage" << final.getPer() << endl;

}
