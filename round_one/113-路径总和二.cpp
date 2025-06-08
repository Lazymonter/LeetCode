#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

vector<vector<int>> result;
vector<int> path;

//dfs
void dfs(TreeNode *root, int sum) {
    if (root == nullptr) {
        return;
    }

    path.emplace_back(root->val);
    sum -= root->val;

    if (root->left == nullptr && root->right == nullptr && sum == 0) {
        result.emplace_back(path);
    }

    dfs(root->left, sum);
    dfs(root->right, sum);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    dfs(root, sum);
    return result;
}