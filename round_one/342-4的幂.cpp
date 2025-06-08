#include <iostream>

using namespace std;

bool isPowerOffFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
}


int main() {
    cout << isPowerOffFour(0) << endl;
    cout << isPowerOffFour(1) << endl;
    cout << isPowerOffFour(2) << endl;
    cout << isPowerOffFour(3) << endl;
    cout << isPowerOffFour(4) << endl;
    cout << isPowerOffFour(32) << endl;
    return 0;
}