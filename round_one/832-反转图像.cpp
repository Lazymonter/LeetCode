/*
数组
双指针
*/

#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

// 遍历（隐双指针）
vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    int len = A[0].size();
    int flag = len % 2;
    for (auto &a : A) {
        for (int i = 0; i < len / 2; ++i) {
            int temp = 1 - a[i];
            int rev = len - 1 - i;
            a[i] = 1 - a[rev];
            a[rev] = temp;
        }
        if (flag) {
            a[len / 2] = 1 - a[len / 2];
        }
    }
    return A;
}
// left和right相同的情况下水平翻转+反转之后值反转
// left和right不同的情况下水平翻转+反转之后值不变
// 双指针
vector<vector<int>> flipAndInvertImage_s(vector<vector<int>> &A) {
    int len = A[0].size();
    for (auto &a: A) {
        int left = 0, right = len - 1;
        while (left < right) {
            if (a[left] == a[right]) {
                a[left] ^= 1;
                a[right] ^= 1;
            }
            left++;
            right--;
        }

        if (left == right) {
            a[left] ^= 1;
        }
    }

    return A;
}


int main() {
    vector<vector<int>> A = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
    vector<vector<int>> A1 = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
    vector<vector<int>> result = flipAndInvertImage(A);
    vector<vector<int>> result2 = flipAndInvertImage_s(A1);
    printMultiVec(result);
    printMultiVec(result2);
    return 0;
}
