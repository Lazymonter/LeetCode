#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max = nums[0];
    for (int i = 1; i < nums.size();i++){
        if (nums[i - 1] > 0){
            nums[i] = nums[i] + nums[i - 1];
        }
        max = max > nums[i] ? max : nums[i];
    }
    return max;    
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -7, 4};
    cout << maxSubArray(nums) << endl;
}