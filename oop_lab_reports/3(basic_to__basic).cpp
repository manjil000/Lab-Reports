#include <iostream>
using namespace std;

int main() {
    int i = 10;
    float f;

    // Basic to Basic: int to float
    f = static_cast<float>(i);
    cout << "Integer: " << i << " → Float: " << f << endl;

    // Basic to Basic: float to int
    f = 25.78;
    i = static_cast<int>(f);
    cout << "Float: " << f << " → Integer: " << i << endl;

    return 0;
}
