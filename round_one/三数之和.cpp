#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//排序（去重）+双指针（求解）
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> results;
    sort(nums.begin(), nums.end());
    if(nums.size() < 3){
        return results;
    }
    for (int i = 0; i < nums.size() - 2; i++){
        if(nums[i] > 0){
            break;
        }
        if(i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        int sum = 0;
        while(left < right){
            sum = nums[left] + nums[right] + nums[i];
            if (sum > 0){
                --right;
            }
            else if(sum < 0){
                ++left;
            }
            else{
                results.push_back({nums[i], nums[left], nums[right]});
                ++left;
                --right;
                while(left < right && nums[left] == nums[left - 1]){
                    ++left;
                }
                while(left < right && nums[right] == nums[right + 1]){
                    --right;
                }
            }
        }
    }
    return results;
}

int main(){
    vector<int> nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> results;
    results = threeSum(nums);
    for(vector<vector<int>>::iterator iter = results.begin(); iter != results.end();iter++){
        for(vector<int>::iterator iter2 = iter->begin(); iter2 != iter->end();iter2++){
            cout << *iter2 << " ";
        }
        cout << endl;
    }
    return 0;
}