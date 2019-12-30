#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
//双指针法，与三数之和思想一致
int threeSumClosest(vector<int>& nums, int target) {
    int result = 0;
    int min_dis = INT_MAX;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2;i++){
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            int dis_t = sum - target;
            if(min_dis > abs(dis_t)){
                min_dis = abs(dis_t);
                result = sum;
            }
            if(dis_t < 0){
                left++;
                while(left < right && nums[left] == nums[left - 1]){
                    left++;
                }
            }
            else if(dis_t > 0){
                right--;
                while(left < right && nums[right] == nums[right + 1]){
                    right--;
                }
                
            }
            else{
                return result;
            }
            
        }
    }
    return result;
}

int main(){
    vector<int> nums = {-1,-1,1,1,4};
    int target = 1;
    cout << threeSumClosest(nums,target) << endl;;
    return 0;
}