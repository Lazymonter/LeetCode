#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

bool isSameTree(TreeNode *p, TreeNode *q) {
    return (p == nullptr && q == nullptr) ? true : ((p != nullptr && q != nullptr && p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main() {
    TreeNode t1(1), t2(2), t3(3), t4(1), t5(2), t6(3);
    t1.left = &t2;
    t1.right = &t3;
    t4.left = &t5;
    t4.right = &t6;
    TreeNode n1(1), n2(2), n3(2), n4(1), n5(2), n6(3);
    n1.left = &n2;
    n1.right = &n3;
    n4.left = &n6;
    n4.right = &n5;
    cout << isSameTree(&t1, &t4) << endl;
    cout << isSameTree(&n1, &n4) << endl;
    return 0;
}