#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int num[n + 1];
    num[0] = 0;
    num[1] = 1;
    for (int i = 2; i <= n; ++i) {
        num[i] = num[i - 1] + num[i - 2];
    }
    return num[n];
}

int main() {
    cout << fib(0) << endl;
    cout << fib(1) << endl;
    cout << fib(3) << endl;
    cout << fib(30) << endl;
    return 0;
}
