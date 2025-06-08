#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return 0;
    int maxnum = nums[0],minnum = nums[0],result = nums[0];
    for(int i = 1;i < n;i++){
        int mx = maxnum,mn = minnum;
        maxnum = max(mx * nums[i],max(mn * nums[i],nums[i]));
        minnum = min(mn * nums[i],min(mx * nums[i],nums[i]));
        result = result > maxnum ? result : maxnum;
    }
    return result;
}

int main(){
    vector<int> nums = {-4,-3,-2};
    cout << maxProduct(nums) << endl;
    return 0;
}