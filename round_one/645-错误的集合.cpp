#include <iostream>
#include <vector>
#include <unordered_map>


#include "utils/myutil.hpp"

using namespace std;


vector<int> findErrorNums(vector<int> &nums) {
    vector<int> result(2);
    unordered_map<int,int> m;
    int len = nums.size();
    for (auto &num : nums) {
        m[num]++;
    }
    for (int i = 1; i <= len; i++) {
        int count = m[i];
        if (count == 2) {
            result[0] = i;
        } else if (count == 0) {
            result[1] = i;
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, 4};
    auto res = findErrorNums(nums);
    printSingleVec(res);
    return 0;
}