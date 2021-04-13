/*
二叉搜索树中序遍历序列为升序序列
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


#include "utils/myutil.hpp"
using namespace std;

void dfs(TreeNode *root, int &minVal, int &pre) {
    if (root == nullptr) return;
    dfs(root->left, minVal, pre);
    if (pre == -1) {
        pre = root->val;
    } else {
        minVal = min(minVal, root->val - pre);
        pre = root->val;
    }
    dfs(root->right, minVal, pre);

    return;
}

int minDiffInBST(TreeNode *root) {
    if (nullptr == root) {
        return 0;
    }

    int minVal = INT_MAX, pre = -1;
    dfs(root, minVal, pre);

    return minVal;
}

int main() {
    TreeNode n1(4), n2(2), n3(6), n4(1), n5(3);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    cout << minDiffInBST(&n1) << endl;
    return 0;
}