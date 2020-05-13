#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums){
    int curMax = 0;
    int preMax = 0;
    for(int i : nums){
        int temp = curMax;
        curMax = (preMax + i) > curMax ? preMax + i : curMax;
        preMax = temp;
    }
    return curMax; 
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    vector<int> nums1 = {1, 2, 3, 1};
    cout << rob(nums) << endl;
    cout << rob(nums1) << endl;
    return 0;
}