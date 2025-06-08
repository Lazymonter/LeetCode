/*
前缀和
二分查找
滑动窗口
*/
#include <iostream>
#include <algorithm>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

// 二分查找
int longestOnes_s(vector<int> &A, int K) {
    int len = A.size();
    vector<int> d(len + 1, 0);
    for (int i = 1; i <= len; i++) {
        d[i] = d[i - 1] + (1 - A[i - 1]);
    }

    int ret = 0;
    for (int right = 0; right < len; right++) {
        int left = lower_bound(d.begin(), d.end(), d[right + 1] - K) - d.begin();
        ret = max(ret, right -left + 1);
    }

    return ret;
}

// 滑动窗口
int longestOnes(vector<int> &A, int K) {
    int len = A.size();
    int left = 0, lsum = 0, rsum = 0;
    int ret = 0;

    for (int right = 0; right < len; right++) {
        rsum += 1 - A[right];
        while (lsum < rsum - K) {
            lsum += 1 - A[left];
            ++left;
        }

        ret = max(ret, right - left + 1);
    }
    return ret;
}

int main() {
    vector<int> A = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << longestOnes(A, 3) << endl;
    cout << longestOnes_s(A, 3) << endl;
    return 0;
}