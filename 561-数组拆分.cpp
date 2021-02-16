#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    vector<int> v1 = {1, 4, 2, 3};
    vector<int> v2 = {6, 2, 6, 5, 1, 2};
    cout << arrayPairSum(v1) << endl;
    cout << arrayPairSum(v2) << endl;
    return 0;
}