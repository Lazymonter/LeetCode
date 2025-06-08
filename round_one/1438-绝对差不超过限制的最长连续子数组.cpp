/*
滑动窗口
data struct:multiset,dequeue
*/

#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

// 滑动窗口(multiset)
int longestSubarray(vector<int> &nums, int limit) {
    multiset<int> s;
    int left = 0, right = 0;
    int ret = 0;
    int len = nums.size();
    while (right < len) {
        s.insert(nums[right]);
        while(*s.rbegin() - *s.begin() > limit) {
            s.erase(nums[left++]);
        }
        ret = max(ret, right - left + 1);
        right++;
    }

    return ret;
}

// 滑动窗口(dequeue)
int longestSubarray_s(vector<int> &nums, int limit) {
    deque<int> maxQue, minQue;
    int len = nums.size();
    int left = 0, right = 0;
    int ret = 0;

    while (right < len) {
        while (!maxQue.empty() && maxQue.back() < nums[right]) {
            maxQue.pop_back();
        }

        while (!minQue.empty() && minQue.back() > nums[right]) {
            minQue.pop_back();
        }

        maxQue.push_back(nums[right]);
        minQue.push_back(nums[right]);
        while (!maxQue.empty() && !minQue.empty() && maxQue.front() - minQue.front() > limit) {
            if (nums[left] == minQue.front()) {
                minQue.pop_front();
            }

            if (nums[left] == maxQue.front()) {
                maxQue.pop_front();
            }

            left++;
        } 
        ret = max(ret, right - left + 1);
        right++;
    }

    return ret;
}

int main() {
    vector<int> nums = {10,1,2,4,7,2};
    cout << longestSubarray_s(nums, 5) << endl;
    cout << longestSubarray(nums, 5) << endl;
    return 0;
}


