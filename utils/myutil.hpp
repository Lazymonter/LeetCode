#ifndef MYUTIL_HPP
#define MYUTIL_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
    TreeNode():val(0), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

void treeBFS(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left != nullptr) {
            q.push(temp->left);
        }
        if(temp->right != nullptr) {
            q.push(temp->right);
        }    
    }
    cout << endl;
}

template <typename T>
void printSingleVec(vector<T> &vec) {
    for(typename vector<T>::iterator it = vec.begin(); it != vec.end();it++){
        cout << (*it) << " ";
    }
    cout << endl;
}

template <typename T>
void printMultiVec(vector<T> &vec){
    for(typename vector<T>::iterator it = vec.begin();it != vec.end();it++){
        printSingleVec(*it);
    }
}

#endif /* MYUTIL_HPP */