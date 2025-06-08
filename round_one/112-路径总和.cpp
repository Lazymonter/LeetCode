#include <iostream>

#include "utils/myutil.hpp"

using namespace std;

bool hasPathSum(TreeNode *root, int sum){
    if(root == nullptr){
        return false;
    }
    return (root->left == nullptr && root->right == nullptr) ? (root->val == sum) : (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    
}

int main(){
    TreeNode n1(5),n2(4),n3(8),n4(11),n5(13),n6(4),n7(7),n8(2),n9(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n6.right = &n9;
    cout << hasPathSum(&n1, 22) << endl;
    return 0;
}