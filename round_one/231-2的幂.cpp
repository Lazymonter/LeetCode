/*
2的幂的二进制表示中只有一个1
*/
#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    cout << isPowerOfTwo(1) << endl;
    cout << isPowerOfTwo(2) << endl;
    cout << isPowerOfTwo(3) << endl;
    cout << isPowerOfTwo(5) << endl;
    cout << isPowerOfTwo(-1) << endl;
    return 0;
}