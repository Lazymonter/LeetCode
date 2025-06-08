#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution_dfs{
public:
    TreeNode *ans;
    bool dfs(TreeNode *root,TreeNode *p,TreeNode *q){
        if(root == nullptr){
            return false;
        }
        bool lson = dfs(root->left,p,q);
        bool rson = dfs(root->right,p,q);
        if((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))){
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};

class Solution_hash{
public:
    unordered_map<int,TreeNode*> parent;
    unordered_map<int,bool> vis;
    void dfs(TreeNode *root){
        if(root->left != nullptr){
            parent[root->left->val] = root;
            dfs(root->left);
        }if(root->right != nullptr){
            parent[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root->val] = nullptr;
        dfs(root);
        while(p != nullptr){
            vis[p->val] = true;
            p = parent[p->val];
        }
        while(q != nullptr){
            if(vis[q->val]){
                return q;
            }
            q = parent[q->val];
        }
        return nullptr;
    }
};
