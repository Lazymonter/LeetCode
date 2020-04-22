#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//bfs
vector<int> rightSideView(TreeNode *root){
    unordered_map<int,int> rightmostvalue;
    int max_depth = -1;
    queue<TreeNode *> nodes;
    queue<int> depth;
    nodes.push(root);
    depth.push(0);
    while(!nodes.empty()){
        TreeNode *node = nodes.front();
        nodes.pop();
        int dep = depth.front();
        depth.pop();
        if(node != NULL){
            max_depth = max(max_depth,dep);
            rightmostvalue[dep] = node->val;
            nodes.push(node->left);
            nodes.push(node->right);
            depth.push(dep + 1);
            depth.push(dep + 1);
        }
    }
    vector<int> result;
    for(int dep = 0;dep <= max_depth;dep++){
        result.push_back(rightmostvalue[dep]);
    }
    return result;
}

vector<int> rightSide_dfs(TreeNode *root){
    unordered_map<int,int> rightmostvalue;
    int max_depth = -1;
    stack<TreeNode *> nodes;
    stack<int> depths;
    nodes.push(root);
    depths.push(0);
    while(!nodes.empty()){
        TreeNode *node = nodes.top();
        nodes.pop();
        int depth = depths.top();
        depths.pop();
        if(node != NULL){
            max_depth = max_depth > depth ? max_depth : depth;
            if(rightmostvalue.count(depth) == 0){
                rightmostvalue[depth] = node->val;
            }
            nodes.push(node->left);
            nodes.push(node->right);
            depths.push(depth + 1);
            depths.push(depth + 1);
        }
    }
    vector<int> result;
    for(int dep = 0;dep <= max_depth;dep++){
        result.push_back(rightmostvalue[dep]);
    }
    return result;
}

int main(){
    TreeNode root(1);
    TreeNode left1(2);
    TreeNode right1(3);
    TreeNode left2(4);
    TreeNode right2(5);
    TreeNode left3(6);
    root.left = &left1;
    root.right = &right1;
    left1.right = &right2;
    left1.left = &left2;
    left2.left = &left3;
    vector<int> result;
    result = rightSide_dfs(&root);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}