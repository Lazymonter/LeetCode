#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums){
    int max = 0;
    for(int i = 0;i < nums.size();i++){
        if(i == max && nums[i] == 0){
            return false;
        }
        if(max == nums.size() - 1){
            return true;
        }
        if(i + nums[i] > max){
            max = i + nums[i];
        }
    }
}


int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) << endl;
    return 0;
}