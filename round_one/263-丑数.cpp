#include <iostream>
#include <vector>


using namespace std;

bool isUgly(int n) {
    if (n <= 0) return false;

    vector<int> vec = {2, 3, 5};

    for (auto &v : vec) {
        while (n % v == 0) {
            n /= v;
        }
    }

    return 1 == n;
}


int main() {
    int n1 = 6, n2 = 8, n3 = 14, n4 = 1, n5 = 7;

    cout << isUgly(n1) << endl;
    cout << isUgly(n2) << endl;
    cout << isUgly(n3) << endl;
    cout << isUgly(n4) << endl;
    cout << isUgly(n5) << endl;
    
    return 0;
}