#include <iostream>
#include <tuple>
#include <queue>
#include <utility>

#include "utils/myutil.hpp"


int x;
TreeNode *x_parent;
int x_depth;
bool x_found = false;

int y;
TreeNode *y_parent;
int y_depth;
bool y_found = false;


void dfs(TreeNode *node, int depth, TreeNode *parent) {
    if (!node) {
        return;
    }

    if (node->val == x) {
        std::tie(x_parent, x_depth, x_found) = std::make_tuple(parent, depth, true);
    } else if (node->val == y) {
        std::tie(y_parent, y_depth, y_found) = std::make_tuple(parent, depth, true);
    }

    if (x_found && y_found) {
        return;
    }

    dfs(node->left, depth + 1, node);

    if (x_found && y_found) {
        return;
    }

    dfs(node->right, depth + 1, node);
}
bool isCousins(TreeNode *root, int x1, int y1) {
    x = x1;
    y = y1;
    dfs(root, 0, nullptr);
    return x_depth == y_depth && x_parent != y_parent;
}


void founded(TreeNode *node, TreeNode *parent, int depth) {
    if (node->val == x) {
        std::tie(x_parent, x_depth, x_found) = std::make_tuple(parent, depth, true);
    } else if (node->val == y) {
        std::tie(y_parent, y_depth, y_found) = std::make_tuple(parent, depth, true);
    }
}

bool isCousins_s(TreeNode *root, int x2, int y2) {
    x = x2;
    y = y2;
    std::queue<std::pair<TreeNode*, int>> q;
    q.emplace(root, 0);
    founded(root, nullptr, 0);

    while(!q.empty()) {
        auto &q1 = q.front();
        if (q1.first->left) {
            q.emplace(q1.first->left, q1.second + 1);
            founded(q1.first->left, q1.first, q1.second + 1);
        }
        if (q1.first->right) {
            q.emplace(q1.first->right, q1.second + 1);
            founded(q1.first->left, q1.first, q1.second + 1);
        }

        if (x_found && y_found) {
            break;
        }
        
        q.pop();
    }

    return x_depth == y_depth && x_parent != y_parent;

}