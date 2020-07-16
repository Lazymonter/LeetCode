#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target) {
    int len = nums.size();
    int left = 0, right = len - 1, res = 0;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if(target <= nums[mid]) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    cout << searchInsert(nums, target) << endl;
    return 0;
}