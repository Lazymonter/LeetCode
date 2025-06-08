#include <iostream>
#include <vector>
#include <unordered_map>

#include "utils/myutil.hpp"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        auto k = target - nums[i];
        if (m.count(k) != 0) {
            return {i, m[k]};
        }
        m[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> v = {3, 2, 4};
    int target = 6;
    auto res = twoSum(v, target);
    printSingleVec(res);
    return 0;
}