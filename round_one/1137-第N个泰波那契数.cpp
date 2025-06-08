#include <iostream>

using namespace std;

int tribonacci(int n) {
    if (0 == n) {
        return 0;
    }

    if (n <= 2) {
        return 1;
    }

    /*
    int tri[n + 1];
    tri[0] = 0;
    tri[1] = 1;
    tri[2] = 1;
    for (int i = 3; i <= n; ++i) {
        tri[i] = tri[i - 1] + tri[i - 2] + tri[i - 3];
    }

    return tri[n];
    */
    int p = 0, q = 0, r = 1, s = 1; 
    for (int i = 3; i <=n; ++i) {
        p = q;
        q = r;
        r = s;
        s = p + q + r;
    }
    
    return s;
}

int main() {
    cout << tribonacci(4) << endl;
    cout << tribonacci(5) << endl;
    cout << tribonacci(37) << endl;
    cout << tribonacci(2) << endl;
    return 0;
}