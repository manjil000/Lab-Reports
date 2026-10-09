#include <iostream>
using namespace std;

class library
{
    private:
    int no_of_books;
    public:
    library()
    {
        no_of_books=500;
    }
    friend class librian;
    friend class student;
};
class librian
{
    public:
    void function1(library)
    {
        cout << "Your data is:" << l.no_of_books; //private member accessible

    }
};
int main(void)
{
    library l1;
    librian l;
    student s;
    s.function1(11);
    l.function1(11);

}