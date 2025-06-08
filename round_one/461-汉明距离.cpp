#include <iostream>

using namespace std;


int hammingDistance(int x, int y) {
    int a = x ^ y;
    int cnt = 0;
    while (a) {
        a = a & (a - 1);
        ++cnt;
    }

    return cnt;
}

int main() {
    cout << hammingDistance(1, 4) << endl;
    return 0;
}