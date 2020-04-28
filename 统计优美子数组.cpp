#include <iostream>
#include <vector>

using namespace std;

int numberOfSubarrays(vector<int> &nums,int k){
    int n = nums.size();
    vector<int> flag(n + 2);
    int ret = 0;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(nums[i] & 1){
            flag[++cnt] = i;
        }
    }
    flag[0] = -1;
    flag[++cnt] = n;
    for(int i = 1;i + k <= cnt;++i){
        ret += (flag[i] - flag[i - 1]) * (flag[i + k] - flag[i + k - 1]);
    }
    return ret;
}

int main(){
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout << numberOfSubarrays(nums,k) << endl;
    return 0;
}