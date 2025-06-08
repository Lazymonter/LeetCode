
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

bool make(vector<int> &bloomDay, int day, int m, int k) {
    int flowers = 0, bou = 0;
    int len = bloomDay.size();
    for (int i = 0; i < len; ++i) {
        if (bloomDay[i] <= day) {
            flowers++;
            if (k == flowers) {
                bou++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
    }

    return m <= bou;
}

int minDays(vector<int> &bloomDay, int m, int k) {
    if (m * k > bloomDay.size()) {
        return -1;
    }

    int left = INT_MAX, right = 0;
    int len = bloomDay.size();
    for (int i = 0; i < len; ++i) {
        left = min(left, bloomDay[i]);
        right = max(right, bloomDay[i]);
    }

    while (left < right) {
        int day = (left + right) >> 1;
        if (make(bloomDay, day, m, k)) {
            right = day;
        } else {
            left = day + 1;
        }
    }

    return left;
}

int main() {
    vector<int> bloomDay = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    cout << minDays(bloomDay, 4, 2) << endl;
    return 0;
}