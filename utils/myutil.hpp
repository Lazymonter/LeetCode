#ifndef MYUTIL_HPP
#define MYUTIL_HPP

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

void treeBFS(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode *temp = s.top();
        s.pop();
        cout << temp->val << " ";
        if(temp->left != nullptr) {
            s.push(temp->left);
        }
        if(temp->right != nullptr) {
            s.push(temp->right);
        }
    }
    cout << endl;
}

#endif /* MYUTIL_HPP */