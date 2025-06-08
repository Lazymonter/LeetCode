/*
hash表
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findShortestSubArray(vector<int> &nums) {
    unordered_map<int,vector<int>> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.count(nums[i])) {
            m[nums[i]][0]++;
            m[nums[i]][2] = i;
        } else {
            m[nums[i]] = {1, i, i};
        }
    }

    int maxNum = 0, minLen = 0;
    for (auto &kv : m) {
        if (maxNum < kv.second[0]) {
            maxNum = kv.second[0];
            minLen = kv.second[2] - kv.second[1] + 1;
        } else if (maxNum == kv.second[0]) {
            if (minLen > kv.second[2] - kv.second[1] + 1) {
                minLen = kv.second[2] - kv.second[1] + 1;
            }
        }
    }
    return minLen;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 1};

    cout << findShortestSubArray(nums) << endl;
    return 0;
}