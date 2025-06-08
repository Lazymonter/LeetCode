/*
排序
前缀相同应判断拼接后的大小
拼接具有传递性
*/
#include <iostream>
#include <vector>
#include <algorithm>


#include "utils/myutil.hpp"
using namespace std;

string largestNumber(vector<int> &nums) {
    string result = "";
    sort(nums.begin(), nums.end(), [](int &a, int &b) {
        long x = 10, y = 10;
        while (x <= a) {
            x *= 10;
        }

        while (y <= b) {
            y *= 10;
        }

        return y * a + b > x * b + a;
    });

    if (nums[0] == 0) {
        return "0";
    }

    for (auto &i : nums) {
        result += to_string(i);
    }

    return result;
}

int main() {
    vector<int> nums = {34323, 3432};
    cout << largestNumber(nums) << endl;
    return 0;
}