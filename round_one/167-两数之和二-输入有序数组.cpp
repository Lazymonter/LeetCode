#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;
//双指针
vector<int> twoSum(vector<int> &numbers, int target) {
    int len = numbers.size();
    vector<int> result(2, -1);
    int left = 0, right = len - 1;
    while(left < right) {
        if(numbers[left] + numbers[right] == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else if(numbers[left] + numbers[right] < target) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}
//二分查找
vector<int> twoSum_Binary(vector<int> &numbers, int target) {
    for(int i = 0; i < numbers.size(); i++) {
        int left = i + 1, right = numbers.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(numbers[i] + numbers[mid] == target) {
                return {i + 1, mid + 1};
            } else if (numbers[i] + numbers[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return {-1, -1};
}
//先二分在双指针
vector<int> twoSum_s(vector<int> &numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if(numbers[mid] + numbers[0] > target) {
            right = mid - 1;
        } else if(numbers[mid] + numbers[0] < target) {
            left = mid + 1;
        } else {
            right = mid;
            break;
        }
    }
    left = 0;
    while(left < right) {
        if(numbers[left] + numbers[right] == target) {
           return {left + 1, right + 1};
        } else if(numbers[left] + numbers[right] < target) {
            left++;
        } else {
            right--;
        }
    }
    return {-1, -1};
}

int main(){
    vector<int> numbers = {0, 0, 5, 6, 7};
    int target = 7;
    vector<int> result = twoSum(numbers, target);
    vector<int> result2 = twoSum_Binary(numbers, target);
    vector<int> result3 = twoSum_s(numbers, target);
    printSingleVec(result);
    printSingleVec(result2);
    printSingleVec(result3);
    return 0;

}