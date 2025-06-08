#include <iostream>


using namespace std;

int xorOperation(int n, int start) {
    int result = start;
    for (int i = 1; i < n; ++i) {
        result ^= (start + (i << 1));
    }

    return result;
}

int main() {
    cout << xorOperation(5, 0) << endl;
    cout << xorOperation(4, 3) << endl;
    cout << xorOperation(1, 7) << endl;
    cout << xorOperation(10, 5) << endl;
    return 0;
}