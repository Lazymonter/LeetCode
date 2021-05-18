/*
前缀和
哈希表
化简
*/


#include <iostream>
#include <vector>
#include <unordered_map>

int countTriplets(std::vector<int> &arr) {
    int len = arr.size();
    std::unordered_map<int, int> count, total;
    int ret = 0, sum = 0;
    for (int i = 0; i < len; ++i) {
        int temp = sum ^ arr[i];
        if (count.count(temp)) {
            ret += count[temp] * i - total[temp];
        }

        ++count[temp];
        total[sum] += i;
        sum = temp;
    }

    return ret;
}

int main() {
    std::vector<int> a = {2, 3, 1, 6, 7};
    std::cout << countTriplets(a) << std::endl;
    return 0;
}