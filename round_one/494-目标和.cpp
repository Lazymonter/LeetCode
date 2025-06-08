#include <iostream>
#include <vector>


using namespace std;


void ykd(vector<int> &nums, int loc, int len, int sum, int target, int &count) {
    if (loc >= len) {
        if (sum == target) {
            count++;
        }
        return;
    }

    ykd(nums, loc + 1, len, sum + nums[loc], target, count);
    ykd(nums, loc + 1, len, sum - nums[loc], target, count);
}

int findTargetSumWays(vector<int> &nums, int target) {
    int cnt = 0;
    ykd(nums, 0, nums.size(), 0, target, cnt);
    return cnt;
}

int findTargetSumWays_dp(vector<int> &nums, int target) {
    int sum = 0;
    for (int &i : nums) {
        sum += i;
    }

    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0) {
        return 0;
    }
    int neg = diff / 2;
    vector<int> dp(neg + 1);
    dp[0] = 1;
    for (int &num :nums) {
        for (int j = neg; j >= num; --j) {
            dp[j] += dp[j - num];
        }
    }

    return dp[neg];
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3) << endl;
    cout << findTargetSumWays_dp(nums, 3) << endl;
    return 0;
}