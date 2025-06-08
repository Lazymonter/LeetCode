/*
morris算法
*/
#include <iostream>


#include "utils/myutil.hpp"

using namespace std;

TreeNode *pre;

void inorder(TreeNode *root) {
    if (nullptr == root) {
        return;
    }
    inorder(root->left);
    pre->right = root;
    root->left = nullptr;
    pre = root;
    inorder(root->right);
}

TreeNode *increasingBST(TreeNode *root) {
    TreeNode *dummy = new TreeNode(-1);
    pre = dummy;
    inorder(root);
    return dummy->right;
}
