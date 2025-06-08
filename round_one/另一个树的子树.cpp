#include <iostream>


using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

bool check(TreeNode *a,TreeNode *b){
    if(!a && !b) return true;
    if((a && !b) || (!a && b) || (a->val != b->val)) return false;
    return check(a->left,b->left) && check(a->right,b->right);
}
bool dfs(TreeNode *a,TreeNode *b){
    if(!a) return false;
    return check(a,b) || dfs(a->left,b) || dfs(a->right,b);
}
bool isSubtree(TreeNode *a,TreeNode *b){
    return dfs(a,b);
}