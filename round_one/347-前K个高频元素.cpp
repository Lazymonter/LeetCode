#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "utils/myutil.hpp"

using namespace std;
//堆排序
typedef pair<int, int> PAIR;

bool cmpByValue(const PAIR &a, const PAIR &b) { return a.second > b.second; }

vector<int> topKFrequent(vector<int> &nums, int k) {
    int len = nums.size();
    if (len == 0) {
        return {};
    }
    unordered_map<int, int> m;
    vector<int> result;
    for(auto && i : nums) {
        if (m.count(i)) {
            m[i]++;
        } else {
            m[i] = 1;
        }
    }
    vector<PAIR> n(m.begin(), m.end());
    sort(n.begin(), n.end(), cmpByValue);
    int count = 0;
    for (auto && i : n) {
        if (count >= k) {
            break;
        }
        result.emplace_back(i.first);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3};
    vector<int> result = topKFrequent(nums, 2);
    printSingleVec(result);
    return 0;
}


