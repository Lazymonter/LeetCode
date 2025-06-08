#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

TreeNode *rec(vector<int> &nums, int left, int right){
    if(left > right){
        return nullptr;
    }

    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = rec(nums, left, mid - 1);
    root->right = rec(nums, mid + 1, right);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums){
    return rec(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    treeBFS(sortedArrayToBST(nums));
    return 0;
}