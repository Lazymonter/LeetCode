#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums) {
    int length = nums.size();
    int maxValue = 0;
    int ret = 0;
    for (int i = 0; i < length; ++i) {
        if (1 == nums[i]) {
            maxValue++;
        } else {
            ret = maxValue > ret ? maxValue : ret;
            maxValue = 0;
        }
    }

    return maxValue > ret ? maxValue : ret;
}

int main() {
    vector<int> v = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(v) << endl;
    return 0;
}