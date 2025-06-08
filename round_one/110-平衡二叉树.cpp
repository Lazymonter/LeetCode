#include <iostream>
#include <algorithm>
#include "utils/myutil.hpp"

using namespace std;

int height(TreeNode *root) {
    if(root == nullptr) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode *root) {
    if(root == nullptr) {
        return true;
    }
    return (abs(height(root->left) - abs(height(root->right))) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}


int main() {
    TreeNode r1(3), r2(9), r3(20), r4(15), r5(7);
    r1.left = &r2;
    r1.right = &r3;
    r3.left = &r4;
    r3.right = &r5;
    cout << isBalanced(&r1) << endl;
    return 0;

}
