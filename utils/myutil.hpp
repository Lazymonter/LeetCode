#ifndef MYUTIL_HPP
#define MYUTIL_HPP

#include <iostream>
#include <stack>
#include <vector>


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