#include <iostream>
#include <vector>

using namespace std;

int totalHammingDistance(vector<int> &nums) {
    int len = nums.size();
    int ret = 0;
    for (int i = 0; i < 30; ++i) {
        int cnt = 0;
        for (auto &num : nums) {
            cnt += (num >> i) & 1;
        }

        ret += cnt * (len - cnt);
    }
    
    return ret;
}

int main() {
    vector<int> nums = {4, 14, 2};
    cout << totalHammingDistance(nums) << endl;
    return 0;
}