#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums,int target){
    int len = nums.size();
    if(len == 0) return -1;
    if(len == 1) return nums[0] == target ? 0 :-1;
    int left = 0;
    int right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        if(nums[0] <= nums[mid]){
            if(nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,8,1,2,3};
    cout << search(nums,3) << endl;
    cout << search(nums,10) << endl;
    return 0;
}