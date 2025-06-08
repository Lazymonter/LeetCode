#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "utils/myutil.hpp"

using namespace std;
//广度优先遍历中分层（加标记）
vector<vector<int>> levelOrderBottom_s(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    queue<TreeNode *> q;
    vector<vector<int>> result;
    vector<int> mid;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node == nullptr) {
            if (!mid.empty()) {
                result.insert(result.begin(), mid);
                mid.clear();
                q.push(nullptr);
            }
        } else {
            mid.emplace_back(node->val);

            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
    }
    return result;
}
//while中添加每一层的内部循环（次数为当前queue长度）
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == nullptr) return {};
    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> mid;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *node = q.front();
            q.pop();
            mid.emplace_back(node->val);
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        result.emplace_back(mid);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    TreeNode a1(3), a2(9), a3(20), a4(15), a5(7);
    a1.left = &a2;
    a1.right = &a3;
    a3.left = &a4;
    a3.right = &a5;

    vector<vector<int>> result = levelOrderBottom(&a1);
    printMultiVec(result);
    return 0;

}