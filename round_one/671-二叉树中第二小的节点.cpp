#include <iostream>
#include <algorithm>

#include "utils/myutil.hpp";

using namespace std;


int findSecondMinimumValue(TreeNode *root) {
    if (root && root->left && root->right) {
        int leftMin = root->left->val == root->val ? findSecondMinimumValue(root->left) : root->left->val;
        int rightMin = root->right->val == root->val ? findSecondMinimumValue(root->right) : root->right->val;
        return min(unsigned(leftMin), unsigned(rightMin));
    }

    return -1;
}