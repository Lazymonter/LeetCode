#include <iostream>
#include <vector>

using namespace std;
//线性时间复杂度和无额外空间时使用位运算
//任何数和 0 做异或运算，结果仍然是原来的数
//任何数和其自身做异或运算，结果是 0
//异或运算满足交换律和结合律
//类比于剑指offer 数组中数字出现的次数
int singleNumber(vector<int> &nums){
    int result = 0;
    for(int i : nums){
        result ^= i;
    }
    return result;
}

int main(){
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums) << endl;
    return 0;
}