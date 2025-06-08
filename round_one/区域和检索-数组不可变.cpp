#include <iostream>
#include <vector>

using namespace std;


class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = &nums;
        int curSum = 0;
        for(int i = 0;i < nums.size();i++){
            curSum += nums[i];
            this->sum.push_back(curSum);
        }
    }
    
    int sumRange(int i, int j) {
        return (sum[j] - sum[i] + (*nums)[i]);
    }
private:
    vector<int> sum;
    vector<int> * nums;
};   

class NumArray2 {
public:
    vector<int> sum;

    NumArray2(vector<int> &nums) {
        int len = nums.size();
        sum.resize(len + 1);
        for (int i = 0; i < len; ++i) {
            sum[i + 1] = nums[i] + sum[i];
        }
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *pol = new NumArray(nums);
    cout << pol->sumRange(0, 2) << endl;
    cout << pol->sumRange(2, 5) << endl;
    cout << pol->sumRange(0, 5) << endl;
    return 0;
}