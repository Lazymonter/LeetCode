#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "utils/myutil.hpp"
using namespace std;

vector<int> interset(vector<int> &nums1, vector<int> &nums2) {
    if(nums1.size() > nums2.size()){
        return interset(nums2, nums1);
    }
    vector<int> result;
    unordered_map<int,int> m;
    for(auto &&num : nums1){
        if(m.count(num)) {
            m[num]++;
        } else {
            m[num] = 1;
        }
    }
    for(auto &&num : nums2){
        if(m.count(num)) {
            result.push_back(num);
            m[num]--;
            if(m[num] == 0){
                m.erase(num);
            }
        }
    }
    return result;
}

vector<int> interset_rank(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();
    vector<int> result;
    while(iter1 != nums1.end() && iter2 != nums2.end()) {
        if(*iter1 < *iter2){
            iter1++;
        } else if(*iter1 > *iter2){
            iter2++;
        } else {
            result.push_back(*iter1);
            iter1++;
            iter2++;
        }
    }
    return result;
}

int main(){
    vector<int> nums1 = {9, 4, 9, 8, 4}, nums2 = {4, 9, 5};
    vector<int> result = interset_rank(nums1, nums2);
    printSingleVec(result);
    return 0;
}