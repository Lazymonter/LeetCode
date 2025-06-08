/*
数组
*/

#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int> &A) {
    int len = A.size();
    if (1 == len) return true;
    int pre = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (A[i] == A[i + 1]) {
            continue;
        }

        int cur = (A[i] > A[i + 1] ? 1 : 2);
        if (pre == 0 || pre == cur) {
            pre = cur;
        } else {
            return false;
        }

    }
    return true;
}

bool isMonotonic_s(vector<int> &A) {
    bool inc = true, dec = true;
    for (int i = 0; i < A.size() - 1; ++i) {
        if (A[i] > A[i + 1]) {
            inc = false;
        }

        if (A[i] < A[i + 1]) {
            dec = false;
        }
    }

    return inc || dec;
}


int main() {
    vector<int> A = {1,3, 2}, B = {6,5,4,4}, C = {1}, D = {2,2,2,2}, E = {1,1,0};
    cout << isMonotonic(A) << endl;
    cout << isMonotonic(B) << endl;
    cout << isMonotonic(C) << endl;
    cout << isMonotonic(D) << endl;
    cout << isMonotonic(E) << endl;
    return 0;
}

