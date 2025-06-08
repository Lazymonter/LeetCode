#include <iostream>
#include <climits>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//递归
bool recur(TreeNode *root,long long lower,long long upper){
    if(root == NULL){
        return true;
    }
    if(root->val <= lower && root->val >= upper){
        return false;
    }
    return (recur(root->left,lower,root->val) && recur(root->right,root->val,upper));
}
bool isValidBST(TreeNode *root){
    return recur(root,LONG_MAX,LONG_MIN);
}

//中序遍历
bool isValidBST_s(TreeNode *root){
    stack<TreeNode *> s;
    long long pre = (long long)INT_MIN - 1;
    while(!s.empty() && root != NULL){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if(root->val <= pre){
            return false;
        }
        pre = root->val;
        root = root->right;
    }
    return true;
}


