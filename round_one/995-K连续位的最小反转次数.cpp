/*
差分数组
滑动窗口
模2加减法等价于异或
*/

#include <iostream>
#include <vector>

#include "utils/myutil.hpp"
using namespace std;

// 差分数组
int minKBitFlips_s(vector<int> &A, int K) {
    int len = A.size(), ans = 0, revCnt = 0;
    vector<int> diff(len +1);
    for (int i = 0; i < len; ++i) {
        revCnt ^= diff[i];
        if (A[i] == revCnt) {
            if (i + K > len) {
                return -1;
            }
            ++ans;
            revCnt ^= 1;
            diff[i + K] ^= 1;
        }
    }

    return ans;
}

// 滑动窗口
int minKBitFlips(vector<int> &A, int K) {
    int len = A.size(), ans = 0, revCnt = 0;
    for (int i = 0; i < len; i++) {
        if (i >= K && A[i - K] > 1) {
            revCnt ^= 1;
            //A[i - K] -= 2; // 此种写法会导致最后一组未还原
        }

        if (A[i] == revCnt) {
            if (i + K > len) {
                return -1;
            }
            ++ans;
            revCnt ^= 1;
            A[i] += 2;
        }
    }

    // 数据还原要么在最后还原要么对对最后一组做特殊处理
    for (int i = 0; i < len; i++) {
        if (A[i] > 1) {
            A[i] -= 2;
        }
    }
    
    return ans;
}

int main() {
    vector<int> A = {0, 0, 0, 1, 0, 1, 1, 0};
    cout << minKBitFlips(A, 3) << endl;
    printSingleVec(A);
    cout << minKBitFlips_s(A, 3) << endl;
    return 0;
}