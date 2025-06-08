#include <iostream>

#include "utils/myutil.hpp"

using namespace std;

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 != nullptr && t2 != nullptr) {
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    } else {
        return t1 == nullptr ? t2 : t1;
    }
}

TreeNode *mergeTrees_new(TreeNode *t1, TreeNode *t2) {
    if (t1 != nullptr && t2 != nullptr) {
        TreeNode *root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    } else {
        return t1 == nullptr ? t2 : t1;
    }
}


int main() {
    TreeNode n1(1), n2(3), n3(2), n4(5);
    TreeNode m1(2), m2(1), m3(3), m4(4), m5(7);
    n1.left = &n2;
    n2.left = &n4;
    n1.right = &n3;
    m1.left = &m2;
    m1.right = &m3;
    m2.right = &m4;
    m3.right = &m5;
    TreeNode *result = mergeTrees(&n1, &m1);
    treeBFS(result);
    return 0;
}