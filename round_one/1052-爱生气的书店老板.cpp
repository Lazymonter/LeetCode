/*
滑动窗口
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最大满意顾客 = 原来满意顾客+（max）增加满意顾客
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    int len = customers.size();
    int left = 0, right = 0;
    int ret = 0, upgrade = 0, temp = 0;
    while (right < len) {
        // 原来满意顾客
        ret += customers[right] * (1 - grumpy[right]);
        // 此处维护滑动窗口
        temp += customers[right] * grumpy[right++];
        // 当前最大增加满意顾客
        upgrade = max(upgrade, temp);
        // 最左边的值出窗口
        if (right - left == X) {
            temp -= grumpy[left] * customers[left++];
        }
    }

    return ret + upgrade;
}

int main() {
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int X = 3;
    cout << maxSatisfied(customers, grumpy, X) << endl;
}