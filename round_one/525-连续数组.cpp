#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


int findMaxLength(vector<int> &nums) {
    int counter = 0;
    int len = nums.size();
    unordered_map<int, int> m;
    m[counter] = -1;
    int ret = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] == 0) {
            --counter;
        } else {
            ++counter;
        }

        if (m.count(counter)) {
            int pre = m[counter];
            ret = max(ret, i - pre);
        } else {
            m[counter] = i;
        }
    }
    return ret;
}

int main() {
    vector<int> nums = {0, 1, 0};
    cout << findMaxLength(nums) << endl;
    return 0;
}