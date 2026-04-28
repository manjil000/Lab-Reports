#include <iostream>
using namespace std;

class Base {
public:
    void publicMethod() {
        cout << "Base public method" << endl;
    }
protected:
    void protectedMethod() {
        cout << "Base protected method" << endl;
    }
};

// Public Inheritance
class PublicDerived : public Base {
public:
    void accessBase() {
        publicMethod();      // ✅ allowed
        protectedMethod();   // ✅ allowed
    }
};

// Private Inheritance
class PrivateDerived : private Base {
public:
    void accessBase() {
        publicMethod();      // ✅ allowed
        protectedMethod();   // ✅ allowed
    }
};

int main() {
    PublicDerived pubObj;
    pubObj.accessBase();     // ✅ allowed
    pubObj.publicMethod();   // ✅ allowed (inherited as public)

    PrivateDerived privObj;
    privObj.accessBase();    // ✅ allowed
    // privObj.publicMethod(); // ❌ Error: inherited as private

    return 0;
}
