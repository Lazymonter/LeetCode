/*
二分查找
*/

#include <iostream>
#include <vector>


using namespace std;

bool search(vector<int> &nums, int target) {
    int len = nums.size();
    if (0 == len) return false;

    if (1 == len) {
        return nums[0] == target;
    }

    int left = 0, right = len - 1;

    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] == target) {
            return true;
        }

        if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
            ++left;
            --right;
        } else if (nums[left] <= nums[mid]){
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[len - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    cout << search(nums, 0) << endl;
    cout << search(nums, 3) << endl;
    return 0;
}