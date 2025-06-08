#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//双队列
vector<vector<int>> levelOrder_s(TreeNode *root){
    if(root == NULL){
        return {{}};
    }
    queue<TreeNode *> q1;
    queue<int> levels;
    q1.push(root);
    levels.push(0);
    int cur_level = 0;
    vector<vector<int>> result;
    vector<int> temp;
    while(!q1.empty()){
        TreeNode *node = q1.front();
        q1.pop();
        int level = levels.front();
        levels.pop();
        if(cur_level == level){
            temp.push_back(node->val);
        }else{
            result.push_back(temp);
            temp.clear();
            temp.push_back(node->val);
            cur_level = level;
        }
        if(node->left != nullptr){
            q1.push(node->left);
            levels.push(level + 1);
        }
        if(node->right != nullptr){
            q1.push(node->right);
            levels.push(level + 1);
        }
    }
    result.push_back(temp);
    return result;
}

//记录层次长度
vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> result;
    if(root == nullptr) return result;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int cur_size = q.size();
        for(int i = 0; i < cur_size;i++){
            auto node = q.front();
            q.pop();
            result.back().push_back(node->val);
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
    }
    return result;
}