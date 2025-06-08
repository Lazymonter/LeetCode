#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;


void dfs(TreeNode *root, vector<int> &tree) {
    if (root->left == nullptr && root->right == nullptr) {
        tree.push_back(root->val);
    } else {
        if (root->left) {
            dfs(root->left, tree);
        }
        
        if (root->right) {
            dfs(root->right, tree);
        }    
    }
}

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> tree1;
    if (root1) {
        dfs(root1, tree1);
    }

    vector<int> tree2;
    if (root2) {
        dfs(root2, tree2);
    }

    return tree1 == tree2;
}