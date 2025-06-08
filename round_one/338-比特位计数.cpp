/*
位运算
动态规划
*/

#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

// 最低设置位
vector<int> countBits(int num) {
    vector<int> ret(num + 1);
    for (int i = 1; i <= num; ++i) {
        ret[i] = ret[i & (i - 1)] + 1;
    }
    return ret;
}

// 最高有效位
vector<int> countBits_s(int num) {
    vector<int> ret(num + 1);
    int highBit = 0;
    for (int i = 1; i <= num; ++i) {
        if (i & (i - 1) == 0) {
            highBit = i;
        }
        ret[i] = ret[i - highBit] + 1;
    }
    return ret;
}
// 最低有效位
vector<int> countBits_ss(int num) {
    vector<int> ret(num + 1);
    for (int i = 1; i <= num; ++i) {
        ret[i] = ret[i >> 1] + (i & 1);
    }
    return ret;
}

int main() {
    int nums = 5;
    vector<int> ret = countBits(nums);
    printSingleVec(ret);
    return 0;
}